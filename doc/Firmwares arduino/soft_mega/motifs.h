#ifndef MOTIFS_H
#define MOTIFS_H

#include <Arduino.h>
#include "geom.h"
#include "periph.h"

extern byte nb_groupes, groupe_actuel;
extern byte nb_motifs,  motif_actuel;
extern word matrice_affichage[81];
extern word matrice_backup[81];
extern int translation_x, translation_y, translation_z;
extern byte num;
extern boolean autoriser_affichage;

void check_animations();
byte nombre_groupes();
void maj_motif();

#endif
