#pragma once
#include <string>
#include "Robiot.h"
#define PATH "C:/Users/Goron/Desktop/terrain.txt"
using namespace std;
// V1
#pragma once
class Controleur_Deplacement
{
public:
	// Constructeurs
	enum MOVE { UP = 0, DOWN=1, LEFT=2, RIGHT=3 };
	/*CMoteur moteur;
	CBatterie batterie;
	CCapteur capteur;
	CCompas compas;
	CCommande commande;*/
	//Accesseurs et mutateurs
	struct Pos
	{
		int x; // Abscisses
		int y; // Ordonnées
	};

private:

	void Init();
	void GestionDeplacement();
	void SetConso();
};