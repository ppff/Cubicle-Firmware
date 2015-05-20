#ifndef VEILLE_H
#define VEILLE_H

#include <Arduino.h>
#include "geom.h"
#include "periph.h"
#include "haut_niveau.h"

extern unsigned long time_boutons;
extern boolean mode_veille;

extern byte nb_groupes, groupe_actuel;
extern byte nb_motifs,  motif_actuel;
extern word matrice_affichage[81];
extern word matrice_backup[81];
extern int translation_x, translation_y, translation_z;
extern boolean autoriser_affichage;

#define Tveille 480000

void reinit_veille();
void afficher_veille();
inline void check_veille()
{
  if (millis() - time_boutons > Tveille)
  {
    if (mode_veille == false)
    {
      ecrire_ligne_P(PSTR("Cubicle is waiting"), 18, true);
      ecrire_ligne_P(PSTR("Press a button"), 14, false);
      mode_veille = true;
      reinit_veille();
    }
    afficher_veille();
  }
}

#endif
