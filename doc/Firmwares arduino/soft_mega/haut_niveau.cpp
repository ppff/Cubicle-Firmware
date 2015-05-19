
#include "haut_niveau.h"

boolean led_active(word* m, unsigned int const& num) //num doit être entre 0 et 9*9*9-1 = 728
{
  if (num < 729)
  {
    return bitRead(m[num/9], num%9);
  }
  //else
    return false;
}

void activer_led(word* m, unsigned int const& num) //num doit être entre 0 et 9*9*9-1 = 728
{
  if (num <= 728)
    bitSet(m[num/9], num%9);
}

void desactiver_led(word* m, unsigned int const& num) //num doit être entre 0 et 9*9*9-1 = 728
{
  if (num <= 728)
    bitClear(m[num/9], num%9);
}

void changer_etat_led(word* m, unsigned int const& num, byte const& b)
{
  if (num <= 728)
    bitWrite(m[num/9], num%9, b);
}

void ajouter_plan(word* m, unsigned int const& num_plan, const char* bits) //doit faire 81 caractères ('1' ou '0')
{
  //!! Ne fonctionne pas avec la compression.  
  for (int i=0 ; i<81 ; i++)
  {
    changer_etat_led(m, 9*num_plan + i%9 + 81*(i/9), bits[i]-'0');
  }
}

void ajouter_plan_P(word* m, unsigned int const& num_plan, const char* str)
{      
  byte i = 0;
  
  while(byte c = pgm_read_byte(str++))
  {
   //old technique
   //changer_etat_led(m, 9*num_plan + i%9 + 81*(i/9), c-'0');
   
   /*Serial.print(i);
   Serial.print(" -- ");
   Serial.print((c - '0'));
   Serial.print(" (");
   Serial.print((c - '0'), BIN);
   Serial.println(")");*/
   //with compression
   if (i < 13)
   {
     for (int k=0 ; k<6 ; k++)
     {
       changer_etat_led(m, 9*num_plan + (6*i+k)%9 + 81*((6*i+k)/9), ((c - '0') >> (5-k)) & 0x01);
       /*Serial.print(9*num_plan + (6*i+k)%9 + 81*((6*i+k)/9));
       Serial.print(" : ");
       Serial.println(((c - '0') >> (5-k)) & 0x01);*/
     }
   }
   else
   {
     for (int k=0 ; k<3 ; k++)
     {
       changer_etat_led(m, 9*num_plan + (6*i+k)%9 + 81*((6*i+k)/9), ((c - '0') >> (2-k)) & 0x01);
       /*Serial.print(9*num_plan + (6*i+k)%9 + 81*((6*i+k)/9));
       Serial.print(" : ");
       Serial.println(((c - '0') >> (2-k)) & 0x01);*/
     }
   }
   
   i++;
  }
}

void ajouter_plan_horizontal_P(word* m, unsigned int const& num_plan, const char* str)
{      
  byte i = 0;
  
  while(byte c = pgm_read_byte(str++))
  {
   if (i < 13)
   {
     for (int k=0 ; k<6 ; k++)
     {
       changer_etat_led(m, 81*num_plan + 6*i + k, ((c - '0') >> (5-k)) & 0x01);
     }
   }
   else
   {
     for (int k=0 ; k<3 ; k++)
     {
       changer_etat_led(m, 81*num_plan + 6*i + k, ((c - '0') >> (2-k)) & 0x01);
     }
   }
   
   i++;
  }
}
