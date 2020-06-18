#pragma once
#include <string>
#include "Robiot.h"
#define PATH "C:/Users/Goron/Desktop/terrain.txt"
using namespace std;

#pragma once
class Controleur_Deplacement
{
public:
	// Constructeurs
	
	/*CMoteur moteur;
	CMesure mesure;
	CBatterie batterie;
	CCapteur capteur;
	CCompas compas;
	CCommande commande;*/
	//Accesseurs et mutateurs

private:

	void Init();
	void GestionDeplacement();
	void SetConso();
};