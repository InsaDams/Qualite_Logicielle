#include "CCommande.h"



CCommande::CCommande(string path) : _path(path)
{
	iterator = -1;
	ReadCommand();
}

CCompas::Pos CCommande::GetNextPos()
{
	if (iterator < _myList.size())
	{
		iterator++;
		_currentpos = _myList[iterator];
	}
	else
	{
		iterator = -1;
		_currentpos = CCompas::Pos{ 0,0 };
	}
	return _currentpos;
}

int CCommande::GetNbArbres()
{
	return _myList.size();
}

void CCommande::ReadCommand()
{
	
	ifstream stream(_path);
	if (stream)
	{
		string ligne; 

		while (getline(stream, ligne))
		{
			AddPos(ligne);
			
		}
	}
	else
	{
		cout << "ERREUR: Impossible d'ouvrir le fichier de commande" << endl;
	}
}

void CCommande::AddPos(string ligne)
{
	int pos_x, pos_y;
	vector<int> array;
	stringstream ss(ligne);
	int temp;
	while (ss >> temp)
		array.push_back(temp);

	
		pos_x = array[0];
		pos_y = array[1];
		_myList.push_back(CCompas::Pos{ pos_x, pos_y });
	
	
}
