/***********************************************************************\
 *  DENIS@HOME Boinc Application
 *   
 *  This application is based on Hello World app from Boinc source code
 *  The initial parameters and the method to perform the calculus is 
 *  inside the model.h file. 
 *
 *  If you run it in standalone mode, the file with parameters must be 
 *  called 'in' ( without quotes and without extension)
 *  
 *  For more information see the release notes at 
 *	  http://denis.usj.es
 *
 *  Jesus Carro <jcarro@usj.es> 
 *  Joel Castro <jcastro@usj.es>
 *  version: 1.04 - 3 June 2015
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
#include <stdio.h>
#include <math.h>
#include "model.h"
#include "config.h"

/* INPUT OUTPUT INCLUDES */
#define CHECKPOINT_FILE "denis_state"
#define INPUT_FILENAME "in"
#define OUTPUT_FILENAME "out"

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

int do_checkpoint(int rat_length, long it, const int buffSize, double* STATES) {
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

	for (int stateIterator = 0; stateIterator < rat_length; stateIterator++) {
		checkpointFile.write(reinterpret_cast<char *>(&STATES[stateIterator]),
				sizeof(double));
	}

	checkpointFile.close();
	return 0;
}

void loadDataFromCheckPoint(long* it, int rat_length, const int buffSize,
		double* STATES) {
	char chkpt_path[buffSize];
	std::string line;

	it = 0;

	int rc = boinc_resolve_filename(CHECKPOINT_FILE, chkpt_path, buffSize);
	if (rc) {
		fprintf(stderr, "APP: cannot resolve checkpoint file name. RC=%d\n",
				rc);
		boinc_finish(rc);
	}

	FILE* state = boinc_fopen(chkpt_path, "r");
	if (!state || appData.wu_cpu_time == 0)
		return;

	fstream checkpointFile(chkpt_path, ios::in | ios::binary);
	if (checkpointFile.is_open())
		checkpointFile.close();

	checkpointFile.open(chkpt_path, ios::in | ios::binary);

	checkpointFile.read(reinterpret_cast<char *>(it), sizeof(long));

	for (int stateIterator = 0; stateIterator < rat_length; stateIterator++) {
		checkpointFile.read(reinterpret_cast<char *>(&STATES[stateIterator]),
				sizeof(double));
	}

	checkpointFile.close();
}

