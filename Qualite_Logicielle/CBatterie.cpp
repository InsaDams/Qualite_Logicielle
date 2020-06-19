#include "CBatterie.h"

int CBatterie::calculconso(int tempsparcours, int nbcontroles, int tempstotal)
{
	conso = ((2 * CONSOMOTEUR*tempsparcours / 3600) + (CONSOMESURE*TEMPSMESURE*nbcontroles) / 60) + (CONSOARM*tempstotal / 60);

	return 0;
}

int CBatterie::getconso()
{
	return conso;
}
