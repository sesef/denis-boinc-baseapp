/***********************************************************************\
 *  DENIS@HOME Boinc Application
 *   
 *  This application is based on Hello World app from Boinc source code
 *
 *  With this simulator you can run different electrophysiological models
 *  modifying the configuration file
 *
 *  If you run it in standalone mode, the file with parameters must be 
 *  called 'in' ( without quotes and without extension)
 *  
 *  For more information see the release notes at 
 *	  http://denis.usj.es
 *
 *  Jesus Carro <jcarro@usj.es> 
 *  Joel Castro <jcastro@usj.es>
 *  version: Natrium - 16 March 2016
 \************************************************************************/
#include <cstddef>		// now required for NULL, etc.

#ifdef _WIN32                //  Stuff we only need on Windows: 
#include "boinc_win.h"
#include "util.h"            // parse_command_line(), boinc_sleep()
#endif

/* BOINC API */

#include "boinc_api.h"
#include "diagnostics.h"     // boinc_init_diagnostics()
#include "filesys.h"         // boinc_fopen(), etc...
#include "str_util.h"		 // for parse_command_line()

// version.h is only used to get BOINC version numbers  
#include "version.h" 

/* DENIS INCLUDES */
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <math.h>
#include "models.h"
#include "config.h"
#include "markerlist.h"
#include "tinyxml2.h"

/* INPUT OUTPUT INCLUDES */
#define CHECKPOINT_FILE "denis_state"
#define INPUT_FILENAME "in"
#define OUTPUT_FILENAME "out"
#define MARKERS_FILENAME "markers"

using std::string;
using std::fstream;

using namespace std;

APP_INIT_DATA appData;

std::vector<std::string> &string_split(const std::string &s, char delim,
		std::vector<std::string> &elems) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}

std::vector<std::string> string_split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	string_split(s, delim, elems);
	return elems;
}

int do_checkpoint(int rat_length, int alg_length, long it, const int buffSize,
		double* STATES, double* ALGEBRAIC) {
	string resolved_name;
	char chkpt_path[buffSize];

	int rc = boinc_resolve_filename(CHECKPOINT_FILE, chkpt_path, buffSize);
	if (rc) {
		fprintf(stderr, "APP: cannot resolve checkpoint file name. RC=%d\n",
				rc);
		boinc_finish(rc);
	}

	FILE* state = boinc_fopen(chkpt_path, "w");
	if (!state) {
		it = 0;
		return 0;
	}

	fstream checkpointFile(chkpt_path, ios::out | ios::binary | ios::trunc);

	checkpointFile.write(reinterpret_cast<const char *>(&it), sizeof(long));
	fprintf(stderr, "\nDoing CP It:%i", it);

	for (int stateIterator = 0; stateIterator < rat_length; stateIterator++) {
		checkpointFile.write(reinterpret_cast<char *>(&STATES[stateIterator]),
				sizeof(double));
		fprintf(stderr, "\nSTATE[%i]:%f", stateIterator, STATES[stateIterator]);
	}

	for (int algIterator = 0; algIterator < alg_length; algIterator++) {
		checkpointFile.write(reinterpret_cast<char *>(&ALGEBRAIC[algIterator]),
				sizeof(double));
		fprintf(stderr, "\nALG[%i]:%f", algIterator, ALGEBRAIC[algIterator]);
	}

	checkpointFile.close();
	return 0;
}

long loadDataFromCheckPoint( int rat_length, int alg_length,
		const int buffSize, double* STATES, double* ALGEBRAIC) {
	char chkpt_path[buffSize];
	std::string line;

	long it = 0;

	int rc = boinc_resolve_filename(CHECKPOINT_FILE, chkpt_path, buffSize);
	if (rc) {
		fprintf(stderr, "APP: cannot resolve checkpoint file name. RC=%d\n",
				rc);
		boinc_finish(rc);
	}

	FILE* state = boinc_fopen(chkpt_path, "r");
	if (!state || appData.wu_cpu_time == 0) {
		return it;
	} else {
		fclose(state);
	}

	fstream checkpointFile(chkpt_path, ios::in | ios::binary);

	try {
		checkpointFile.read(reinterpret_cast<char *>(&it), sizeof(long));
		fprintf(stderr, "LoadFromCP: it = %i", it);
		for (int stateIterator = 0; stateIterator < rat_length;
				stateIterator++) {
			checkpointFile.read(
					reinterpret_cast<char *>(&STATES[stateIterator]),
					sizeof(double));
			fprintf(stderr, "\nSTATE[%i]:%f", stateIterator,
					STATES[stateIterator]);
		}


		for (int algIterator = 0; algIterator < alg_length; algIterator++) {
			checkpointFile.read(
					reinterpret_cast<char *>(&ALGEBRAIC[algIterator]),
					sizeof(double));
			fprintf(stderr, "\nALG[%i]:%f", algIterator,
					ALGEBRAIC[algIterator]);
		}
	} catch (std::exception & ex) {
		fprintf(stderr, "EXCEPTION%s\n", ex.what());
		it = 0;
	}

	checkpointFile.close();
	return it;
}

