#include <stdio.h>
#include <stdlib.h>
#include "moteur.h"
#include "sauvegarde.h"
#include "menu.h"


int main() {
  //test moteur
    /*
     *Création de la base de données pour le test !
     */
    piste* PisteTEST= malloc(sizeof(piste));
    avion* liste = malloc(sizeof(avion));
    liste = loadAvions(liste,"bdd");
    
    PisteTEST=initPiste();
    PisteTEST=creerPiste(14,400,PETITE,5,liste);

    afficheListe(liste);
    affichePiste(PisteTEST);

    menu(liste,PisteTEST);
//fin test moteur
    return 0;
}