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
#ifndef CONFIG_H_
#define CONFIG_H_
struct CONFIG {
	int modelID;
	double initial_time;
	double final_time; //ms
	double dt; //ms
	int outputFreq;
	long initPost;
	long lastIteration;

	int numConstantsToChange;
	int numStatesToPrint;
	int numAlgToPrint;
	int vIndex;

	struct changed_double *ChangedConstants;
	int * statesToPrint;
	int * algToPrint;
};

struct changed_double {
	int key;
	double value;
};

#endif /* CONFIG_H_ */
