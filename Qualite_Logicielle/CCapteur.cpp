#include "CCapteur.h"

CCapteur::CCapteur(string path) : _path(path), position(CCompas::Pos{0,0})
{
	ReadTerrain();
}

void CCapteur::ReadTerrain()
{
	ifstream stream(_path);
	int iterator = 0;
	if (stream)
	{
		string ligne;

		while (getline(stream,ligne))
		{
			Filltab(ligne, iterator);
			iterator++;
		}
		
	}
	else
	{
		cout << "ERREUR: Impossible d'ouvrir le fichier de commande" << endl;
	}

}

void CCapteur::UpdatePosition(CCompas::Pos point)
{
	position = point;
	arbre = false;
	bor = CCapteur::bordure{false,CCapteur::UP};
	obs = CCapteur::obstacle{ false,CCapteur::UP };
	if (_myList[position.y][position.x] != 'D')
	{
		if (_myList[position.y][position.x] == 'O')
		{
			arbre = true;
		}
		else if (_myList[position.y][position.x] == '|')
		{
			if (position.x == 0)
			{
				bor.dir = CCapteur::LEFT;
			}
			else
			{
				bor.dir = CCapteur::RIGHT;
			}
			bor.state = true;
		}

		else if (_myList[position.y][position.x] == '-')
		{
			if (position.y == 0)
			{
				bor.dir = CCapteur::UP;
			}
			else
			{
				bor.dir = CCapteur::DOWN;
			}
			bor.state = true;
		}

		if (!(bor.state && bor.dir == CCapteur::LEFT) && _myList[position.y][position.x - 1] == 'X')
		{
			obs.dir = CCapteur::LEFT;
			obs.state = true;
		}
		if (!(bor.state && bor.dir == CCapteur::RIGHT) && _myList[position.y][position.x + 1] == 'X')
		{
			obs.dir = CCapteur::RIGHT;
			obs.state = true;
		}
		if (!(bor.state && bor.dir == CCapteur::UP) && _myList[position.y - 1][position.x] == 'X')
		{
			obs.dir = CCapteur::UP;
			obs.state = true;
		}
		if (!(bor.state && bor.dir == CCapteur::DOWN) && _myList[position.y + 1][position.x] == 'X')
		{
			obs.dir = CCapteur::DOWN;
			obs.state = true;
		}
	}
	

}

CCompas::Pos CCapteur::GetStart()
{
	for (int i = 0; i <= iterator; i++)
	{
		for (int j = 0; j < _myList[i].size(); j++)
		{
			if (_myList[i][j]=='D')
			{
				return CCompas::Pos{ j,i };
			}
		}
	}
	return CCompas::Pos{ 0,0 };
}

bool CCapteur::Getarbre()
{
	return arbre;
}

CCapteur::bordure CCapteur::Getbordure()
{
	return bor;
}

CCapteur::obstacle CCapteur::Getobstacle()
{
	return obs;
}

void CCapteur::Filltab(string ligne,int iterator)
{
	_myList.push_back(vector<char>(1,ligne[0]));
	for (int i = 1; i < ligne.size() ; i++)
	{
		_myList[iterator].push_back(ligne[i]);
	}
}