void initBoinc() {
	boinc_init_diagnostics(BOINC_DIAG_REDIRECTSTDERR |
	BOINC_DIAG_MEMORYLEAKCHECKENABLED |
	BOINC_DIAG_DUMPCALLSTACKENABLED |
	BOINC_DIAG_TRACETOSTDERR);

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

void getFilePaths(char input_path[], char output_path[], const int buffSize) {
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
}

CONFIG loadConfiguration(char input_path[]) {
	FILE* infile = boinc_fopen(input_path, "r");
	char buf[256], readerBuffer[1024];
	if (!infile) {
		fprintf(stderr, "%s Couldn't find input file, resolved name %s.\n",
				boinc_msg_prefix(buf, sizeof(buf)), input_path);
		exit(-1);
	}

	double initial_time;
	double final_time;
	double dt;
	int outputFreq;

	//Get Values of Configuration File
	std::string line;
	line = fgets(readerBuffer, sizeof(readerBuffer), infile);
	final_time = atof(line.c_str());
	fprintf(stderr, "OpT:%f\n", final_time);

	line = fgets(readerBuffer, sizeof(readerBuffer), infile);
	dt = atof(line.c_str());
	fprintf(stderr, "DT:%f\n", dt);

	line = fgets(readerBuffer, sizeof(readerBuffer), infile);
	outputFreq = atoi(line.c_str());
	fprintf(stderr, "F:%i\n", outputFreq);

	line = fgets(readerBuffer, sizeof(readerBuffer), infile);
	initial_time = atof(line.c_str());
	fprintf(stderr, "InT:%f\n", initial_time);

	long initPost = (long) (round(initial_time / dt));
	long lastIteration = (long) (round(final_time / dt));

	line = fgets(readerBuffer, sizeof(readerBuffer), infile);
	int numConstantsToChange = atoi(line.c_str());
	changed_double * changedConstants = new changed_double[numConstantsToChange];

	for (int iteratorConstants = 0; iteratorConstants < numConstantsToChange;
			iteratorConstants++) {
		line = fgets(readerBuffer, sizeof(readerBuffer), infile);
		changedConstants[iteratorConstants].key = atoi(
				(string_split(line, ' ')[0]).c_str());
		changedConstants[iteratorConstants].value = atof(
				(string_split(line, ' ')[1]).c_str());
	}

	line = fgets(readerBuffer, sizeof(readerBuffer), infile);
	int numStatesToPrint = atoi(line.c_str());
	int * statesToPrint = new int[numStatesToPrint];
	for (int iteratorRates = 0; iteratorRates < numStatesToPrint;
			iteratorRates++) {
		line = fgets(readerBuffer, sizeof(readerBuffer), infile);
		statesToPrint[iteratorRates] = atoi(line.c_str());
	}

	struct CONFIG cfg = { initial_time, final_time, dt, outputFreq, initPost,
			lastIteration, numConstantsToChange, numStatesToPrint,
			changedConstants, statesToPrint };
	return cfg;
}

void solveModel(int rat_length, double* CONSTANTS, double* RATES,
		double* STATES, double* ALGEBRAIC, CONFIG config, double* &saveStates,
		const int buffSize) {

	bool *PRINTABLE_STATES = new bool[rat_length];

	std::fill_n(PRINTABLE_STATES, rat_length, false);

	double initial_time = config.initial_time;
	double dt = config.dt;
	int retval;
	long it = 0;
	int outputFreq = config.outputFreq;
	long initPost = config.initPost;
	long lastIteration = config.lastIteration;
	int numConstantsToChange = config.numConstantsToChange;
	int numStatesToPrint = config.numStatesToPrint;
	int * statesToPrint = config.statesToPrint;
	changed_double * ChangedConstants = config.ChangedConstants;
	int iteratorRates = 0;

	for (int iteratorConstants = 0; iteratorConstants < numConstantsToChange;
			iteratorConstants++)
		CONSTANTS[ChangedConstants[iteratorConstants].key] =
				ChangedConstants[iteratorConstants].value;

	for (iteratorRates = 0; iteratorRates < numStatesToPrint; iteratorRates++)
		PRINTABLE_STATES[statesToPrint[iteratorRates]] = true;

	saveStates = new double[(int) ((((lastIteration - initPost) / outputFreq)
			+ 1) * (numStatesToPrint + 1))];

	double VOI = initial_time;

	//If it exists a checkpoint, load data from it
	loadDataFromCheckPoint(&it, rat_length, buffSize, STATES);

	int saveIterator = 0;
	for (; it <= lastIteration; it++) {
		boinc_fraction_done(double(it / lastIteration));

		VOI = dt * it; //Integration variable, in this case, time
		computeRates(VOI, CONSTANTS, RATES, STATES, ALGEBRAIC);
		if (it % outputFreq == 0 && it >= initPost)
			saveStates[saveIterator++] = VOI;

		for (int i = 0; i < rat_length; i++) {
			STATES[i] += (RATES[i] * dt);

			if (PRINTABLE_STATES[i] && it % outputFreq == 0 && it >= initPost) {
				saveStates[saveIterator++] = STATES[i];
			}

		}

		if (boinc_time_to_checkpoint()) {
			retval = do_checkpoint(rat_length, it, buffSize, STATES);
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
	int numStatesToSave = config.numStatesToPrint + 1;
	int numIterations = (int) (round(
			(config.lastIteration - config.initPost) / outputFreq) + 1);
	FILE* f;
	f = boinc_fopen(output_path, "w");

	//TODO: HERE A LOOP TO PRINT THE HEADERS

	for (int i = 0; i < numIterations; i++) {
		for (int j = 0; j < numStatesToSave; j++) {
			fprintf(f, "%+1.8e", saveStates[i * numStatesToSave + j]);
			if (j == numStatesToSave - 1)
				fprintf(f, "\n");
			else
				fprintf(f, "\t");
		}
	}
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

