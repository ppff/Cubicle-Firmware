
#include <SPI.h>
#include <LiquidCrystal.h>

#include "bas_niveau.h"
#include "haut_niveau.h"
#include "periph.h"
#include "geom.h"
#include "motifs.h"
#include "veille.h"

byte nb_groupes, groupe_actuel;
byte nb_motifs,  motif_actuel;
word matrice_affichage[81];
word matrice_backup[81];
int translation_x, translation_y, translation_z;
byte num;
boolean autoriser_affichage;

void setup()
{  
  init_ecran();
  init_boutons();
  
  num = 1;
  autoriser_affichage = false;
  
  delay(1000);
  
  maj_ecran_chargement();
  
  nb_groupes = nombre_groupes();
  maj_motif();

  init_affichage();
  //Serial.begin(9600); 
}

void loop()
{
  //Animations
  check_veille();
  if (!mode_veille)
    check_animations();

  //Autres
  switch (bouton_actif())
  {
    case 2 : translation_y--; translater(); break;
    case 5 : translation_y++; translater(); break;
    case 0 : translation_x++; translater(); break;
    case 1 : translation_x--; translater(); break;
    case 3 : translation_z++; translater(); break;
    case 4 : translation_z--; translater(); break;
    case 6 : groupe_actuel = groupe_actuel-1  < 0          ? nb_groupes-1     : groupe_actuel-1;  motif_actuel = 0; maj_motif(); break;
    case 7 : groupe_actuel = groupe_actuel+1  < nb_groupes ? groupe_actuel+1  : 0;                motif_actuel = 0; maj_motif(); break;
    case 8 : motif_actuel  = motif_actuel-num < 0          ? nb_motifs-1      : motif_actuel-num; maj_motif(); break;
    case 9 : motif_actuel  = motif_actuel+num < nb_motifs  ? motif_actuel+num : 0;                maj_motif(); break;
    case 10 :
    case 11 :
    case 12 :
    case 13 :
    case 14 :
    case 15 :
    case 16 :
    case 17 :
    case 18 :
    case 19 : maj_motif(); break;
  }
  
  afficher_matrice(matrice_affichage);
}
