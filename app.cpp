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
#include "functions.h"

using namespace std;

int main() {
	const int buffSize = 512;
	char input_path[buffSize], output_path[buffSize];

	initBoinc();

	fprintf(stderr, "Optimized by Sesef v1.5.5 (SSE3) 2015\n");

	getFilePaths(input_path, output_path, buffSize);

	CONFIG config = loadConfiguration(input_path);

	int alg_length, rat_length, cons_length = 0;
	vectorsLength(&alg_length, &rat_length, &cons_length);

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

	initConsts(CONSTANTS, STATES);

	names(VOI_name, CONSTANTS_names, RATES_names, STATES_names,
			ALGEBRAIC_names);

	solveModel(rat_length, CONSTANTS, RATES, STATES, ALGEBRAIC, config,
			saveStates, buffSize);

	boinc_begin_critical_section();
	printResults(output_path, saveStates, config);
	boinc_end_critical_section();
	boinc_finish(0);
}

