#include "CCommande.h"


//Initialise l'initiator à 0, et permettra de lire la première ligne de notre fichier .txt
CCommande::CCommande(string path) : _path(path)
{
	iterator = 0;
	ReadCommand();
}

//Retourne la prochaine position à controler
CCompas::Pos CCommande::GetNextPos()
{
	if (iterator < _myList.size()) //Tant qu'il reste des arbres à controler, on passe à l'arbre suivant
	{
		
		_currentpos = _myList[iterator];
		iterator++;
	}
	else //Sinon la prochaine position devient la position de départ
	{
		iterator = -1;
		_currentpos = CCompas::Pos{ 0,0 };
	}
	return _currentpos;
}

//Retourne le nombre d'arbres à controler
int CCommande::GetNbArbres()
{
	return _myList.size();
}

//Permet de lire le fichier commande.txt ligne par ligne
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

//Ajouter dans la liste les arbres à controler
void CCommande::AddPos(string ligne)
{
	int pos_x, pos_y;
	vector<int> array;
	stringstream ss(ligne); //permet de séparer les coordonnées en x et en y
	int temp;
	while (ss >> temp)
		array.push_back(temp); //liste temporaire contenant les positions en x et y

	
		pos_x = array[0];
		pos_y = array[1];
		_myList.push_back(CCompas::Pos{ pos_x, pos_y });
	
	
}
