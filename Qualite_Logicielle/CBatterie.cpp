#include "CBatterie.h"
//V1

//Calcule la consommation finale de la batterie
double CBatterie::calculconso(int tempsparcours, int nbcontroles, int tempstotal)
{
	// Le moteur a une puissance de 2*CONSOMOTEUR W (CONSOMOTEUR W * 2 roues) et sont utilis�es pendant tempsparcours
	// Les �quipements de mesures ont une puissance de CONSOMESURE et sont utilis�s pendant TEMPSMESURE nbcontroles fois
	// Le processeur a une puissance CONSOARM et est utilis� pendant la totalit� du fonctionnement du robot tempstotal
	// La conso totale est ainsi �gale � la somme des consommations du moteur, du processeur et des �quipements de mesure pendant toute la dur�e du trajet.
	conso =(double)((2 * CONSOMOTEUR*tempsparcours / 3600) + (double)(CONSOMESURE*TEMPSMESURE* (double)nbcontroles) / 60) + (double)(CONSOARM*tempstotal / 3600);

	return conso;
}
// Renvoie la consommation totale
double CBatterie::getconso()
{
	return conso;
}
