#pragma once
#define CONSOMOTEUR 14
#define CONSOMESURE 30
#define CONSOARM 12.5
#define TEMPSMESURE 5



class CBatterie
{
	//Attributs
private:
	int conso;

	//Methodes

public:
	int calculconso(int tempsparcours, int nbcontroles, int tempstotal);

	int getconso();
};

