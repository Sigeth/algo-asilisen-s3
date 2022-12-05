#ifndef ALGO_ASILISEN_S3_SAUVEGARDE_H
#define ALGO_ASILISEN_S3_SAUVEGARDE_H

#include "moteur.h"

listeAvion* genBddRandom(listeAvion* liste);
int saveAvions(listeAvion* liste, char* nomFichier) ;
listeAvion* loadAvions(listeAvion* liste, char* nomFichier);
piste* genPistes(piste* listePistes, listeAvion* listeAvions);
int savePistes(piste* liste, char* nomFichier);
piste* loadPistes(piste* liste, char* nomFichier);

#endif
