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
  
    piste* PisteTEST=NULL;
    listeAvion* liste = malloc(sizeof(listeAvion));
    liste = loadAvions(liste,"saves/globalAvions.save");

    PisteTEST=initPiste();
    PisteTEST=creerPiste(14,400,PETITE,5,liste);


    /*avion* New=NULL;
    New=initAvion(New);
    New=creerAvion("omg",0,0,150);
    
    liste=enfile(liste,New);*/
    
    /*
    afficheListeAvion(liste);
    liste->Elm->etat=1;
    int  i= decolle(liste->Elm,PisteTEST);
    afficheListeAvion(liste);
    */
   
    
    //affichePiste(PisteTEST);
    //int i = compteurElm(PisteTEST);
    //printf("\n OMG ON ARRETE TOUT ! IL Y A : %d",i);

    //affiche_avion();

    menu(liste,PisteTEST);
    //affichePiste(PisteTEST);
//fin test moteur
   // animationAvion();

    //genPistes(PisteTEST, liste);
    return 0;
}