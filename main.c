#include <stdio.h>
#include "moteur.h"
#include "sauvegarde.h"
#include <stdlib.h>

int main() {
  //test moteur
    /*
     *Création de la base de données pour le test !
     */
    avion* liste = malloc(sizeof(avion));
    liste = loadAvions(liste,"bdd");
    
    afficheListe(liste);
//fin test moteur
    return 0;
}