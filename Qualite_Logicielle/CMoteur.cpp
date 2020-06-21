#include "CMoteur.h"
#include "CCompas.h"



CMoteur::CMoteur() : compas()
{
	
}

void CMoteur::ActiveMoteur(CCompas::MOVE move)
{
	switch (move)
	{
	case CCompas::UP :
		compas.MoveUp();
			break;
	case CCompas::DOWN:
		compas.MoveDown();
		break;
	case CCompas::LEFT:
		compas.MoveLeft();
		break;
	case CCompas::RIGHT:
		compas.MoveRight();
		break;
	default:
		break;
	}
}