void initBoinc() {
	boinc_init_diagnostics(
			BOINC_DIAG_REDIRECTSTDERR | BOINC_DIAG_MEMORYLEAKCHECKENABLED
					| BOINC_DIAG_DUMPCALLSTACKENABLED
					| BOINC_DIAG_TRACETOSTDERR);

	int rc = boinc_init();
	if (rc) {
		fprintf(stderr, "APP: boinc_init() failed. rc=%d\n", rc);
		fflush(0);
		exit(rc);
	}

	rc = boinc_get_init_data(appData);
	if (rc) {
		fprintf(stderr, "APP: boinc_init_data() failed. rc=%d\n", rc);
		fflush(0);
		exit(rc);
	}

}

void getFilePaths(char input_path[], char output_path[], char markers_path[],
		const int buffSize) {
	int rc = boinc_resolve_filename(INPUT_FILENAME, input_path, buffSize);
	if (rc) {
		fprintf(stderr, "APP: cannot resolve input file name. RC=%d\n", rc);
		boinc_finish(rc);
	}

	rc = boinc_resolve_filename(OUTPUT_FILENAME, output_path, buffSize);

	if (rc) {
		fprintf(stderr, "APP: cannot resolve output file name. RC=%d\n", rc);
		boinc_finish(rc);
	}

	rc = boinc_resolve_filename(MARKERS_FILENAME, markers_path, buffSize);

	if (rc) {
		fprintf(stderr, "APP: cannot resolve markers file name. RC=%d\n", rc);
		boinc_finish(rc);
	}

}
int loadModelID(char input_path[]) {
	int modelID = 0;
	tinyxml2::XMLDocument doc;
	doc.LoadFile(input_path);
	const char* modelName =
			doc.FirstChildElement("simulation")->FirstChildElement("model")->FirstChildElement(
					"name")->GetText();
	modelID = getModelId(modelName);
	fprintf(stderr, "MName:%s\n", modelName);
	fprintf(stderr, "MID:%i\n", modelID);

	return modelID;
}

