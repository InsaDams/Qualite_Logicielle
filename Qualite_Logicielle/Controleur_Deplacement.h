#pragma once
#include <string>
#include "Robiot.h"
#define PATH1 "../terrain.txt" // Chemin pour le fichier contenant la carte du terrain
#define PATH2 "../commande.txt" // Chemin pour le fichier contenant les commandes
#define VITROBOT 0.42			// Vitesse du Robot
#define TEMPSMESURE 5.0			// Temps d'une mesure en minutes
using namespace std;
// V4
#pragma once
class Controleur_Deplacement
{
public:
	Controleur_Deplacement();
	// Constructeurs
	

	//Accesseurs et mutateurs
	

private:
	int time;
	int racetime;
	double conso;
	Robiot _robiot;
	CCompas::Pos _startpos;
	CCompas::Pos _nextpos;
	CCompas::Pos _currentpos;
	void Init();
	void CalculDep();
	void GestionDeplacement();
	void ResultSimu();
	void MoveRobiot(CCompas::MOVE move);
};