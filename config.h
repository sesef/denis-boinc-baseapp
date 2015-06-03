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
struct CONFIG {
	double initial_time;
	double final_time; //ms
	double dt; //ms
	int outputFreq;
	long initPost;
	long lastIteration;

	int numConstantsToChange;
	int numStatesToPrint;

	struct changed_double *ChangedConstants;
	int * statesToPrint;
};

struct changed_double {
	int key;
	double value;
};

