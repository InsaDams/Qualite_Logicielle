#include "CMoteur.h"
#include "CCompas.h"


CMoteur::CMoteur() : compas()
{
	_distance = 0;
}

//Réalise un déplacement du robot de 1 case vers le haut, vers le bas, vers la droite ou vers la gauche
void CMoteur::ActiveMoteur(CCompas::MOVE move)
{
	switch (move)
	{
	case CCompas::UP :
		compas.MoveUp(); //déplacement vers le haut
		break;
	case CCompas::DOWN:
		compas.MoveDown(); //déplacement vers le bas
		break;
	case CCompas::LEFT:
		compas.MoveLeft(); // déplacement vers la gauche
		break;
	case CCompas::RIGHT:
		compas.MoveRight(); //déplacement vers la droite
		break;
	default:
		break;
	}
	_distance += 10; //Il faut considérer une échelle d'une case vaut 10 mètres sur le terrain.
}

int CMoteur::GetDistance()
{
	return _distance;
}
