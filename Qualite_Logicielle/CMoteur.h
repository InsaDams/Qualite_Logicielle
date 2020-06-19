#include <string>
#include "CCompas.h"
#include "Controleur_Deplacement.h"
using namespace std;
// V2
#pragma once
class CMoteur
{
public:
	// Constructeurs
	CMoteur();
	void ActiveMoteur(Controleur_Deplacement::MOVE move);

private:
	CCompas compas;
		
	//Accesseurs et mutateurs


};
