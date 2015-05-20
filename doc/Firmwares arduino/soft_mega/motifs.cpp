
#include "motifs.h"

#define NB_GROUPE_100     0
#define NB_GROUPE_110     1
#define NB_GROUPE_111     2
#define NB_GROUPE_HGD_A   21
#define NB_GROUPE_HGD_B   19
#define NB_GROUPE_HGD_C   20
#define NB_GROUPE_HGD_BCA 22
#define NB_GROUPE_HGD_GD  23
#define NB_GROUPE_NACL    14
#define NB_GROUPE_SINUS   28
#define NB_GROUPE_ELLIPSE 29
#define NB_GROUPE_ARETES1 30
#define NB_GROUPE_SEGM    32
#define NB_GROUPE_CUBE1   33

unsigned long time = 0;
#define Tfast   5
#define Tfast2  40
#define Tshort  200
#define Tmedium 600
#define Tlong   2000

void check_animations()
{
  if (groupe_actuel == NB_GROUPE_100 && motif_actuel == 1 && millis() - time > Tshort)
  {
    translation_y = translation_y+1 >= 9 ? 0 : translation_y+1;
    translater();
    time = millis();
  } 
  else if (groupe_actuel == NB_GROUPE_110 && motif_actuel == 1 && millis() - time > Tshort)
  {
    translation_x = translation_x+1 >= 4 ? -4 : translation_x+1;
    translation_y = translation_y+1 >= 4 ? -4 : translation_y+1;
    translater();
    time = millis();
  } 
  else if (groupe_actuel == NB_GROUPE_111 && motif_actuel == 1 && millis() - time > Tshort)
  {
    translation_x = translation_x+1 >= 4 ? -4 : translation_x+1;
    translation_y = translation_y+1 >= 4 ? -4 : translation_y+1;
    translation_z = translation_z+1 >= 4 ? -4 : translation_z+1;
    translater();
    time = millis();
  }   
  else if ((groupe_actuel == NB_GROUPE_HGD_A || groupe_actuel == NB_GROUPE_HGD_B || groupe_actuel == NB_GROUPE_HGD_C || groupe_actuel == NB_GROUPE_HGD_BCA) && motif_actuel > 2 && millis() - time > Tlong)
  {
    motif_actuel = motif_actuel+1 < nb_motifs ? motif_actuel+1 : 3;
    maj_motif();
    time = millis();
  }
  else if (groupe_actuel == NB_GROUPE_HGD_GD && motif_actuel > 1 && millis() - time > Tlong)
  {
    motif_actuel = motif_actuel+1 < nb_motifs ? motif_actuel+1 : 2;
    maj_motif();
    time = millis();
  }
  else if (groupe_actuel == NB_GROUPE_NACL && millis() - time > Tmedium)
  {
    motif_actuel = motif_actuel%2 == 0 ? motif_actuel+1 : motif_actuel-1;
    maj_motif();
    time = millis();
  }
  else if (groupe_actuel == NB_GROUPE_SINUS && millis() - time > Tfast)
  {
    motif_actuel = motif_actuel+1 == 16 ? 0 : motif_actuel+1;
    maj_motif();
    time = millis();
  }
  else if (groupe_actuel == NB_GROUPE_ELLIPSE && millis() - time > Tfast2)
  {
    motif_actuel = motif_actuel+1 == 8 ? 0 : motif_actuel+1;
    maj_motif();
    time = millis();
  }
  else if (groupe_actuel == NB_GROUPE_ARETES1 && millis() - time > Tfast2)
  {
    motif_actuel = motif_actuel+1 == 50 ? 0 : motif_actuel+1;
    maj_motif();
    time = millis();
  }
  else if (groupe_actuel == NB_GROUPE_SEGM && millis() - time > Tfast)
  {
    motif_actuel = motif_actuel+1 == 15 ? 0 : motif_actuel+1;
    maj_motif();
    time = millis();
  }

}
