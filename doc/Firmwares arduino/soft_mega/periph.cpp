
#include "periph.h"

//byte boutons[] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
byte boutons[10] = {42, 40, 38, 36, 34, 30, 28, 26, 24, 22};

unsigned long time_boutons;
boolean mode_veille;

void init_boutons()
{  
  for (byte i=0 ; i<10 ; i++)
  {
    pinMode(boutons[i], INPUT);
    digitalWrite(boutons[i], HIGH);
  }
  
  time_boutons = millis();
  mode_veille = false;
}

byte bouton_actif()
{
  for (byte i=0 ; i<10 ; i++)
  {
    if (digitalRead(boutons[i]) == LOW && millis() - time_boutons > 200)
    {
      time_boutons = millis();
      if (mode_veille)
      {
        mode_veille = false;
        return i+10;
      }
      return i;
    }
  }

  return -1;  
}

//LiquidCrystal lcd = LiquidCrystal(A0, A1, A5, A4, A3, A2);
LiquidCrystal lcd = LiquidCrystal(31, 33, 41, 39, 37, 35);

void init_ecran()
{
  lcd.begin(20, 2);
  lcd.setCursor(0,0);
  lcd.print("       Cubicle      ");
  lcd.setCursor(0,1);
  lcd.print("     Please wait.   ");
}

void maj_ecran_chargement()
{
  lcd.clear();
}

void ecrire_ligne_centree(const char* string, boolean const& dessus)
{
  if (dessus)
  {
    lcd.setCursor(5,0);
  }
  else
  {
    lcd.setCursor(5,1);
  }
  
  byte l = 15-strlen(string);
  
  for (byte i=0 ; i<(l/2+l%2) ; i++)
    lcd.print(' ');
    
  lcd.print(string);  
  
  for (byte i=0 ; i<(l/2) ; i++)
    lcd.print(' ');
}

void ecrire_ligne_centree(const char* string, byte const& longueur, boolean const& dessus)
{
  if (dessus)
  {
    lcd.setCursor(5,0);
  }
  else
  {
    lcd.setCursor(5,1);
  }
  
  byte l = 15-longueur;
  
  for (byte i=0 ; i<(l/2+l%2) ; i++)
    lcd.print(' ');
    
  lcd.print(string);  
  
  for (byte i=0 ; i<(l/2) ; i++)
    lcd.print(' ');
}

void ecrire_ligne_centree_P(const char* string, byte const& longueur, boolean const& dessus)
{
  if (dessus)
  {
    lcd.setCursor(5,0);
  }
  else
  {
    lcd.setCursor(5,1);
  }
  
  byte l = 15-longueur;
  
  for (byte i=0 ; i<(l/2+l%2) ; i++)
    lcd.print(' ');
    
  while(char c = pgm_read_byte(string++))
    lcd.print(c);  
  
  for (byte i=0 ; i<(l/2) ; i++)
    lcd.print(' ');
}

void ecrire_numero(byte const& actuel, byte const& maximum, boolean const& dessus)
{
  if (dessus)
  {
    lcd.setCursor(0,0);
    lcd.print("     ");
    lcd.setCursor(0,0);
  }
  else
  {
    lcd.setCursor(0,1);
    lcd.print("     ");
    lcd.setCursor(0,1);
  }
  
  lcd.print(actuel);
  lcd.print('/');
  lcd.print(maximum);
}

void ecrire_ligne(const char* string, byte const& longueur, boolean const& dessus)
{
  if (dessus)
  {
    lcd.setCursor(0,0);
  }
  else
  {
    lcd.setCursor(0,1);
  }
  
  byte l = 20-longueur;
  
  for (byte i=0 ; i<(l/2) ; i++)
    lcd.print(' ');
    
  lcd.print(string); 
  
  for (byte i=0 ; i<(l/2+l%2) ; i++)
    lcd.print(' ');
}

void ecrire_ligne_P(const char* string, byte const& longueur, boolean const& dessus)
{
  if (dessus)
  {
    lcd.setCursor(0,0);
  }
  else
  {
    lcd.setCursor(0,1);
  }
  
  byte l = 20-longueur;
  
  for (byte i=0 ; i<(l/2) ; i++)
    lcd.print(' ');
    
  while(char c = pgm_read_byte(string++))
    lcd.print(c);   
  
  for (byte i=0 ; i<(l/2+l%2) ; i++)
    lcd.print(' ');
}

