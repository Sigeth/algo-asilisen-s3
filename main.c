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
  
    piste* pistes=NULL;
    listeAvion* liste = malloc(sizeof(listeAvion));
    liste = loadAvions(liste,"saves/globalAvions.save");
    pistes = loadPistes(pistes, "saves/pistes.save");   

    int i  = AvionInListe(pistes,liste->Elm);
    printf("Ok : i  = %d\n",i);
     piste* pisteTest= RecherchePiste(pistes,liste->suiv->suiv->suiv->suiv->suiv->Elm);
     if(pisteTest != NULL ){
      printf("omg piste trouvé : N° :%d",pisteTest->numPiste);
     } else {
      printf("avion en vol ");
    }
    afficheListeAvion(pisteTest->liste);
    deplace(liste->suiv->suiv->suiv->suiv->suiv->Elm,pisteTest,pisteTest->suiv);
    printf("omg l'avion vion vion c'est %s",liste->suiv->suiv->suiv->suiv->suiv->Elm->identifiant);
    afficheListeAvion(pisteTest->liste);
    printf("\n");
    afficheListeAvion(pisteTest->suiv->liste);
  // menu(liste,pistes);



  // menu(liste,pistes);
    //affichePiste(PisteTEST);
//fin test moteur
   // animationAvion();
    return 0;
}