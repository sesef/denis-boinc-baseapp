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
#include "functions.h"

using namespace std;

int main() {
	const int buffSize = 512;
	char input_path[buffSize], output_path[buffSize],markers_path[buffSize];
	int modelID;

	initBoinc();

	getFilePaths(input_path, output_path, markers_path,buffSize);
	modelID = loadModelID(input_path);

	int alg_length, rat_length, cons_length = 0;
	getVectorsLength (modelID,&alg_length, &rat_length, &cons_length);

	double *CONSTANTS = new double[cons_length];
	double *RATES = new double[rat_length];
	double *STATES = new double[rat_length];
	double *ALGEBRAIC = new double[alg_length];
	const char* VOI_name;
	const char** CONSTANTS_names = new const char*[cons_length];
	const char** RATES_names = new const char*[rat_length];
	const char** STATES_names = new const char*[rat_length];
	const char** ALGEBRAIC_names = new const char*[alg_length];
	double* saveStates;
	double* vState;
	double* t;


	initConsts(modelID,CONSTANTS, STATES);

	names(modelID,VOI_name, CONSTANTS_names, RATES_names, STATES_names,
			ALGEBRAIC_names);

	CONFIG config = loadConfiguration(input_path,CONSTANTS_names,STATES_names,ALGEBRAIC_names,cons_length,rat_length,alg_length,modelID);

	solveModel(rat_length,alg_length, CONSTANTS, RATES, STATES, ALGEBRAIC, config,
			t,saveStates,vState,buffSize);

	boinc_begin_critical_section();
	printResults(output_path, saveStates, config);
	saveMarkers(markers_path,t, vState, config);
	boinc_end_critical_section();
	boinc_finish(0);
}

#ifdef _WIN32

/*******************************************************
 * Windows: Unix applications begin with main() while Windows applications
 * begin with WinMain, so this just makes WinMain() process the command line
 * and then invoke main()
 */

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst,
		LPSTR Args, int WinMode)
{
	LPSTR command_line;
	char* argv[100];
	int argc;

	command_line = GetCommandLine();
	argc = parse_command_line( command_line, argv );
	return main();
}

#endif
