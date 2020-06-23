#pragma once
#include <string>
#include "Robiot.h"
#define PATH1 "../terrain.txt"
#define PATH2 "../commande.txt"
#define VITROBOT 0.42
#define TEMPSMESURE 5.0
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