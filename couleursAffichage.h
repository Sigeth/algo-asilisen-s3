#ifndef COULEURS
#define COULEURS

#include <stdio.h>

/*function clrscr(), clear the terminal
 */
#define clrscr() printf("\033[H\033[2J")

/*function couleur, add style to the text printed in the terminal
 *@param param, int that corresponds to the desired color
 *more details below

Change text color :
-30 noir
-31 rouge
-32 vert
-33 jaune
-34 bleu
-35 magenta
-36 cyan
-37 blanc

Change background color :
-40 noir
-41 rouge
-42 jaune
-43 vert
-44 bleu
-45 magenta
-46 cyan
-47 blanc

High color intensity : 1

Invert color selection (invert text color and background) : 7

WARNING: each time the color() function is used, the color must be reset with color("0");
*/
#define couleur(param) printf("\033[%sm", param)

#endif