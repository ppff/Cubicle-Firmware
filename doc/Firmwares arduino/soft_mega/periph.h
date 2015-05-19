#ifndef PERIPH_H
#define PERIPH_H

#include <Arduino.h>
#include <LiquidCrystal.h>

extern unsigned long time_boutons;
extern boolean mode_veille;

//Boutons
void init_boutons(); //Initialise les boutons.
byte bouton_actif(); //Renvoie le bouton actif.

//Ecran
extern LiquidCrystal lcd;
void init_ecran();                                                                                        //Initialise l'écran.
void maj_ecran_chargement();                                                                              //Action à effectuer après le "chargement" au démarrage du cube.
void ecrire_ligne_centree(const char* string, boolean const& dessus);                                     //Ecrit la ligne en la centrant, ligne 0 si dessus est TRUE, ligne 1 si dessus est FALSE.
void ecrire_ligne_centree(const char* string, byte const& longueur, boolean const& dessus);               //On indique spécifiquement la longueur.
void ecrire_ligne_centree_P(const char* string, byte const& longueur, boolean const& dessus);             //Idem mais avec la ligne dans la mémoire Flash
void ecrire_numero(byte const& actuel, byte const& maximum, boolean const& dessus);                       //Ecrit numero/maximum au début de la ligne.
void ecrire_ligne(const char* string, byte const& longueur, boolean const& dessus);                       //Ecrit sur la ligne entière.
void ecrire_ligne_P(const char* string, byte const& longueur, boolean const& dessus);                     //Ecrit sur la ligne entière depuis la Flash.
#endif