CONFIG loadConfiguration(char input_path[], const char** constants,
		const char** states, const char** algebraic, int cons_len, int rat_len,
		int alg_len, int modelID) {
	double initial_time;
	double final_time;
	double dt;
	int outputFreq;

	int vIndex;
	int * algToPrint;
	int * statesToPrint;

	tinyxml2::XMLDocument doc;
	doc.LoadFile(input_path);

	final_time =
			atof(
					doc.FirstChildElement("simulation")->FirstChildElement(
							"model")->FirstChildElement("endtime")->GetText());
	fprintf(stderr, "OpT:%f\n", final_time);
	dt =
			atof(
					doc.FirstChildElement("simulation")->FirstChildElement(
							"model")->FirstChildElement("diferentialtime")->GetText());
	fprintf(stderr, "DT:%f\n", dt);
	outputFreq =
			atoi(
					doc.FirstChildElement("simulation")->FirstChildElement(
							"output")->FirstChildElement("frequency")->GetText());
	fprintf(stderr, "OutFreq:%i\n", outputFreq);
	initial_time =
			atof(
					doc.FirstChildElement("simulation")->FirstChildElement(
							"output")->FirstChildElement("starttime")->GetText());
	fprintf(stderr, "InT:%f\n", initial_time);

	vIndex =
			getNameId(modelID,
					doc.FirstChildElement("simulation")->FirstChildElement(
							"model")->FirstChildElement("markerv")->FirstChildElement(
							"name")->GetText(),
					doc.FirstChildElement("simulation")->FirstChildElement(
							"model")->FirstChildElement("markerv")->FirstChildElement(
							"component")->GetText(), states, rat_len);

	long initPost = (long) (round(initial_time / dt));
	long lastIteration = (long) (round(final_time / dt));

	int numConstantsToChange = 0;
	if (doc.FirstChildElement("simulation")->FirstChildElement(
			"constants_to_change")) {
		for (tinyxml2::XMLNode* ele =
				doc.FirstChildElement("simulation")->FirstChildElement(
						"constants_to_change")->FirstChild(); ele;
				ele = ele->NextSibling()) {
			++numConstantsToChange;
		}
	}

	fprintf(stderr, "NumConstToChange:%i\n", numConstantsToChange);

	int numStatesToPrint = 0;
	if (doc.FirstChildElement("simulation")->FirstChildElement("output")->FirstChildElement(
			"states")) {
		for (tinyxml2::XMLNode* ele =
				doc.FirstChildElement("simulation")->FirstChildElement("output")->FirstChildElement(
						"states")->FirstChild(); ele; ele =
				ele->NextSibling()) {
			++numStatesToPrint;
		}
	}

	fprintf(stderr, "NumStatesToPrint:%i\n", numStatesToPrint);

	int numAlgToPrint = 0;
	if (doc.FirstChildElement("simulation")->FirstChildElement("output")->FirstChildElement(
			"algebraics")) {
		for (tinyxml2::XMLNode* ele =
				doc.FirstChildElement("simulation")->FirstChildElement("output")->FirstChildElement(
						"algebraics")->FirstChild(); ele; ele =
				ele->NextSibling()) {
			++numAlgToPrint;
		}
	}

	fprintf(stderr, "NumAlgToPrint:%i\n", numAlgToPrint);
	changed_double * changedConstants = new changed_double[numConstantsToChange];

	int iterator = 0;
	if (numConstantsToChange > 0) {
		for (tinyxml2::XMLNode* ele =
				doc.FirstChildElement("simulation")->FirstChildElement(
						"constants_to_change")->FirstChild(); ele;
				ele = ele->NextSibling()) {
			changedConstants[iterator].key = getNameId(modelID,
					ele->FirstChildElement("name")->GetText(),
					ele->FirstChildElement("component")->GetText(), constants,
					cons_len);
			changedConstants[iterator].value = atof(
					ele->FirstChildElement("value")->GetText());
			fprintf(stderr, "CC ID:%i NAME: %s in component %s VALUE:%s\n",
					changedConstants[iterator].key,
					ele->FirstChildElement("name")->GetText(),
					ele->FirstChildElement("component")->GetText(),
					ele->FirstChildElement("value")->GetText());
				iterator++;
		}
	}

	iterator = 0;
	if (numStatesToPrint > 0) {
		statesToPrint = new int[numStatesToPrint];
		for (tinyxml2::XMLNode* ele =
				doc.FirstChildElement("simulation")->FirstChildElement("output")->FirstChildElement(
						"states")->FirstChild(); ele; ele =
				ele->NextSibling()) {
			statesToPrint[iterator] = getNameId(modelID,
					ele->FirstChildElement("name")->GetText(),
					ele->FirstChildElement("component")->GetText(), states,
					rat_len);
			fprintf(stderr, "STP ID:%i - %s in component %s\n",
					statesToPrint[iterator],
					ele->FirstChildElement("name")->GetText(),
					ele->FirstChildElement("component")->GetText());
			iterator++;
		}
	}

	iterator = 0;
	if (numAlgToPrint > 0) {
		algToPrint = new int[numAlgToPrint];
		for (tinyxml2::XMLNode* ele =
				doc.FirstChildElement("simulation")->FirstChildElement("output")->FirstChildElement(
						"algebraics")->FirstChild(); ele; ele =
				ele->NextSibling()) {
			algToPrint[iterator] = getNameId(modelID,
					ele->FirstChildElement("name")->GetText(),
					ele->FirstChildElement("component")->GetText(), algebraic,
					alg_len);
			fprintf(stderr, "ATP ID:%i - %s in component %s\n",
					algToPrint[iterator],
					ele->FirstChildElement("name")->GetText(),
					ele->FirstChildElement("component")->GetText());
			iterator++;
		}
	}
	fprintf(stderr, "CONFIG END\n");
	struct CONFIG cfg = { modelID, initial_time, final_time, dt, outputFreq,
			initPost, lastIteration, numConstantsToChange, numStatesToPrint,
			numAlgToPrint, vIndex, changedConstants, statesToPrint, algToPrint };
	return cfg;
}

