#include "Controleur_Deplacement.h"

int main()
{
	Controleur_Deplacement Contr;
}

/*Ce programme permet de contrôler les arbres choisis dans commande.txt en prenant en compte terrain.txt.
Le programme affiche bien le nombre d’arbres contrôlés, le temps du trajet et la consommation du robot.
La détection d'obstacle fonctionne mais ne permet pas toujours de trouver le chemin le plus court. 
Le test réalisé avec les 2 fichiers commande.txt et terrain.txt nous donne un temps de trajet de 2285 secondes, 
soit une distance parcouru de 960 mètres alors que dans ce cas-là, le temps optimal serais de 2238 secondes pour 940 mètres. 
Donc l’algorithme de détection d’obstacle présent dans CCapteur.cpp peut être amélioré afin de trouver le chemin le plus court à chaque fois. 
De plus, le robot n’évolue que suivant 2 axes, soit il effectue des déplacements de 10 mètres suivant x soit des déplacements de 10 mètres suivant y.
En lui faisant faire des déplacements en diagonale, on pourrait lui faire économiser environ 30 % d’énergie(il ferait 14 mètre à la place de 20).
Dans tous les cas, le résultat que nous donnera le programme sera au moins égale à la consommation réelle du robot et nous permettra d’avoir une batterie 
qui ne sera jamais sous - dimensionnée.
Après avoir réalisé les tests de validation et voyant qu’ils étaient bons, comme nous manquions de temps, nous avons pris la décision de ne pas faire de tests unitaires car le programme marche.
Afin de simplifier l'utilisation du projet, nous n'avons pas jugé utile d'envoyer seulement la version finale testée et fonctionnelle au client car nous n'avons pas de nouveau code en phase de build dans le projet, et que le code est déjà testé
*/


//Metrique : Comment Only  :  lignes 58.6 %
//                            Caractères : 93.8 %