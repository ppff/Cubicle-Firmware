#ifndef HAUT_NIVEAU_H
#define HAUT_NIVEAU_H

#include <Arduino.h>

boolean led_active(word* m, unsigned int const& num);
void activer_led(word* m, unsigned int const& num);
void desactiver_led(word* m, unsigned int const& num);
void changer_etat_led(word* m, unsigned int const& num, byte const& b);
void ajouter_plan(word* m, unsigned int const& num_plan, const char* bits);
void ajouter_plan_P(word* m, unsigned int const& num_plan, const char* str);
void ajouter_plan_horizontal_P(word* m, unsigned int const& num_plan, const char* str);

inline void reinitialiser_matrice(word* m)
{
  memset(m, 0, 162);
}

inline void copier_matrice(const word* m_src, word* m_dest)
{
  memcpy(m_dest, m_src, 162);
}

#endif