void solveModel(int rat_length, int alg_length, double* CONSTANTS,
		double* RATES, double* STATES, double* ALGEBRAIC, CONFIG config,
		double* &t, double* &saveStates, double* &vState, const int buffSize) {

	bool *PRINTABLE_STATES = new bool[rat_length];
	bool *PRINTABLE_ALG = new bool[alg_length];
	std::fill_n(PRINTABLE_STATES, rat_length, false);
	std::fill_n(PRINTABLE_ALG, alg_length, false);
	fprintf(stderr, "SolveModel 388\n");
	double initial_time = config.initial_time;
	double dt = config.dt;
	int retval;
	long it = 0;
	int modelID = config.modelID;
	int outputFreq = config.outputFreq;
	long initPost = config.initPost;
	long lastIteration = config.lastIteration;
	int numConstantsToChange = config.numConstantsToChange;
	int numStatesToPrint = config.numStatesToPrint;
	int * statesToPrint = config.statesToPrint;
	int numAlgToPrint = config.numAlgToPrint;
	int * algToPrint = config.algToPrint;
	int vIndex = config.vIndex;
	changed_double * ChangedConstants = config.ChangedConstants;
	int simpleIterator = 0;

	fprintf(stderr, "SolveModel 406 NUMC2CHANGE: %i\n",numConstantsToChange);

	for (int iteratorConstants = 0; iteratorConstants < numConstantsToChange;
			iteratorConstants++) {
		fprintf(stderr, "SolveModel 410 ITER: %i , %i --- %e\n",iteratorConstants,ChangedConstants[iteratorConstants].key,ChangedConstants[iteratorConstants].value);

		CONSTANTS[ChangedConstants[iteratorConstants].key] =
				ChangedConstants[iteratorConstants].value;
	}
	fprintf(stderr, "SolveModel 413 \n");
	for (simpleIterator = 0; simpleIterator < numStatesToPrint;
			simpleIterator++) {
		PRINTABLE_STATES[statesToPrint[simpleIterator]] = true;
		fprintf(stderr, "PRINTABLE_STATE ID:%i\n",
				statesToPrint[simpleIterator]);
	}

	for (simpleIterator = 0; simpleIterator < numAlgToPrint; simpleIterator++) {
		PRINTABLE_ALG[algToPrint[simpleIterator]] = true;
	}

	saveStates = new double[(int) ((((lastIteration - initPost) / outputFreq)
			+ 1) * (numStatesToPrint + numAlgToPrint + 1))];

	vState = new double[(int) (((lastIteration - initPost) / outputFreq) + 1)];
	t = new double[(int) (((lastIteration - initPost) / outputFreq) + 1)];
	double VOI = initial_time;

	//If it exists a checkpoint, load data from it
	it = loadDataFromCheckPoint( rat_length, alg_length, buffSize, STATES,
			ALGEBRAIC);
	int saveIterator = 0;
	int vIterator = 0;

	double last = 1.0 / double(lastIteration);

	for (; it <= lastIteration; it++) {

		if ((it % 0x80000) == 0) {
			double frac = double(it) * last;
			boinc_fraction_done(frac);
		}

		VOI = dt * it; //Integration variable, in this case, time
		computeRates(modelID, VOI, CONSTANTS, RATES, STATES, ALGEBRAIC);

		if (it % outputFreq == 0 && it >= initPost) {
			saveStates[saveIterator++] = VOI;
			vState[vIterator] = STATES[vIndex];
			t[vIterator++] = VOI;
		}

		for (int i = 0; i < rat_length; i++) {

			if (PRINTABLE_STATES[i] && it % outputFreq == 0 && it >= initPost) {
				saveStates[saveIterator++] = STATES[i];
			}
			STATES[i] += (RATES[i] * dt);

		}

		for (int j = 0; j < alg_length; j++) {
			if (PRINTABLE_ALG[j] && it % outputFreq == 0 && it >= initPost) {
				saveStates[saveIterator++] = ALGEBRAIC[j];
			}
		}

		if (boinc_time_to_checkpoint()) {
			retval = do_checkpoint(rat_length, alg_length, it, buffSize, STATES,
					ALGEBRAIC);
			if (retval) {
				fprintf(stderr,
						"DENIS: checkpoint failed at Iteration %d , retval%d\n",
						(int) it, retval);
				exit(1);
			}
			boinc_checkpoint_completed();
		}

	}

}

void printResults(char output_path[], double* saveStates, CONFIG config) {
	int outputFreq = config.outputFreq;
	int numColumnsToSave = config.numAlgToPrint + config.numStatesToPrint + 1;
	int numIterations = (int) (round(
			(config.lastIteration - config.initPost) / outputFreq) + 1);
	FILE* f;
	f = boinc_fopen(output_path, "w");

	//TODO: HERE A LOOP TO PRINT THE HEADERS

	for (int i = 0; i < numIterations; i++) {
		for (int j = 0; j < numColumnsToSave; j++) {
			fprintf(f, "%+1.8e", saveStates[i * numColumnsToSave + j]);
			if (j == numColumnsToSave - 1)
				fprintf(f, "\n");
			else
				fprintf(f, "\t");
		}
	}
	fclose(f);
}

