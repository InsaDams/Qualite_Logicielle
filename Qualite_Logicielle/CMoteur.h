#include <string>
#include "CCompas.h"
//#include "Controleur_Deplacement.h"
using namespace std;
// V2
#pragma once
class CMoteur
{
public:
	// Constructeurs
	CMoteur();
	void ActiveMoteur(CCompas::MOVE move);
	CCompas compas;
private:
	
		
	//Accesseurs et mutateurs


};
