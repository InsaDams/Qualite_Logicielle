#pragma once
#include <string>
#include "Robiot.h"
#define PATH1 "C:/Users/Pierre-Antoine/Documents/Qualite_Logicielle/Qualite_Logicielle/terrain.txt"
#define PATH2 "C:/Users/Pierre-Antoine/Documents/Qualite_Logicielle/Qualite_Logicielle/commande.txt"
using namespace std;
// V2
#pragma once
class Controleur_Deplacement
{
public:
	Controleur_Deplacement();
	// Constructeurs
	

	//Accesseurs et mutateurs
	

private:
	CCompas::Pos _currentpos;
	void Init();
	void GestionDeplacement();
	void SetConso();
};