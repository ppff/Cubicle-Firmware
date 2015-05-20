#ifndef GEOM_H
#define GEOM_H

#include "haut_niveau.h"

//num appartient à [0 ; 9*9*9-1 = 728]

extern word matrice_affichage[81];
extern word matrice_backup[81];
extern int translation_x, translation_y, translation_z;
extern boolean autoriser_affichage;

inline boolean est_dans_le_cube(int const& coor)
{
  return coor >= 0 && coor < 9;
}

//Récupérer l'abscisse à partir du numéro de led
inline unsigned int num_vers_x(unsigned int const& num)
{
  return num < 729 ? num%9 : -1;
}

//Récupérer l'ordonnée à partir du numéro de led
inline unsigned int num_vers_y(unsigned int const& num)
{
  return num < 729 ? (num/9)%9 : -1;
}

//Récupérer la cote à partir du numéro de led
inline unsigned int num_vers_z(unsigned int const& num)
{
  return num < 729 ? (num/9)/9 : -1;
}

//Récupérer les coordonnées depuis le numéro de led
inline void num_vers_coord(unsigned int const& num, int & x, int & y, int & z)
{
  x = num_vers_x(num);
  y = num_vers_y(num);
  z = num_vers_z(num);
}

//Récupérer le numéro de led à partir des coordonnées (attention : vaut -1 si les coordonnées sont hors du cube || attention bis : renvoie -1 si une des coordonnées est hors du cube)
inline int coord_vers_num(int const& x, int const& y, int const& z)
{
  if (est_dans_le_cube(x) && est_dans_le_cube(y) && est_dans_le_cube(z))
  {
    unsigned int tmp_num = x + y*9 + z*9*9;
    return tmp_num < 729 ? tmp_num : -1;
  }
  //else
    return -1;
}

//Ajouter 1 en abscisse au numéro
inline int num_x_plus(unsigned int const& num)
{
  return coord_vers_num(num_vers_x(num)+1, num_vers_y(num), num_vers_z(num));
}

//Enlever 1 en abscisse au numéro
inline int num_x_moins(unsigned int const& num)
{
  return coord_vers_num(num_vers_x(num)-1, num_vers_y(num), num_vers_z(num));
}

//Ajouter 1 en ordonnée au numéro
inline int num_y_plus(unsigned int const& num)
{
  return coord_vers_num(num_vers_x(num), num_vers_y(num)+1, num_vers_z(num));
}

//Enlever 1 en ordonnée au numéro
inline int num_y_moins(unsigned int const& num)
{
  return coord_vers_num(num_vers_x(num), num_vers_y(num)-1, num_vers_z(num));
}

//Ajouter 1 en cote au numéro
inline int num_z_plus(unsigned int const& num)
{
  return coord_vers_num(num_vers_x(num), num_vers_y(num), num_vers_z(num)+1);
}

//Enlever 1 en cote au numéro
inline int num_z_moins(unsigned int const& num)
{
  return coord_vers_num(num_vers_x(num), num_vers_y(num), num_vers_z(num)-1);
}

//Ajouter x en abscisse au numéro
inline int num_decaler_x(unsigned int const& num, int const& x)
{
  int tmp = num;
  
  if (x < 0)
  {
    for (byte i=0 ; i<-x ; i++)
      tmp = num_x_moins(tmp);
  }
  else
  {
    for (byte i=0 ; i<x ; i++)
      tmp = num_x_plus(tmp);
  }
  
  return tmp;
}

//Ajouter y en ordonné au numéro
inline int num_decaler_y(unsigned int const& num, int const& y)
{
  int tmp = num;
  
  if (y < 0)
  {
    for (byte i=0 ; i<-y ; i++)
      tmp = num_y_moins(tmp);
  }
  else
  {
    for (byte i=0 ; i<y ; i++)
      tmp = num_y_plus(tmp);
  }
  
  return tmp;
}

//Ajouter z en cote au numéro
inline int num_decaler_z(unsigned int const& num, int const& z)
{
  int tmp = num;
  
  if (z < 0)
  {
    for (byte i=0 ; i<-z ; i++)
      tmp = num_z_moins(tmp);
  }
  else
  {
    for (byte i=0 ; i<z ; i++)
      tmp = num_z_plus(tmp);
  }
  
  return tmp;
}

//Ajouter x, y et z aux coordonnées du numéro
inline unsigned int num_decaler_xyz(unsigned int const& num, int const& x, int const& y, int const& z)
{
  return num_decaler_z(num_decaler_y(num_decaler_x(num, x), y), z); //On décale x, puis y, puis z.
}

inline boolean decalage_possible(unsigned int const& num, int const& x, int const& y, int const& z)
{
  return est_dans_le_cube(num_vers_x(num)+x) && est_dans_le_cube(num_vers_y(num)+y) && est_dans_le_cube(num_vers_z(num)+z);
}

inline void reinit_translation()
{
  translation_x = 0;
  translation_y = 0;
  translation_z = 0;
}

inline void allumer_leds_avec_decalage(int const& decalage_x, int const& decalage_y, int const& decalage_z)
{
  //Valeur de décalage
  int decalage = decalage_x + decalage_y*9 + decalage_z*81;
  
  //On translate chaque point de la matrice de base
  for (unsigned int i=0 ; i<729 ; i++)
  {
    if (led_active(matrice_backup, i))
    {
      if (decalage_possible(i, decalage_x, decalage_y, decalage_z))
      {
        activer_led(matrice_affichage, i+decalage);
      }
    }
  }
}

inline void translater()
{
  //On écrase la matrice
  reinitialiser_matrice(matrice_affichage);
  
  //On la met à jour avec la translation
  allumer_leds_avec_decalage(translation_x, translation_y, translation_z);
  
  //On duplique l'image pour créer l'impression d'infini
  /*if (translation_x != 0)
  {
    if (translation_x < 0)
    {
      allumer_leds_avec_decalage(9-translation_x, translation_y, translation_z);
    }
    else
    {
      allumer_leds_avec_decalage(translation_x-9, translation_y, translation_z);
    }
  }*/
  
  //On envoie l'image
  autoriser_affichage = true;
}

#endif
