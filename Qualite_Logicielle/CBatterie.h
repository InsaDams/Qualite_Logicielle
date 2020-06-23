#pragma once
#define CONSOMOTEUR 14.0
#define CONSOMESURE 30.0
#define CONSOARM 12.5
#define TEMPSMESURE 5.0

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