void saveMarkers(char markers_path[], double* t, double* V, CONFIG config) {

	List markerList = NULL;
	double minV = V[0];
	double maxV = INFINITY;
	double apd75 = -1;
	double apd50 = -1;
	double apd25 = -1;
	double apd10 = -1;
	double maxDiff = 0.001;
	double minDiff = -INFINITY;
	int maxDiff_ind = 0;
	int APD_n = 0;
	int vlen = (int) (round(
			(config.lastIteration - config.initPost) / config.outputFreq));

	FILE* f;
	f = boinc_fopen(markers_path, "w");

	for (int i = 1; i < vlen; i++) {

		double diff = (V[i] - V[i - 1]) / (t[i] - t[i - 1]);

		if (diff > maxDiff) {
			maxDiff = diff;
			maxDiff_ind = i;

			if (isinf(maxV)) {
				maxV = V[i];
				minDiff = maxDiff;
			}

		}

		if (V[i] > maxV)
			maxV = V[i];


		if (V[i] < minV)
			minV = V[i];


		if (minDiff > diff)
			minDiff = diff;

		if (maxDiff_ind > 0) {
			double line90 = maxV - (maxV - minV) * 0.9;
			double line75 = maxV - (maxV - minV) * 0.75;
			double line50 = maxV - (maxV - minV) * 0.5;
			double line25 = maxV - (maxV - minV) * 0.25;
			double line10 = maxV - (maxV - minV) * 0.1;

			if (V[i] <= line75 && V[i - 1] > line75)
				apd75 = t[i] - t[maxDiff_ind];

			if (V[i] <= line50 && V[i - 1] > line50)
				apd50 = t[i] - t[maxDiff_ind];

			if (V[i] <= line25 && V[i - 1] > line25)
				apd25 = t[i] - t[maxDiff_ind];

			if (V[i] <= line10 && V[i - 1] > line10)
				apd10 = t[i] - t[maxDiff_ind];

			if (V[i] < line90) {
				Insert(markerList, t[i] - t[maxDiff_ind], apd75, apd50, apd25,
						apd10, t[maxDiff_ind], maxV, minV, maxDiff, minDiff);

				maxDiff_ind = 0;
				maxDiff = 0.001;
				maxV = INFINITY;
				minDiff = INFINITY;
				minV = V[i];
				APD_n = APD_n + 1;
			}
		}
	}


	fprintf(f,"ID\tAPD90\tAPD75\tAPD50\tAPD25\tAPD10\tAPD_time\tMaxV\tMinV\tMaxDiffV\tMinDiffV\n");
	int id = 1;
	if (EmptyList(markerList))
		fprintf(f, "");
	else {
		while (markerList != NULL) {
			fprintf(f, "%i", id);
			fprintf(f, "\t%+1.8e", markerList->apd90);
			fprintf(f, "\t%+1.8e", markerList->apd75);
			fprintf(f, "\t%+1.8e", markerList->apd50);
			fprintf(f, "\t%+1.8e", markerList->apd25);
			fprintf(f, "\t%+1.8e", markerList->apd10);
			fprintf(f, "\t%+1.8e", markerList->apdtime);
			fprintf(f, "\t%+1.8e", markerList->maxV);
			fprintf(f, "\t%+1.8e", markerList->minV);
			fprintf(f, "\t%+1.8e", markerList->maxDiff);
			fprintf(f, "\t%+1.8e\n", markerList->minDiff);
			markerList = markerList->next;
			id++;
		}
	}

	fclose(f);
}
/*
 *  Dummy graphics API entry points.  This app does not do graphics, 
 *  but it still must provide these empty callbacks (for BOINC 5).  
 */
#if BOINC_MAJOR_VERSION < 6
void app_graphics_init() {
}
void app_graphics_resize(int width, int height) {
}
void app_graphics_render(int xs, int ys, double time_of_day) {
}
void app_graphics_reread_prefs() {
}
void boinc_app_mouse_move(int x, int y, int left, int middle, int right) {
}
void boinc_app_mouse_button(int x, int y, int which, int is_down) {
}
void boinc_app_key_press(int, int) {
}
void boinc_app_key_release(int, int) {
}
#endif

