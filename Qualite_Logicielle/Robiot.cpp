#include "Robiot.h"
#include <cmath>
#include <iostream>
using namespace std;

//Permet d'interfacer tous les composants du robot
Robiot::Robiot(string pathfile, string pathfile2) : path1(pathfile),path2(pathfile2), moteur(),batterie(),capteur(pathfile),commande(pathfile2)
{
	
}

