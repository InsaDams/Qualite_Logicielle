//#include "Controleur_Deplacement.h"
#pragma once

//V3

class CCompas
{
private:
	int pos_x;
	int pos_y;

public:	
	struct Pos
	{
		int x; // Abscisses
		int y; // Ordonn�es
	};

	void SetStart(Pos start);

	void MoveRight();
	void MoveLeft();
	void MoveUp();
	void MoveDown();

	//creation du type de variable MOVE, dont les valeurs possibles sont limit�es � celles de l'�num�ration.

	enum MOVE { UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3 };

	Pos GetPosition();
	
	CCompas();



};

