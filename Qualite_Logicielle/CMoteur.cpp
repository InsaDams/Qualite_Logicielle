#include "CMoteur.h"
#include "CCompas.h"



CMoteur::CMoteur() : compas()
{
	
}

void CMoteur::ActiveMoteur(Controleur_Deplacement::MOVE move)
{
	switch (move)
	{
	case Controleur_Deplacement::UP :
		compas.MoveUp();
			break;
	case Controleur_Deplacement::DOWN:
		compas.MoveDown();
		break;
	case Controleur_Deplacement::LEFT:
		compas.MoveLeft();
		break;
	case Controleur_Deplacement::RIGHT:
		compas.MoveRight();
		break;
	default:
		break;
	}
}
