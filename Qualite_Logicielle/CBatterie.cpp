#include "CBatterie.h"
//V1
int CBatterie::calculconso(int tempsparcours, int nbcontroles, int tempstotal)
{
	conso = ((2 * CONSOMOTEUR*tempsparcours / 3600) + (CONSOMESURE*TEMPSMESURE*nbcontroles) / 60) + (CONSOARM*tempstotal / 60);

	return conso;
}

int CBatterie::getconso()
{
	return conso;
}
