#include <malloc.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "sauvegarde.h"

avion* genBddRandom(avion* liste) {
    srand(time(NULL));

    for (int i=0;i<50;i++) {
        char* id = malloc(sizeof(char) * 10);
        snprintf(id, 10, "PGN-%02d", i);

        printf("Nom de l'avion : %s\n", id);
        avion* newAvion = creerAvion(id,rand()%3,rand()%1,rand()%500);


        if (i == 0) {
            liste = newAvion;
        } else {
            liste=enfile(liste,newAvion);
        }
    }
    return liste;
}

int saveAvions(avion* liste, char* nomFichier) {
    FILE* bdd = fopen(nomFichier, "wb");

    avion* tmp = liste;
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

avion* loadAvions(avion* liste, char* nomFichier) {
    FILE* bdd = fopen(nomFichier, "rb");
    avion* prev = NULL;
    while(!feof(bdd)) {
        avion* tmp = malloc(sizeof(avion));
        fread(tmp, sizeof(avion), 1, bdd);
        if (!strcmp(tmp->identifiant, "")) {
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
