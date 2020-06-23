#include "CBatterie.h"
//V1

//Calcule la consommation finale de la batterie
double CBatterie::calculconso(int tempsparcours, int nbcontroles, int tempstotal)
{
	// Le moteur a une puissance de 2*CONSOMOTEUR W (CONSOMOTEUR W * 2 roues) et sont utilisées pendant tempsparcours
	// Les équipements de mesures ont une puissance de CONSOMESURE et sont utilisés pendant TEMPSMESURE nbcontroles fois
	// Le processeur a une puissance CONSOARM et est utilisé pendant la totalité du fonctionnement du robot tempstotal
	// La conso totale est ainsi égale à la somme des consommations du moteur, du processeur et des équipements de mesure pendant toute la durée du trajet.
	conso =(double)((2 * CONSOMOTEUR*tempsparcours / 3600) + (double)(CONSOMESURE*TEMPSMESURE* (double)nbcontroles) / 60) + (double)(CONSOARM*tempstotal / 3600);

	return conso;
}
// Renvoie la consommation totale
double CBatterie::getconso()
{
	return conso;
}


//Metrique : Comment Only  :  lignes 36.8 %
//                            Caractères :64.0 %