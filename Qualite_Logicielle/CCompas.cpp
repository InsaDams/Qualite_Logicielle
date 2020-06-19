#include "CCompas.h"


void CCompas::MoveRight()
{
	pos_x = pos_x + 1;
}

void CCompas::MoveLeft()
{
	pos_x = pos_x - 1;

}

void CCompas::MoveUp()
{
	pos_y = pos_y -1;
}

void CCompas::MoveDown()
{
	pos_y = pos_y + 1;
}

Controleur_Deplacement::Pos CCompas::GetPosition()
{
	Controleur_Deplacement::Pos point = {pos_x,pos_y};
	return point;
}

CCompas::CCompas()
{
	pos_x = 0;
	pos_y = 0;
}