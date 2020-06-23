#include "CMoteur.h"
#include "CCompas.h"



CMoteur::CMoteur() : compas()
{
	_distance = 0;
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
	_distance += 10;
}

int CMoteur::GetDistance()
{
	return _distance;
}
