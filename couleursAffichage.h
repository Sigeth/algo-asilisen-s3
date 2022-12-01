#ifndef COULEURS
#define COULEURS

#include <stdio.h>

//Permet de supprimer tout ce qui est écrit dans le terminal
#define clrscr() printf("\033[H\033[2J")

/*
Permet de changer le style du texte dans le terminal :

Changer couleur du texte :
-30 noir
-31 rouge
-32 vert
-33 jaune
-34 bleu
-35 magenta
-36 cyan
-37 blanc

Changer la couleur de fond :
-40 noir
-41 rouge
-42 jaune
-43 vert
-44 bleu
-45 magenta
-46 cyan
-47 blanc

Haute intensité des couleurs : 1

Inverser la selection des couleurs (inverser couleur et fond) : 7

ATTENTION : à chaque utilisation de la fonction couleur(), il faut réinitialiser la couleur avec couleur("0");
*/
#define couleur(param) printf("\033[%sm", param)

#endif