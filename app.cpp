/***********************************************************************\
 *  DENIS Boinc Application
 *   
 *  This application is based on Hello World app from Boinc source code
 *  The initial parameters and the method to perform the calculus is 
 *  inside the model.h file. 
 *
 *  If you run it in standalone mode, the file with parameters must be 
 *  called 'in' ( without quotes and without extension)
 *  
 *  For more information see the release notes at 
 *      http://denis.usj.es
 *
 *  Jesus Carro <jcarro@usj.es> - C++ Initial Version
 *  Joel Castro <jcastro@usj.es> - 11 March 2015 (Added Boinc support)
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
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "model.h"


/* INPUT OUTPUT INCLUDES */
#define INPUT_FILENAME "in"
#define OUTPUT_FILENAME "out"


using namespace std;
extern void vectorsLength(int *,int *,int *);
void initConsts(double* CONSTANTS, double* RATES, double *STATES);
void computeRates(double VOI, double* CONSTANTS, double* RATES, double* STATES, double* ALGEBRAIC);


/* UNCOMMENT TO ADD SPLIT FUNCTION FOR OLD GCC-COMPILATORS

#if !HAVE_SPLIT
std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}
#endif
*/

/* Begin: */ 
int main() {
  int rc;                       // return code from various functions
  char input_path[512], output_path[512],buf[256],readerBuffer[1024];
  double fsize;
  FILE* f,*infile;                      // file pointer for out.txt

  /*
   *  Before initializing BOINC itself, intialize diagnostics, so as
   *  to get stderr output to the file stderr.txt, and thence back home.
   */

  boinc_init_diagnostics(BOINC_DIAG_REDIRECTSTDERR|
                         BOINC_DIAG_MEMORYLEAKCHECKENABLED|
                         BOINC_DIAG_DUMPCALLSTACKENABLED| 
                         BOINC_DIAG_TRACETOSTDERR);



  /* BOINC apps that do not use graphics just call boinc_init() */

  rc = boinc_init();
  if (rc){
    fprintf(stderr, "APP: boinc_init() failed. rc=%d\n", rc);
    fflush(0);
    exit(rc);
  }

  /*
   * Input and output files need to be "resolved" from their logical name
   * for the application to the actual path on the client's disk
   */


    boinc_resolve_filename(INPUT_FILENAME, input_path, sizeof(input_path));
    infile = boinc_fopen(input_path, "r");
    if (!infile) {
        fprintf(stderr,
            "%s Couldn't find input file, resolved name %s.\n",
            boinc_msg_prefix(buf, sizeof(buf)), input_path
        );
        exit(-1);
    }

    // get size of input file (used to compute fraction done)
    //
    file_size(input_path, fsize);

  rc = boinc_resolve_filename(OUTPUT_FILENAME, output_path, sizeof(output_path));
  if (rc){
    fprintf(stderr, "APP: cannot resolve output file name. RC=%d\n", rc);
    boinc_finish(rc);    /* back to BOINC core */
  }

  /*
   *  Open files with boinc_fopen() not just fopen()
   *  (Output files should usually be opened in "append" mode, in case
   *  this is actually a restart (which will not be the case here)).
   */
  f = boinc_fopen(output_path, "w");



  /* Now run DENIS APPLICATION ALGORITHM */

 /* Initial Default Values */
	double initial_time;
	double final_time; //ms
	double dt; //ms
	int outputFreq;
	

	//Get array's length values
	int alg_length=0;
	int rat_length=0;
	int cons_length=0;
	vectorsLength(&alg_length,&rat_length,&cons_length);

	//Generate arrays
	
	double *CONSTANTS = new double[cons_length];
	double *RATES = new double[rat_length];
	double *STATES = new double[rat_length];
	double *ALGEBRAIC = new double[alg_length];
	const char* VOI_name;
	const char** CONSTANTS_names = new const char*[cons_length];
	const char** RATES_names = new const char*[rat_length];
	const char** STATES_names = new const char*[rat_length];
	const char** ALGEBRAIC_names = new const char*[alg_length];
	bool *PRINTABLE_STATES = new bool[rat_length];
	std::fill_n( PRINTABLE_STATES, rat_length, 0 );

	//Initialize arrays
	initConsts(CONSTANTS,STATES);

	//Get Names
	names(VOI_name,CONSTANTS_names, RATES_names, STATES_names, ALGEBRAIC_names);

	//Get Values of Configuration File
	std::string line;
	line = fgets(readerBuffer,sizeof(readerBuffer),infile);
	final_time = atof (line.c_str());
	fprintf(stderr,"Operation time:%f\n",final_time);

	line = fgets(readerBuffer,sizeof(readerBuffer),infile);
	dt = atof (line.c_str());
	fprintf(stderr,"Diferential Time:%f\n",dt);

	line = fgets(readerBuffer,sizeof(readerBuffer),infile);
	outputFreq = atoi (line.c_str());
	fprintf(stderr,"Frequency:%i\n",outputFreq);

	line = fgets(readerBuffer,sizeof(readerBuffer),infile);
	initial_time = atof (line.c_str());
	fprintf(stderr,"Initial Time:%f\n",initial_time);

	int initPost = (int)((initial_time)/dt);

	//MODIFY CONSTANTS BASED ON CONFIGURATION FILE
	line = fgets(readerBuffer,sizeof(readerBuffer),infile);
	int numConstantsToChange = atoi (line.c_str());

	for(int iteratorConstants=0;iteratorConstants<numConstantsToChange;iteratorConstants++)
	{
		line = fgets(readerBuffer,sizeof(readerBuffer),infile);
		CONSTANTS[atoi ((split(line,' ')[0]).c_str())] = atof ((split(line,' ')[1]).c_str());
	}

	//DEFINE VARIABLES TO PRINT
	line = fgets(readerBuffer,sizeof(readerBuffer),infile);
	int numRatesToChange = atoi (line.c_str());

	for(int iteratorRates=0;iteratorRates<numRatesToChange;iteratorRates++)
	{
		line = fgets(readerBuffer,sizeof(readerBuffer),infile);
		PRINTABLE_STATES[atoi (line.c_str())] = true;
	}


	//Generate array value and saves them in a xls file
	int i=0;
	double VOI=initial_time;

	fprintf(f,"\"%s\"",(const char *)VOI_name);
	for(i=0;i<rat_length;i++)
		if(PRINTABLE_STATES[i])
			fprintf(f,"\t\"%s\"",(const char*)STATES_names[i]);
	fprintf(f,"\n");

	for(int it=0;it*dt<=final_time;it++)
	{
		boinc_fraction_done(double (it*dt)/final_time);
		VOI =dt*it; //Integration variable, in this case, time
		
		computeRates(VOI, CONSTANTS, RATES, STATES, ALGEBRAIC);


		if(it%outputFreq==0 && it>=initPost)
			fprintf(f,"%12.6f",VOI);//Print the time in the first column
		for(i=0;i<rat_length;i++)
		{
			if(PRINTABLE_STATES[i]){
				STATES[i]+=(RATES[i]*dt);
				if(it%outputFreq==0 && it>=initPost)
					fprintf(f,"\t%+1.8e",STATES[i]); //Print the value in the cell
			}

		}
		if(it%outputFreq==0 && it>=initPost)
			fprintf(f,"\n"); //new line of excel file

	}

	


  /* All BOINC applications must exit via boinc_finish(rc), not merely exit() */

  fclose(f);               
  boinc_finish(0);
}


/*
 *  Dummy graphics API entry points.  This app does not do graphics, 
 *  but it still must provide these empty callbacks (for BOINC 5).  
 */
#if BOINC_MAJOR_VERSION < 6
void app_graphics_init() {}
void app_graphics_resize(int width, int height){}
void app_graphics_render(int xs, int ys, double time_of_day) {}
void app_graphics_reread_prefs() {}
void boinc_app_mouse_move(int x, int y, int left, int middle, int right ){}
void boinc_app_mouse_button(int x, int y, int which, int is_down){}
void boinc_app_key_press(int, int){}
void boinc_app_key_release(int, int){}
#endif



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
//EOF//
