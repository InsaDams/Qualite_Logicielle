// Controleur_Deplacement.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Robiot.h"
#include "Controleur_Deplacement.h"

// Constructeur du controleur de déplacement, il appelle toute les fonctions nécessaire au cycle du robiot
Controleur_Deplacement::Controleur_Deplacement() : _robiot(PATH1, PATH2)
{
	Init();
	GestionDeplacement();
	ResultSimu();
}

// Fonction Pour initialiser la position de départ du robot
void Controleur_Deplacement::Init()
{
	_startpos=_robiot.capteur.GetStart();
	_robiot.moteur.compas.SetStart(_startpos);
	printf("Position de Depart : %d , %d\n", _startpos.x, _startpos.y);
}


// Fonction pour déplacer le robot en fonction de la commande
void Controleur_Deplacement::CalculDep()
{
	bool obstacle=false;
	int dep_x, dep_y;
	dep_x = _nextpos.x - _currentpos.x; // On calcule la distance en absisce par rapport à notre position actuelle
	dep_y = _nextpos.y - _currentpos.y; // On calcule la distance en ordonnée par rapport à notre position actuelle
	for (int i = 0; i < abs(dep_x); i++) // Boucle pour avancer en absicsse
	{
			if (dep_x < 0)			// Si on a un déplacement négatif on va à gauche, sinon à droite
			{
				if (_robiot.capteur.Getobstacle().state && _robiot.capteur.Getobstacle().dir==CCompas::LEFT)  // On vérifie si on a un obstacle dans notre direction
				{
					obstacle = true; // Si c'est le cas on leve le flag sur la variable obstacle
				}
				else
				{
					MoveRobiot(CCompas::LEFT); // On fait avancer le robot à Gauche
				}
			}
			else
			{
				if (_robiot.capteur.Getobstacle().state && _robiot.capteur.Getobstacle().dir == CCompas::RIGHT)
				{
					obstacle = true;
				}
				else
				{
					MoveRobiot(CCompas::RIGHT); // On fait avancer le robot à Droite
				}
			}
		
		if(obstacle)
		{
			MoveRobiot(CCompas::DOWN); // EN cas d'obstacle rencontrer on descends d'une case et on réessaye de déplacer le robot jusqu'au point d'arriver
			CalculDep();
			return;
		}
	}
	obstacle=false; // On remet le flag d'obstacle à l'état initial
	for (int i = 0; i < abs(dep_y); i++)  // Boucle pour avancer en ordonnée
	{
		if (dep_y < 0) // Si on a un déplacement négatif on en haut, sinon à bas
		{
			if (_robiot.capteur.Getobstacle().state && _robiot.capteur.Getobstacle().dir == CCompas::UP) // On vérifie si on a un obstacle dans notre direction
			{
				obstacle = true;
			}
			else
			{
				MoveRobiot(CCompas::UP); // On fait avancer le robot en Haut
			}
		}
		else
		{
			if (_robiot.capteur.Getobstacle().state && _robiot.capteur.Getobstacle().dir == CCompas::DOWN)	
			{
				obstacle = true;
			}
			else
			{
				MoveRobiot(CCompas::DOWN);  // On fait avancer le robot en Bas
			}
		}

		if (obstacle)
		{
			MoveRobiot(CCompas::LEFT); // EN cas d'obstacle rencontrer on descends d'une case et on réessaye de déplacer le robot jusqu'au point d'arriver
			CalculDep();
			return;
		}
	}
}

// Fonction pour séquencer les destination
void Controleur_Deplacement::GestionDeplacement()
{
	_currentpos = _startpos; // Notre position de départ est notre position actuelle
	_nextpos = _robiot.commande.GetNextPos(); // On récupère la prochaine destination
	printf("Prochaine Destination : %d , %d\n", _nextpos.x, _nextpos.y); 
	while (_nextpos.x!=0 || _nextpos.y != 0)	// Tant qu'on a des destination on fait bouger le robot
	{
		CalculDep();	// On déplace le robot à la destination
		printf("Destination atteinte !\n");
		//_currentpos = _nextpos;		
		_nextpos = _robiot.commande.GetNextPos(); // On récupère la position du prochain arbre à controler
		printf("Prochaine Destination : %d , %d\n", _nextpos.x, _nextpos.y);
	}
	_nextpos = _startpos; // On met la dernière destination sur le point de départ
	printf("Prochaine Destination : %d , %d\n", _nextpos.x, _nextpos.y);
	CalculDep(); // On déplace le robot jusqu'au point de départ
}

// Fonction pour afficher les mesures souhaitée
void Controleur_Deplacement::ResultSimu()
{
	racetime = _robiot.moteur.GetDistance() / VITROBOT; // On calcule le temps de parcours
	time = racetime + _robiot.commande.GetNbArbres()*TEMPSMESURE*60;// On calcule le temps total
	conso = _robiot.batterie.calculconso(racetime, _robiot.commande.GetNbArbres(),time);// On calcule la consommation a l'aide de la classe batterie
	printf("Temps de Deplacement : %d s\n", racetime); // On affiche toute les données
	printf("Temps Total: %d s\n", time);
	printf("Nb Arbres Controle: %d\n", _robiot.commande.GetNbArbres());
	printf("Consommation Totale : %f W.h\n", conso);

}

// Fonction pour déplacer et mettre à jour la position dans une direction donnée
void Controleur_Deplacement::MoveRobiot(CCompas::MOVE move)
{
	_robiot.moteur.ActiveMoteur(move); // On bouge le robot dans la direction voulue
	_currentpos = _robiot.moteur.compas.GetPosition(); // On met à jour notre position dans la classe
	_robiot.capteur.UpdatePosition(_currentpos); // On met à jour la position du capteur
	printf("Position Robot : %d , %d\n", _currentpos.x, _currentpos.y);
	
}

//Metrique : Comment Only  :  lignes 6.2 %
//                            Caractères : 43.6 %





