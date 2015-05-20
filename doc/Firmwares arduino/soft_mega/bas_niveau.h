#ifndef CUBE_H
#define CUBE_H

#include <Arduino.h>

extern boolean autoriser_affichage;

enum Etat_Affichage { Attente, Demande, Reponse, Envoi };
byte etat_courant;

inline void init_affichage()
{
  Serial3.begin(2000000);
  etat_courant = Attente;
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}

inline void afficher_matrice(const word* matrice)
{
  switch(etat_courant)
  {
    case Attente :
      if (autoriser_affichage)
      {
        etat_courant = Demande;
        autoriser_affichage = false;
        digitalWrite(13, HIGH);
      }
      break;
    
    case Demande :
      Serial3.write((byte)30);
      etat_courant = Reponse;
      break;
      
    case Reponse :   
      if (Serial3.available())
      {
        if (Serial3.read() == 40)
        {
          etat_courant = Envoi;
        }
        else
        {
          etat_courant = Attente;
        }
      }
      break; 
      
    case Envoi :
      for (byte i=0 ; i<81 ; i++)
      {
        Serial3.write(matrice[i] & 0x00FF);
      }
      for (byte i=0 ; i<10 ; i++)
      {
        Serial3.write( (((matrice[8*i] & 0x0100) >> 8) | ((matrice[8*i+1] & 0x0100) >> 7) | ((matrice[8*i+2] & 0x0100) >> 6) | ((matrice[8*i+3] & 0x0100) >> 5) | ((matrice[8*i+4] & 0x0100) >> 4) | ((matrice[8*i+5] & 0x0100) >> 3) | ((matrice[8*i+6] & 0x0100) >> 2) | ((matrice[8*i+7] & 0x0100) >> 1)) & 0x00FF);
      }
      Serial3.write((matrice[80] >> 8) & 0x00FF);
      
      /*for (byte i=0 ; i<81 ; i++)
      {
        Serial3.write((matrice[i] >> 8) & 0x00FF);
        Serial3.write(matrice[i] & 0x00FF);
      }*/
      
      etat_courant = Attente;
      digitalWrite(13, LOW);
      
      break;
  }   
}

#endif
