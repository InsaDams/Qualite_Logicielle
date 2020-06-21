#include "Robiot.h"
#include <cmath>
#include <iostream>
using namespace std;


Robiot::Robiot(string pathfile, string pathfile2) : path1(pathfile),path2(pathfile2), moteur(),batterie(),commande(pathfile2)
{
	
}

