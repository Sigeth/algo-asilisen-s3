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
    printf("init fait :) ");
    piste* PisteTEST=NULL;
    listeAvion* liste = malloc(sizeof(listeAvion));
  
    liste = loadAvions(liste,"avions");
     
   // PisteTEST=initPiste();
  
    //PisteTEST=creerPiste(14,400,PETITE,5,liste);

    //maafficheListeAvion(liste);
    //affichePiste(PisteTEST);
    //int i = compteurElm(PisteTEST);
    //printf("\n OMG ON ARRETE TOUT ! IL Y A : %d",i);

    //affiche_avion();
    //menu(liste,PisteTEST);
    //affichePiste(PisteTEST);
//fin test moteur
    return 0;
}