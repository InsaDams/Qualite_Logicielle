#include "CCompas.h"

//Affecte les positions de départs x et y
void CCompas::SetStart(Pos start)
{
	pos_x = start.x;
	pos_y = start.y;
}

//Déplace le robot d'une case vers la droite
void CCompas::MoveRight()
{
	pos_x = pos_x + 1;
}

//Déplace le robot d'une case vers la gauche
void CCompas::MoveLeft()
{
	pos_x = pos_x - 1;

}

//Déplace le robot d'une case vers le haut
void CCompas::MoveUp()
{
	pos_y = pos_y -1;
}

//Déplace le robot d'une case vers le bas
void CCompas::MoveDown()
{
	pos_y = pos_y + 1;
}

//Retourne la position du robot à travers un point de coordonnés {x,y}
CCompas::Pos CCompas::GetPosition()
{
	CCompas::Pos point = {pos_x,pos_y};
	return point;
}

CCompas::CCompas()
{
	pos_x = 0;
	pos_y = 0;
}

//Metrique : Comment Only  :  lignes 13.0 %
//                            Caractères :41.6 %