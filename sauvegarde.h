#ifndef ALGO_ASILISEN_S3_SAUVEGARDE_H
#define ALGO_ASILISEN_S3_SAUVEGARDE_H

#include "moteur.h"

avion* genBddRandom(avion* liste);
int saveAvions(avion* liste, char* nomFichier);
avion* loadAvions(avion* liste, char* nomFichier);

#endif
