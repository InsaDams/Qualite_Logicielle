#include "Controleur_Deplacement.h"
#pragma once

//V1

class CCompas
{
private:
	int pos_x;
	int pos_y;

public:	
	void MoveRight();
	void MoveLeft();
	void MoveUp();
	void MoveDown();

	Controleur_Deplacement::Pos GetPosition();

	CCompas();



};

