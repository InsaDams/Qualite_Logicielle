#include "CCapteur.h"

CCapteur::CCapteur(string path) : _path(path), position(CCompas::Pos{0,0})
{
	ReadTerrain();
}


//Permet de lire le fichier terrain.txt ligne par ligne
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
			iterator++; //incrémentation de l'iterator pour la création du terrain
		}
		
	}
	else
	{
		cout << "ERREUR: Impossible d'ouvrir le fichier de commande" << endl;
	}

}

//Fonction qui met à jour la position du capteur
void CCapteur::UpdatePosition(CCompas::Pos point)
{
	position = point;
	arbre = false; //On initialise arbre à false
	bor = CCapteur::bordure{false,CCapteur::UP}; //On initialise bordure à false
	obs = CCapteur::obstacle{ false,CCapteur::UP }; //On initialise l'obstacle à False

	if (_myList[position.y][position.x] != 'D') //Si la position actuelle n'est pas le point de départ, on entre dans la boucle
	{
		if (_myList[position.y][position.x] == 'O') //Indique si on se trouve sur un arbre
		{
			arbre = true;
		}
		else if (_myList[position.y][position.x] == '|') //mise à jour du capteur de bordure si on se trouve sur la bordure gauche ou droite
		{
			if (position.x == 0)
			{
				bor.dir = CCapteur::LEFT; //Si on se trouve en position x = 0, on se trouve forcement sur la bordure gauche
			}
			else
			{
				bor.dir = CCapteur::RIGHT; //Sinon on se trouve sur la bordure droite
			}
			bor.state = true;
		}

		else if (_myList[position.y][position.x] == '-') //mise à jour du capteur de bordure si on se trouve sur la bordure gauche ou droite
		{
			if (position.y == 0)
			{
				bor.dir = CCapteur::UP; //Si on se trouve en position y = 0, on se trouve forcement sur la bordure haute
			}
			else
			{
				bor.dir = CCapteur::DOWN; //Sinon on se trouve forcement sur la bordure basse
			}
			bor.state = true;
		}

		if (!(bor.state && bor.dir == CCapteur::LEFT) && _myList[position.y][position.x - 1] == 'X') //mise à jour du capteur d'obstacles si un obstacle se trouve à notre gauche
		{
			obs.dir = CCapteur::LEFT;
			obs.state = true;
		}
		if (!(bor.state && bor.dir == CCapteur::RIGHT) && _myList[position.y][position.x + 1] == 'X') //mise à jour du capteur d'obstacles si un obstacle se trouve à notre droite
		{
			obs.dir = CCapteur::RIGHT;
			obs.state = true;
		}
		if (!(bor.state && bor.dir == CCapteur::UP) && _myList[position.y - 1][position.x] == 'X') //mise à jour du capteur d'obstacles si un obstacle se trouve juste au dessus
		{
			obs.dir = CCapteur::UP;
			obs.state = true;
		}
		if (!(bor.state && bor.dir == CCapteur::DOWN) && _myList[position.y + 1][position.x] == 'X') //mise à jour  du capteur d'obstacles si une bordure se trouve juste en dessous
		{
			obs.dir = CCapteur::DOWN;
			obs.state = true;
		}
	}
	

}

//Trouver le point de départ
CCompas::Pos CCapteur::GetStart()
{
	for (int i = 0; i <= iterator; i++) //parcoure l'entièreté du terrain
	{
		for (int j = 0; j < _myList[i].size(); j++) 
		{
			if (_myList[i][j]=='D')
			{
				return CCompas::Pos{ j,i }; //Une fois que l'on trouve D, on arrete de parcourir le terrain, et on renvoie la position de D
			}
		}
	}
	return CCompas::Pos{ 0,0 }; //Si on ne trouve pas D, la position de base sera 0,0
}

//Retourne arbre si le capteur détecteur un arbre
bool CCapteur::Getarbre()
{
	return arbre;
}

//retourne bordure si le capteur détecte une bordure
CCapteur::bordure CCapteur::Getbordure()
{
	return bor;
}

//retourne obstacle si le capteur détecte un obstacle
CCapteur::obstacle CCapteur::Getobstacle()
{
	return obs;
}

//Permet de remplir le vecteur correspondant au terrain
void CCapteur::Filltab(string ligne,int iterator)
{
	_myList.push_back(vector<char>(1,ligne[0]));
	for (int i = 1; i < ligne.size() ; i++)
	{
		_myList[iterator].push_back(ligne[i]);
	}
}



