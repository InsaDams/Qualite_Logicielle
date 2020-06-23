#include <string>
#include "CMoteur.h"
#include "CBatterie.h"
#include "CCommande.h"
#include "CCapteur.h"
using namespace std;
// V3
#pragma once
class Robiot
{
public:
	// Constructeurs
	Robiot(string pathfile1, string pathfile2);

	CMoteur moteur;
	CBatterie batterie;
	CCapteur capteur;
	CCommande commande;
	//Accesseurs et mutateurs

private:
	string path1;
	string path2;

};


