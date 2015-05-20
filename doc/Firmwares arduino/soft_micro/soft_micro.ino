
/******************************/
/************ NOTE ************/
//If using Arduino Micro, change Serial into Serial1.
/******************************/

//Include
#include <SPI.h>

//Variables
#define LE 5
word matrice[81];

//Functions
inline void digitalWriteDirect(short pin, boolean val)
{
  if(val) *(portOutputRegister(digitalPinToPort(pin))) |= digitalPinToBitMask(pin);
  else    *(portOutputRegister(digitalPinToPort(pin))) &= ~digitalPinToBitMask(pin);
}

inline void eteindre_cube()
{
  for (byte i=0 ; i<10 ; i++)
  {
    SPI.transfer(0);
    SPI.transfer(0);
  }

  digitalWriteDirect(LE, HIGH);
  digitalWriteDirect(LE, LOW);
}

inline void envoyer_image(word const& plan, const word* lignes)
{  
  eteindre_cube();
  
  for (byte i=0 ; i<9 ; i++)
  {
    SPI.transfer((byte)((lignes[8-i]&0xFF00) >> 8));
    SPI.transfer((byte)(lignes[8-i]&0x00FF));
  }
  SPI.transfer((byte)((plan&0xFF00) >> 8));
  SPI.transfer((byte)(plan&0x00FF));
  digitalWriteDirect(LE, HIGH);
  digitalWriteDirect(LE, LOW);
}

inline void afficher_matrice()
{
  for (byte i=0 ; i<9 ; i++)
  {
    envoyer_image((word)(0x1 << i), matrice + 9*i);
    //delay(100);
  }
  
  /*for (byte i=9 ; i>0 ; i--)
  {
    envoyer_image((word)(0x1 << (i-1)), matrice + 9*(i-1));
    //delay(100);
  }*/

  eteindre_cube();
  //delay(100);
}

enum Etat_Affichage { Attente, Reponse, Reception };
byte etat_courant;
inline void recuperer_donnees()
{
  switch(etat_courant)
  {
    case Attente :
      if (Serial.available())
      {
        if (Serial.read() == 30)
          etat_courant = Reponse;
      }
      break;
    
    case Reponse :
      Serial.write((byte)40);
      etat_courant = Reception;
      //break;
      
    case Reception :
      byte i=0;   
      while (i<81)
      {
        if (Serial.available())
        {
          matrice[i] = Serial.read();
          i++;
        }
      }
      i=0;   
      while (i<10)
      {
        if (Serial.available())
        {
          byte tmp = Serial.read();
          matrice[8*i+0] |= (tmp & 0x0001) << 8;
          matrice[8*i+1] |= (tmp & 0x0002) << 7;
          matrice[8*i+2] |= (tmp & 0x0004) << 6;
          matrice[8*i+3] |= (tmp & 0x0008) << 5;
          matrice[8*i+4] |= (tmp & 0x0010) << 4;
          matrice[8*i+5] |= (tmp & 0x0020) << 3;
          matrice[8*i+6] |= (tmp & 0x0040) << 2;
          matrice[8*i+7] |= (tmp & 0x0080) << 1;
          i++;
        }
      }
      while (!Serial.available())
      {} //wait
      matrice[80] |= Serial.read() << 8;
      
      etat_courant = Attente;
      break; 
  }   
}

//Setup
void setup()
{
  Serial.begin(2000000);
  
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  SPI.setDataMode(SPI_MODE0);
  
  //SPI.setClockDivider(SPI_CLOCK_DIV2);
  
  pinMode(LE, OUTPUT);
  digitalWriteDirect(LE, LOW);
  
  for (byte i=0 ; i<81 ; i++)
  {
    matrice[i] = 0x0000;
  }
  eteindre_cube();

  etat_courant = Attente;
}

//Main
void loop()
{
  recuperer_donnees();
  
  afficher_matrice();
}
