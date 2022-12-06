#include <stdio.h>
#include <stdlib.h>
#include "moteur.h"
#include "sauvegarde.h"
#include "affichage.h"
#include "menu.h"


int main() {
  
    piste* pistes=NULL;
    listeAvion* liste = malloc(sizeof(listeAvion));
    liste = loadAvions(liste,"saves/globalAvions.save");
    pistes = loadPistes(pistes, "saves/pistes.save");   
    
    menu(liste,pistes);

    return 0;
}