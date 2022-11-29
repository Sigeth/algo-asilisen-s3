#include <stdio.h>
#include "moteur.h"
#include "sauvegarde.h"


int main() {
  //test moteur
    /*
     *Création de la base de données pour le test !
     */
    avion* liste;
    liste = genBddRandom(liste);
    
    afficheListe(liste);
//fin test moteur
    return 0;
}