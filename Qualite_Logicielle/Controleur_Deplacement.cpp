// Controleur_Deplacement.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Robiot.h"
#include "Controleur_Deplacement.h"



int main()
{
	Robiot _robiot(PATH1,PATH2);
	CCompas::Pos _currentpos(CCompas::Pos{ 0,0 });
	_robiot.moteur.ActiveMoteur(CCompas::DOWN);
	_robiot.moteur.ActiveMoteur(CCompas::DOWN);
	_robiot.moteur.ActiveMoteur(CCompas::DOWN);
	_robiot.moteur.ActiveMoteur(CCompas::LEFT);
	_robiot.commande.GetNextPos();
	_currentpos = _robiot.commande.GetNextPos();
	printf("Position Robot : %d , %d", _robiot.moteur.compas.GetPosition().x, _robiot.moteur.compas.GetPosition().y);
	printf("Prochaine Destination : %d , %d", _currentpos.x, _currentpos.y);
}




void Controleur_Deplacement::Init()
{
	
}

void Controleur_Deplacement::GestionDeplacement()
{
}

void Controleur_Deplacement::SetConso()
{
}
