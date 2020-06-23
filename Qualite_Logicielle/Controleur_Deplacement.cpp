// Controleur_Deplacement.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Robiot.h"
#include "Controleur_Deplacement.h"

Controleur_Deplacement::Controleur_Deplacement() : _robiot(PATH1, PATH2)
{
	Init();
	GestionDeplacement();
	ResultSimu();
	/*CCompas::Pos _currentpos(CCompas::Pos{ 0,0 });*/
	/*_robiot.moteur.ActiveMoteur(CCompas::DOWN);
	_robiot.moteur.ActiveMoteur(CCompas::DOWN);
	_robiot.moteur.ActiveMoteur(CCompas::DOWN);
	_robiot.moteur.ActiveMoteur(CCompas::LEFT);
	_robiot.commande.GetNextPos();
	_currentpos = _robiot.commande.GetNextPos();
	printf("Position Robot : %d , %d\n", _robiot.moteur.compas.GetPosition().x, _robiot.moteur.compas.GetPosition().y);
	printf("Prochaine Destination : %d , %d\n", _currentpos.x, _currentpos.y);*/
}

void Controleur_Deplacement::Init()
{
	_startpos=_robiot.capteur.GetStart();
	_robiot.moteur.compas.SetStart(_startpos);
	printf("Position de Depart : %d , %d\n", _startpos.x, _startpos.y);
}

void Controleur_Deplacement::CalculDep()
{
	int dep_x, dep_y;
	dep_x = _nextpos.x - _currentpos.x;
	dep_y = _nextpos.y - _currentpos.y;
	for (int i = 0; i < abs(dep_x); i++)
	{
		if (dep_x < 0)
		{
			MoveRobiot(CCompas::LEFT);
		}
		else
		{
			MoveRobiot(CCompas::RIGHT);
		}
	}
	for (int i = 0; i < abs(dep_y); i++)
	{
		if (dep_y < 0)
		{
			MoveRobiot(CCompas::UP);
		}
		else
		{
			MoveRobiot(CCompas::DOWN);
		}
	}
}

void Controleur_Deplacement::GestionDeplacement()
{
	
	_currentpos = _startpos;
	_nextpos = _robiot.commande.GetNextPos();
	printf("Prochaine Destination : %d , %d\n", _nextpos.x, _nextpos.y);
	while (_nextpos.x!=0 || _nextpos.y != 0)
	{
		CalculDep();
		printf("Destination atteinte !\n");
		_currentpos = _nextpos;
		_nextpos = _robiot.commande.GetNextPos();
		printf("Prochaine Destination : %d , %d\n", _nextpos.x, _nextpos.y);
	}
	_nextpos = _startpos;
	printf("Prochaine Destination : %d , %d\n", _nextpos.x, _nextpos.y);
	CalculDep();
}

void Controleur_Deplacement::ResultSimu()
{
	racetime = _robiot.moteur.GetDistance() / VITROBOT;
	time = racetime + _robiot.commande.GetNbArbres()*TEMPSMESURE*60;
	conso = _robiot.batterie.calculconso(racetime, _robiot.commande.GetNbArbres(),time);
	printf("Temps de Deplacement : %d s\n", racetime);
	printf("Temps Total: %d s\n", time);
	printf("Nb Arbres Controle: %d\n", _robiot.commande.GetNbArbres());
	printf("Consommation Totale : %f W.h\n", conso);

}

void Controleur_Deplacement::MoveRobiot(CCompas::MOVE move)
{
	_robiot.moteur.ActiveMoteur(move);
	_currentpos = _robiot.moteur.compas.GetPosition();
	_robiot.capteur.UpdatePosition(_currentpos);
	printf("Position Robot : %d , %d\n", _currentpos.x, _currentpos.y);
	
}







