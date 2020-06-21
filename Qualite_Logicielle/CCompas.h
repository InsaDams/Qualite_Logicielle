//#include "Controleur_Deplacement.h"
#pragma once

//V1

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
	void MoveRight();
	void MoveLeft();
	void MoveUp();
	void MoveDown();
	enum MOVE { UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3 };
	Pos GetPosition();
	
	CCompas();



};

