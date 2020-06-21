#include <string>
#include "CCompas.h"
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;
#pragma once

class CCommande
{
public:
	// Constructeurs
	CCommande(string path);
	CCompas::Pos GetNextPos();

private:
	void ReadCommand();
	void AddPos(string ligne);
	
	string _path;
	std::vector<CCompas::Pos> _myList;
	CCompas::Pos _currentpos;
	int iterator;
	//Accesseurs et mutateurs


};

