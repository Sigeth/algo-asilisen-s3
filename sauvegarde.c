#include <malloc.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "sauvegarde.h"

listeAvion* genBddRandom(listeAvion* liste) {
    srand(time(NULL));

    for (int i=0;i<50;i++) {
        char* id = malloc(sizeof(char) * 10);
        snprintf(id, 10, "PGN-%02d", i);

        printf("Nom de l'avion : %s\n", id);
        avion* newAvion = creerAvion(id,rand()%3,rand()%1,rand()%500);

        if (i == 0) {
            liste->Elm = newAvion;
        } else {
            liste=enfile(liste,newAvion);
        }
    }
    return liste;
}

int saveAvions(listeAvion* liste, char* nomFichier) {
    FILE* bdd = fopen(nomFichier, "wb");

    listeAvion* tmp = liste;
    int i = 0;
    while(tmp != NULL) {
        fwrite(tmp, sizeof(avion), 1, bdd);

        tmp = tmp->suiv;
        i++;
    }

    fclose(bdd);

    if(i == 0) {
        printf("Une liste vide ne peut être sauvegardée.\n");
        return 0;
    } else {
        printf("Liste sauvegardée\n");
        return 1;
    }
}

listeAvion* loadAvions(listeAvion* liste, char* nomFichier) {
    FILE* bdd = fopen(nomFichier, "rb");
    listeAvion* prev = NULL;
    while(!feof(bdd)) {
        listeAvion* tmp = malloc(sizeof(listeAvion));
        tmp=initListe(tmp);
        fread(tmp->Elm, sizeof(avion), 1, bdd);
        if (!strcmp(tmp->Elm->identifiant, "")) {
            break;
        }
        if (prev == NULL) {
            liste = tmp;
        } else {
            prev->suiv = tmp;
        }
        tmp->prec = prev;
        prev = tmp;
    }

    return liste;
}
