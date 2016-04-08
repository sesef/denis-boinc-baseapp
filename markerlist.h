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

#ifndef MARKERLIST_H_
#define MARKERLIST_H_

typedef struct marker {
	double minV;
	double maxV;
	double apd90;
	double apd75;
	double apd50;
	double apd25;
	double apd10;
	double apdtime;
	double maxDiff;
	double minDiff;
	struct marker * next;
};

typedef marker *List;

int EmptyList(List &l){
	if (l == NULL) {
			return 1;
		} else {
			return 0;
		}
}

void Insert(List &l, double apd90, double apd75,
		double apd50, double apd25, double apd10, double apdtime,
		double maxV,double minV,double maxDiff, double minDiff) {

	List oldNode, newNode = new (struct marker);

	newNode->apd90 = apd90;
	newNode->apd75 = apd75;
	newNode->apd50 = apd50;
	newNode->apd25 = apd25;
	newNode->apd10 = apd10;
	newNode->apdtime = apdtime;
	newNode->maxV = maxV;
	newNode->minV = minV;
	newNode->maxDiff = maxDiff;
	newNode->minDiff = minDiff;
	newNode->next = NULL;

	if (l == NULL) {
		l = newNode;
	} else {
		oldNode = l;
		while (oldNode->next != NULL) {
			oldNode = oldNode->next;
		}
		oldNode->next = newNode;
	}

}

#endif /* MARKERLIST_H_ */
