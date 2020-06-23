#include "CBatterie.h"
//V1
double CBatterie::calculconso(int tempsparcours, int nbcontroles, int tempstotal)
{
	conso =(double)((2 * CONSOMOTEUR*tempsparcours / 3600) + (double)(CONSOMESURE*TEMPSMESURE* (double)nbcontroles) / 60) + (double)(CONSOARM*tempstotal / 3600);

	return conso;
}

double CBatterie::getconso()
{
	return conso;
}
