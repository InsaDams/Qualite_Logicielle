#pragma once
#include "CCompas.h"
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
//V2
using namespace std;

class CCapteur
{
public:
	enum DIR { UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3 };
	struct bordure
	{
		bool state;
		DIR dir;
	};

	struct obstacle
	{
		bool state;
		DIR dir;
	};

	obstacle obs;
	bordure bor;

	CCapteur(string path);
	void UpdatePosition(CCompas::Pos point);
	CCompas::Pos GetStart();
	bool Getarbre();
	CCapteur::bordure Getbordure();
	CCapteur::obstacle Getobstacle();

private:
	void ReadTerrain();
	void Filltab(string ligne, int iterator);
	string _path;
	std::vector<vector<char>> _myList;

	CCompas::Pos _currenttree;
	int iterator;
	CCompas::Pos position;

	bool arbre;

	


};

