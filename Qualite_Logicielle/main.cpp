#include "Controleur_Deplacement.h"

int main()
{
	Controleur_Deplacement Contr;
}

/*Ce programme permet de contr�ler les arbres choisis dans commande.txt en prenant en compte terrain.txt.
Le programme affiche bien le nombre d�arbres contr�l�s, le temps du trajet et la consommation du robot.
La d�tection d'obstacle fonctionne mais ne permet pas toujours de trouver le chemin le plus court. 
Le test r�alis� avec les 2 fichiers commande.txt et terrain.txt nous donne un temps de trajet de 2285 secondes, 
soit une distance parcouru de 960 m�tres alors que dans ce cas-l�, le temps optimal serais de 2238 secondes pour 940 m�tres. 
Donc l�algorithme de d�tection d�obstacle pr�sent dans CCapteur.cpp peut �tre am�lior� afin de trouver le chemin le plus court � chaque fois. 
De plus, le robot n��volue que suivant 2 axes, soit il effectue des d�placements de 10 m�tres suivant x soit des d�placements de 10 m�tres suivant y.
En lui faisant faire des d�placements en diagonale, on pourrait lui faire �conomiser environ 30 % d��nergie(il ferait 14 m�tre � la place de 20).
Dans tous les cas, le r�sultat que nous donnera le programme sera au moins �gale � la consommation r�elle du robot et nous permettra d�avoir une batterie 
qui ne sera jamais sous - dimensionn�e.
Apr�s avoir r�alis� les tests de validation et voyant qu�ils �taient bons, comme nous manquions de temps, nous avons pris la d�cision de ne pas faire de tests unitaires car le programme marche.
Afin de simplifier l'utilisation du projet, nous n'avons pas jug� utile d'envoyer seulement la version finale test�e et fonctionnelle au client car nous n'avons pas de nouveau code en phase de build dans le projet, et que le code est d�j� test�
*/


//Metrique : Comment Only  :  lignes 58.6 %
//                            Caract�res : 93.8 %