#pragma once
#define CONSOMOTEUR 14.0 //Puissance de chaque moteur (1 moteur par roue) en Watt
#define CONSOMESURE 30.0 //Puissance de l'ensemble des équipements de mesures en Watt
#define CONSOARM 12.5 //Puissance processeur en Watt
#define TEMPSMESURE 5.0 //Temps nécessaire pour contrôler un arbre (en minutes)

//V3

class CBatterie
{
	//Attributs
private:
	double conso;

	//Methodes

public:
	double calculconso(int tempsparcours, int nbcontroles, int tempstotal);

	double getconso();
};

