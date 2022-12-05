#include <malloc.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "sauvegarde.h"

listeAvion* genBddRandom(listeAvion* liste) {
    srand(time(NULL));

    for (int i=0;i<50;i++) {
        char* id = malloc(sizeof(char) * 10);
        snprintf(id, 10, "PGN-%02d", i);

        printf("Nom de l'avion : %s\n", id);
        TypeAvion avionType = 1 + rand()%3;
        avion* newAvion;
        switch(avionType) {
            case AVIONLEGER:
                newAvion = creerAvion(id,avionType,rand()%2, 1 + rand()%4);
                break;
            case AVIONAFFAIRE:
                newAvion = creerAvion(id,avionType,rand()%2, 2 + rand()%14);
                break;
            case AVIONLIGNE:
                newAvion = creerAvion(id,avionType,rand()%2, 250 + rand()%850);
                break;
            default:
                printf("ambiance étrange, l'avion est de type undefined quoi donc bon bizarre quoi......\n");
                break;
        }

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
        fwrite(tmp->Elm, sizeof(avion), 1, bdd);

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
        tmp->Elm = malloc(sizeof(avion));
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

piste* genPistes(piste* listePistes, listeAvion* listeAvions) {

    srand(time(NULL));

    piste* parking = creerPiste(0, 0, PARKING, 30,NULL);
    piste* petite = creerPiste(1, 100, PETITE, 2,NULL);
    parking->suiv = petite;
    piste* moy = creerPiste(2, 250, MOYENNE, 4, NULL);
    petite->suiv = moy;
    moy->prec = petite;
    piste* grande = creerPiste(3, 500, GRANDE, 10, NULL);
    moy->suiv = grande;
    grande->prec = moy;

    while(listeAvions != NULL) {
        if (listeAvions->Elm->etat == 0) {
            bool available = false;
            while (!available) {
                TypePiste pisteAvion = rand() % 4;
                switch (pisteAvion) {
                    case PARKING:
                        if (cptElement(parking) >= parking->nbAvionsMax) {
                            available = false;
                        } else {
                            parking->liste = enfile(parking->liste, listeAvions->Elm);
                            available = true;
                        }
                        break;
                    case PETITE:
                        if (cptElement(petite) >= petite->nbAvionsMax) {
                            available = false;
                        } else {
                            petite->liste = enfile(petite->liste, listeAvions->Elm);
                            available = true;
                        }
                        break;
                    case MOYENNE:
                        if (cptElement(moy) >= moy->nbAvionsMax) {
                            available = false;
                        } else {
                            moy->liste = enfile(moy->liste, listeAvions->Elm);
                            available = true;
                        }
                        break;
                    case GRANDE:
                        if (cptElement(grande) >= grande->nbAvionsMax) {
                            available = false;
                        } else {
                            grande->liste = enfile(grande->liste, listeAvions->Elm);
                            available = true;
                        }
                        break;
                }
            }
        }
        listeAvions=listeAvions->suiv;
    }

    return parking;
}

int savePistes(piste* liste, char* nomFichier) {
    FILE* bdd = fopen(nomFichier, "wb");

    piste* tmp = liste;
    int i = 0;
    while(tmp != NULL) {
        fwrite(tmp, sizeof(piste), 1, bdd);

        tmp = tmp->suiv;
        i++;
    }

    fclose(bdd);

    if(i == 0) {
        printf("Une liste vide ne peut être sauvegardée.\n");
        return 0;
    } else {
        printf("Pistes sauvegardées\n");
        return 1;
    }
}

piste* loadPistes(piste* liste, char* nomFichier) {
    FILE *bdd = fopen(nomFichier, "rb");
    piste *prev = NULL;
    while (!feof(bdd)) {
        piste *tmp = malloc(sizeof(piste));
        fread(tmp, sizeof(piste), 1, bdd);
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
