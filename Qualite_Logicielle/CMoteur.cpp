#include "CMoteur.h"
#include "CCompas.h"


CMoteur::CMoteur() : compas()
{
	_distance = 0;
}

//R�alise un d�placement du robot de 1 case vers le haut, vers le bas, vers la droite ou vers la gauche
void CMoteur::ActiveMoteur(CCompas::MOVE move)
{
	switch (move)
	{
	case CCompas::UP :
		compas.MoveUp(); //d�placement vers le haut
		break;
	case CCompas::DOWN:
		compas.MoveDown(); //d�placement vers le bas
		break;
	case CCompas::LEFT:
		compas.MoveLeft(); // d�placement vers la gauche
		break;
	case CCompas::RIGHT:
		compas.MoveRight(); //d�placement vers la droite
		break;
	default:
		break;
	}
	_distance += 10; //Il faut consid�rer une �chelle d'une case vaut 10 m�tres sur le terrain.
}

int CMoteur::GetDistance()
{
	return _distance;
}

//Metrique : Comment Only  :  lignes 2.8 %
//                            Caract�res :40 %