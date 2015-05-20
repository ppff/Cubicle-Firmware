
#include "veille.h"

#define Tshort 20
#define Tlong  200
unsigned long tim = 0;
unsigned long attente = Tshort;
byte compteur = 0;

enum Etat {Chargement, Avance, Attente, Descente};
Etat etat = Chargement;

void reinit_veille()
{
  etat = Chargement;
  compteur = 0;
  attente = Tshort;
  tim = 0;
}

void afficher_veille()
{
  if (millis() - tim > attente)
  {
    switch(etat)
    {
      case Chargement :
      reinit_translation();  
      reinitialiser_matrice(matrice_affichage);
      switch(compteur)
      {
        case 0 : 
            ajouter_plan_P(matrice_affichage, 2, PSTR("000P40P40P0000"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("04000000004000"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("04000000004000"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("04000000004000"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("000P00000P0000"));
          break;
        case 1 : 
            ajouter_plan_P(matrice_affichage, 2, PSTR("000P40P40P4000"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("04000000000000"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("04000000000000"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("04000000000000"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("000P40P40P4000"));
          break;
        case 2 : 
            ajouter_plan_P(matrice_affichage, 2, PSTR("040P40P40P4000"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("040000P0004000"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("040000P0004000"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("040000P0004000"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("000P40040P0000"));
          break;
        case 3 : 
            ajouter_plan_P(matrice_affichage, 2, PSTR("04000000004000"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("04000000004000"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("040P40P40P4000"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("04000000004000"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("04000000004000"));
          break;
        case 4 : 
            ajouter_plan_P(matrice_affichage, 2, PSTR("000P40P40P0000"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("04000000004000"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("04000000004000"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("04000000004000"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("000P00000P0000"));
          break;
        case 5 : 
            ajouter_plan_P(matrice_affichage, 2, PSTR("040P40P40P4000"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("04000000000000"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("04000000000000"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("04000000000000"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("04000000000000"));
          break;
        case 6 : 
            ajouter_plan_P(matrice_affichage, 2, PSTR("040P40P40P4000"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("040000P0004000"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("040000P0004000"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("040000P0004000"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("04000000004000"));
        case 7 : 
          break;
      }
      copier_matrice(matrice_affichage, matrice_backup);
      autoriser_affichage = true;
      
      compteur = compteur+1 == 8 ? 0 : compteur+1;
      etat = Avance;
      break;
    case Avance :
      if (translation_x == 8)
      {
        etat = Attente;
      }
      else
      {
        translation_x++;
        translater();
      }
      break;
    case Attente :
      attente = Tlong;
      etat = Descente;
      break;
    case Descente :
      attente = Tshort;
      if (translation_z == -8)
      {
        etat = Chargement;
      }
      else
      {
        translation_z--;
        translater();
      }
      break;
    }
    
    tim = millis();
  }
}
