#include "CCapteur.h"

CCapteur::CCapteur(string path) : _path(path), position(CCompas::Pos{0,0})
{
	iterator = -1;
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

	if (_myList[position.x][position.y]=='O')
	{ 
		arbre = true;
	}
	else if (_myList[position.x][position.y] == '|')
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

	else if (_myList[position.x][position.y] == '-')
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

	if (_myList[position.x-1][position.y] == 'X')
	{
		obs.dir = CCapteur::LEFT;
		obs.state = true;
	}
	if (_myList[position.x +1][position.y] == 'X')
	{
		obs.dir = CCapteur::RIGHT;
		obs.state = true;
	}
	if (_myList[position.x][position.y-1] == 'X')
	{
		obs.dir = CCapteur::UP;
		obs.state = true;
	}
	if (_myList[position.x][position.y+1] == 'X')
	{
		obs.dir = CCapteur::DOWN;
		obs.state = true;
	}

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
	for (int i = 0; i < ligne.size() ; i++)
	{
		_myList[iterator].push_back(ligne[i]);
	}
}

