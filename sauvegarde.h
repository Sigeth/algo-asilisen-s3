#ifndef ALGO_ASILISEN_S3_SAUVEGARDE_H
#define ALGO_ASILISEN_S3_SAUVEGARDE_H

#include "moteur.h"

listeAvion* genBddRandom(listeAvion* liste);
int saveAvions(listeAvion* liste, char* nomFichier) ;
listeAvion* loadAvions(listeAvion* liste, char* nomFichier);

#endif
