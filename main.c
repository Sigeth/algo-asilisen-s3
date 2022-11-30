#include <stdio.h>
#include <stdlib.h>
#include "moteur.h"
#include "sauvegarde.h"
#include "affichage.h"
#include "menu.h"


int main() {
  //test moteur
    /*
     *Création de la base de données pour le test !
     */
    piste* PisteTEST= malloc(sizeof(piste));
    avion* liste = malloc(sizeof(avion));
    liste = loadAvions(liste,"avions");
     
    PisteTEST=initPiste();
  
    PisteTEST=creerPiste(14,400,PETITE,5,liste->identifiant);

    afficheListeAvion(liste);
    affichePiste(PisteTEST);

    menu(liste,PisteTEST);
    //affichePiste(PisteTEST);
//fin test moteur
    return 0;
}