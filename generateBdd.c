#include <stdio.h>
#include <malloc.h>
#include "sauvegarde.h"
#include "moteur.h"
#include "affichage.h"

int main() {
    listeAvion* listeAvions = malloc(sizeof(listeAvion));
    listeAvions = genBddRandom(listeAvions);
    piste* pistes = NULL;
    pistes = genPistes(pistes, listeAvions);

    afficheListeAvion(listeAvions);
    affichePisteAvion(pistes);

    piste* tmp = pistes;
    while (tmp != NULL) {
        printf("Avions de la piste n°%d :\n", tmp->numPiste);
        afficheListeAvion(tmp->liste);
        tmp = tmp->suiv;
    }

    saveAvions(listeAvions, "saves/globalAvions.save");
    savePistes(pistes, "saves/pistes.save");

    return 0;
}