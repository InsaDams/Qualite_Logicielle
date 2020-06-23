#include <string>
#include "CCompas.h"
//#include "Controleur_Deplacement.h"
using namespace std;
// V3
#pragma once
class CMoteur
{
public:
	// Constructeurs
	CMoteur();
	void ActiveMoteur(CCompas::MOVE move);
	CCompas compas;
	int GetDistance();
private:
	int _distance;
		
	//Accesseurs et mutateurs


};
