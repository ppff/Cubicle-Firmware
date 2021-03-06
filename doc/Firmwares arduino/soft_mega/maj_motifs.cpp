
#include "motifs.h"

byte nombre_groupes()
{
  return 36;
}

void maj_motif()
{
  reinit_translation();
  reinitialiser_matrice(matrice_affichage);
  num = 1;

  switch(groupe_actuel)
  {
  case 0 : 
    ecrire_ligne_centree_P(PSTR("(100) planes"), 12, true);
    nb_motifs = 5;
    switch(motif_actuel)
    {
      case 0 : 
        ecrire_ligne_centree_P(PSTR("1 plane"), 7, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("ooooooooooooo7"));
        break;
      case 1 : 
        ecrire_ligne_centree_P(PSTR("1 plane"), 7, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("ooooooooooooo7"));
        break;
      case 2 : 
        ecrire_ligne_centree_P(PSTR("1 every 4"), 9, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("ooooooooooooo7"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("ooooooooooooo7"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("ooooooooooooo7"));
        break;
      case 3 : 
        ecrire_ligne_centree_P(PSTR("1 every 3"), 9, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("ooooooooooooo7"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("ooooooooooooo7"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("ooooooooooooo7"));
        break;
      case 4 : 
        ecrire_ligne_centree_P(PSTR("1 every 2"), 9, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("ooooooooooooo7"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("ooooooooooooo7"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("ooooooooooooo7"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("ooooooooooooo7"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("ooooooooooooo7"));
        break;
    }
    break;
  case 1 : 
    ecrire_ligne_centree_P(PSTR("(110) planes"), 12, true);
    nb_motifs = 6;
    switch(motif_actuel)
    {
      case 0 : 
        ecrire_ligne_centree_P(PSTR("1 plane"), 7, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("08108108108101"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("0@20@20@20@202"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("0P40P40P40P404"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("10810810810810"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("20@20@20@20@20"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("40P40P40P40P40"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("81081081081080"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("@20@20@20@20@0"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("P40P40P40P40P0"));
        break;
      case 1 : 
        ecrire_ligne_centree_P(PSTR("1 plane"), 7, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("08108108108101"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("0@20@20@20@202"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("0P40P40P40P404"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("10810810810810"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("20@20@20@20@20"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("40P40P40P40P40"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("81081081081080"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("@20@20@20@20@0"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("P40P40P40P40P0"));
        break;
      case 2 : 
        ecrire_ligne_centree_P(PSTR("1 every 6"), 9, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("89189189189181"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("@B2@B2@B2@B2@2"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("PT4PT4PT4PT4P4"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("10810810810810"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("20@20@20@20@20"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("40P40P40P40P40"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("89189189189181"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("@B2@B2@B2@B2@2"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("PT4PT4PT4PT4P4"));
        break;
      case 3 : 
        ecrire_ligne_centree_P(PSTR("1 every 4"), 9, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("R<AR<AR<AR<AR1"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("4@R4@R4@R4@R42"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("8Q48Q48Q48Q484"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("A28A28A28A28A0"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("R<AR<AR<AR<AR1"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("4@R4@R4@R4@R42"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("8Q48Q48Q48Q484"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("A28A28A28A28A0"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("R<AR<AR<AR<AR1"));
        break;
      case 4 : 
        ecrire_ligne_centree_P(PSTR("1 every 3"), 9, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("99999999999991"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("BBBBBBBBBBBBB2"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("TTTTTTTTTTTTT4"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("99999999999991"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("BBBBBBBBBBBBB2"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("TTTTTTTTTTTTT4"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("99999999999991"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("BBBBBBBBBBBBB2"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("TTTTTTTTTTTTT4"));
        break;
      case 5 : 
        ecrire_ligne_centree_P(PSTR("1 every 2"), 9, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("Z]EZ]EZ]EZ]EZ5"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("EBZEBZEBZEBZE2"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("Z]EZ]EZ]EZ]EZ5"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("EBZEBZEBZEBZE2"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("Z]EZ]EZ]EZ]EZ5"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("EBZEBZEBZEBZE2"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("Z]EZ]EZ]EZ]EZ5"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("EBZEBZEBZEBZE2"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("Z]EZ]EZ]EZ]EZ5"));
        break;
    }
    break;
  case 2 : 
    ecrire_ligne_centree_P(PSTR("(111) planes"), 12, true);
    nb_motifs = 5;
    switch(motif_actuel)
    {
      case 0 : 
        ecrire_ligne_centree_P(PSTR("1 plane"), 7, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("00000000000001"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("00000000000102"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("00000000008204"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("0000000010@410"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("0000000820P820"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("0000010@410@40"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("0000820P820P80"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("0010@410@410@0"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("0820P820P820P0"));
        break;
      case 1 : 
        ecrire_ligne_centree_P(PSTR("1 plane"), 7, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("00000000000001"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("00000000000102"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("00000000008204"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("0000000010@410"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("0000000820P820"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("0000010@410@40"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("0000820P820P80"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("0010@410@410@0"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("0820P820P820P0"));
        break;
      case 2 : 
        ecrire_ligne_centree_P(PSTR("1 every 9"), 9, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("0@410@410@4001"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("0P820P820P0102"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("10@410@4008204"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("20P820P010@410"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("410@400820P820"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("820P010@410@40"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("@400820P820P80"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("P010@410@410@0"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("0820P820P820P0"));
        break;
      case 3 : 
        ecrire_ligne_centree_P(PSTR("1 every 4"), 9, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("R8R8R8R8R8R8R1"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("4A4A4A4A4A4A42"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("8R8R8R8R8R8R84"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("A4A4A4A4A4A4A0"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("R8R8R8R8R8R8R1"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("4A4A4A4A4A4A42"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("8R8R8R8R8R8R84"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("A4A4A4A4A4A4A0"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("R8R8R8R8R8R8R1"));
        break;
      case 4 : 
        ecrire_ligne_centree_P(PSTR("1 every 3"), 9, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("BDT9:BTQ9BDT91"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("TQ9BDT9:BTQ9B2"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("9:BTQ9BDT9:BT4"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("BDT9:BTQ9BDT91"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("TQ9BDT9:BTQ9B2"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("9:BTQ9BDT9:BT4"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("BDT9:BTQ9BDT91"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("TQ9BDT9:BTQ9B2"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("9:BTQ9BDT9:BT4"));
        break;
    }
    break;
  case 3 : 
    ecrire_ligne_centree_P(PSTR("Triclinic"), 9, true);
    nb_motifs = 2;
    switch(motif_actuel)
    {
      case 0 : 
        ecrire_ligne_centree_P(PSTR("1 cell"), 6, false);
            ajouter_plan_P(matrice_affichage, 4, PSTR("00000@00000@00"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00000100000100"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("00000020000020"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("00000008000001"));
        break;
      case 1 : 
        ecrire_ligne_centree_P(PSTR("8 cells"), 7, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("000P00000P0000"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("00020000020000"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("00008000008000"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00004000004000"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("00000@00000@00"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00000100000100"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("P00000P00000P0"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("20000020000020"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("08000008000001"));
        break;
    }
    break;
  case 4 : 
    ecrire_ligne_centree_P(PSTR("Monoclinic"), 10, true);
    nb_motifs = 2;
    switch(motif_actuel)
    {
      case 0 : 
        ecrire_ligne_centree_P(PSTR("1 cell"), 6, false);
            ajouter_plan_P(matrice_affichage, 4, PSTR("00000020000020"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00000008000001"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("00000020000020"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("00000008000001"));
        break;
      case 1 : 
        ecrire_ligne_centree_P(PSTR("8 cells"), 7, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("P00000P00000P0"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("20000020000020"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("08000008000001"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("P00000P00000P0"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("20000020000020"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("08000008000001"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("P00000P00000P0"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("20000020000020"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("08000008000001"));
        break;
    }
    break;
  case 5 : 
    ecrire_ligne_centree_P(PSTR("Orthorhombic"), 12, true);
    nb_motifs = 2;
    switch(motif_actuel)
    {
      case 0 : 
        ecrire_ligne_centree_P(PSTR("1 cell "), 7, false);
            ajouter_plan_P(matrice_affichage, 6, PSTR("00000000A00021"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("00000000A00021"));
        break;
      case 1 : 
        ecrire_ligne_centree_P(PSTR("16 cells"), 8, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("R80000R80000R1"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("R80000R80000R1"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("R80000R80000R1"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("R80000R80000R1"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("R80000R80000R1"));
        break;
    }
    break;
  case 6 : 
    ecrire_ligne_centree_P(PSTR("Orthorhombic c"), 14, true);
    nb_motifs = 2;
    switch(motif_actuel)
    {
      case 0 : 
        ecrire_ligne_centree_P(PSTR("1 cell"), 6, false);
            ajouter_plan_P(matrice_affichage, 6, PSTR("00000028000021"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("0000000P000004"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("00000028000021"));
        break;
      case 1 : 
        ecrire_ligne_centree_P(PSTR("16 cells"), 8, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("R80000R80000R1"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("8P00008P000084"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("R80000R80000R1"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("8P00008P000084"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("R80000R80000R1"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("8P00008P000084"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("R80000R80000R1"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("8P00008P000084"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("R80000R80000R1"));
        break;
    }
    break;
  case 7 : 
    ecrire_ligne_centree_P(PSTR("Tetragonal"), 10, true);
    nb_motifs = 2;
    switch(motif_actuel)
    {
      case 0 : 
        ecrire_ligne_centree_P(PSTR("1 cell"), 6, false);
            ajouter_plan_P(matrice_affichage, 4, PSTR("00000000028021"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("00000000028021"));
        break;
      case 1 : 
        ecrire_ligne_centree_P(PSTR("16 cells"), 8, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("R80R80R80R80R1"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("R80R80R80R80R1"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("R80R80R80R80R1"));
        break;
    }
    break;
  case 8 : 
    ecrire_ligne_centree_P(PSTR("Tetragonal c"), 12, true);
    nb_motifs = 2;
    switch(motif_actuel)
    {
      case 0 : 
        ecrire_ligne_centree_P(PSTR("1 cell"), 6, false);
            ajouter_plan_P(matrice_affichage, 4, PSTR("00000000028021"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00000000000400"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("00000000028021"));
        break;
      case 1 : 
        ecrire_ligne_centree_P(PSTR("16 cells"), 8, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("R80R80R80R80R1"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("01401401401400"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("R80R80R80R80R1"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("01401401401400"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("R80R80R80R80R1"));
        break;
    }
    break;
  case 9 : 
    ecrire_ligne_centree_P(PSTR("Hexagonal AAAA"), 14, true);
    nb_motifs = 6;
    switch(motif_actuel)
    {
      case 0 : 
        ecrire_ligne_centree_P(PSTR("1 cell (1 C)"), 12, false);
            ajouter_plan_P(matrice_affichage, 2, PSTR("00000020000000"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00000000800000"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("00020080000000"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00000800P00000"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00080000000000"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("00000P00000000"));
        break;
      case 1 : 
        ecrire_ligne_centree_P(PSTR("n cells (1 C)"), 13, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("200880PP020081"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("00800P02200800"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("880PP0200880P4"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00P02200800P00"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("PP0200880PP020"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("02200800P02200"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("200880PP020081"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("00800P02200800"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("880PP0200880P4"));
        break;
      case 2 : 
        ecrire_ligne_centree_P(PSTR("1 cell (2 C)"), 12, false);
            ajouter_plan_P(matrice_affichage, 2, PSTR("00000020000000"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("0002008000P000"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("0008000P020000"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("00000020000000"));
        break;
      case 3 : 
        ecrire_ligne_centree_P(PSTR("n cells (2 C)"), 13, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("200880PP020081"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("880PP0200880P4"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("PP0200880PP020"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("200880PP020081"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("880PP0200880P4"));
        break;
      case 4 : 
        ecrire_ligne_centree_P(PSTR("1 cell (3 C)"), 12, false);
            ajouter_plan_P(matrice_affichage, 1, PSTR("00000P00000000"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00P02000000000"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("0000000000P000"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("02000000000000"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("0000000P020000"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("00000020000000"));
        break;
      case 5 : 
        ecrire_ligne_centree_P(PSTR("ABCABCA planes"), 14, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("R808P0R808P0R1"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("00R02800R02800"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("8P0R808P0R8084"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("02800R02800R00"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("R808P0R808P0R1"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00R02800R02800"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("8P0R808P0R8084"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("02800R02800R00"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("R808P0R808P0R1"));
        break;
    }
    break;
  case 10 : 
    ecrire_ligne_centree_P(PSTR("Rhombo. ABC"), 11, true);
    nb_motifs = 4;
    switch(motif_actuel)
    {
      case 0 : 
        ecrire_ligne_centree_P(PSTR("1c. (elongated)"), 15, false);
            ajouter_plan_P(matrice_affichage, 1, PSTR("02000000000000"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("00000020000000"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("00020080000000"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00000000200800"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("00000000800000"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("00000000000001"));
        break;
      case 1 : 
        ecrire_ligne_centree_P(PSTR("nc. (elongated)"), 15, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("0000800P020080"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("0800P0200800P0"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00000000000200"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("0P0200800P0000"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00000000200800"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("200800P0000000"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("00000200800P00"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("800P0000000001"));
        break;
      case 2 : 
        ecrire_ligne_centree_P(PSTR("1 cell (CFC)"), 12, false);
            ajouter_plan_P(matrice_affichage, 4, PSTR("0000002000P000"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("0000000P028004"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("0000000000P001"));
        break;
      case 3 : 
        ecrire_ligne_centree_P(PSTR("n cells (CFC)"), 13, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("R808P0R808P0R1"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("8P0R808P0R8084"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("R808P0R808P0R1"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("8P0R808P0R8084"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("R808P0R808P0R1"));
        break;
    }
    break;
  case 11 : 
    ecrire_ligne_centree_P(PSTR("Cubic P"), 7, true);
    nb_motifs = 2;
    switch(motif_actuel)
    {
      case 0 : 
        ecrire_ligne_centree_P(PSTR("1 cell"), 6, false);
            ajouter_plan_P(matrice_affichage, 4, PSTR("00000028000021"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("00000028000021"));
        break;
      case 1 : 
        ecrire_ligne_centree_P(PSTR("8 cells"), 7, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("R80000R80000R1"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("R80000R80000R1"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("R80000R80000R1"));
        break;
    }
    break;
  case 12 : 
    ecrire_ligne_centree_P(PSTR("Cubic C"), 7, true);
    nb_motifs = 2;
    switch(motif_actuel)
    {
      case 0 : 
        ecrire_ligne_centree_P(PSTR("1 cell"), 6, false);
            ajouter_plan_P(matrice_affichage, 4, PSTR("00000028000021"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("0000000000P000"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("00000028000021"));
        break;
      case 1 : 
        ecrire_ligne_centree_P(PSTR("8 cells"), 7, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("R80000R80000R1"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("0008P00008P000"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("R80000R80000R1"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("0008P00008P000"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("R80000R80000R1"));
        break;
    }
    break;
  case 13 : 
    ecrire_ligne_centree_P(PSTR("Cubic CFC"), 9, true);
    nb_motifs = 2;
    switch(motif_actuel)
    {
      case 0 : 
        ecrire_ligne_centree_P(PSTR("1 cell"), 6, false);
            ajouter_plan_P(matrice_affichage, 4, PSTR("0000002800P021"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("0000000P028004"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("0000002800P021"));
        break;
      case 1 : 
        ecrire_ligne_centree_P(PSTR("8 cells"), 7, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("R808P0R808P0R1"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("8P0R808P0R8084"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("R808P0R808P0R1"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("8P0R808P0R8084"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("R808P0R808P0R1"));
        break;
    }
    break;
  case 14 : 
    ecrire_ligne_centree_P(PSTR("NaCl"), 4, true);
    nb_motifs = 8;
    switch(motif_actuel)
    {
      case 0 : 
        ecrire_ligne_centree_P(PSTR("1c (Na blinks)"), 14, false);
            ajouter_plan_P(matrice_affichage, 4, PSTR("0000002X02X025"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("0000002X02X025"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("0000002X02X025"));
        break;
      case 1 : 
        ecrire_ligne_centree_P(PSTR("1c (Na blinks)"), 14, false);
            ajouter_plan_P(matrice_affichage, 4, PSTR("0000002800P021"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("0000000P028004"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("0000002800P021"));
        break;
      case 2 : 
        ecrire_ligne_centree_P(PSTR("1c (Cl blinks)"), 14, false);
            ajouter_plan_P(matrice_affichage, 4, PSTR("0000002X02X025"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("0000002X02X025"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("0000002X02X025"));
        break;
      case 3 : 
        ecrire_ligne_centree_P(PSTR("1c (Cl blinks)"), 14, false);
            ajouter_plan_P(matrice_affichage, 4, PSTR("0000000P028004"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("0000002X00P025"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("0000000P028004"));
        break;
      case 4 : 
        ecrire_ligne_centree_P(PSTR("8c (Na blinks)"), 14, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("ZX0ZX0ZX0ZX0Z5"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("ZX0ZX0ZX0ZX0Z5"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("ZX0ZX0ZX0ZX0Z5"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("ZX0ZX0ZX0ZX0Z5"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("ZX0ZX0ZX0ZX0Z5"));
        break;
      case 5 : 
        ecrire_ligne_centree_P(PSTR("8c (Na blinks)"), 14, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("R808P0R808P0R1"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("8P0R808P0R8084"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("R808P0R808P0R1"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("8P0R808P0R8084"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("R808P0R808P0R1"));
        break;
      case 6 : 
        ecrire_ligne_centree_P(PSTR("8c (Cl blinks)"), 14, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("ZX0ZX0ZX0ZX0Z5"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("ZX0ZX0ZX0ZX0Z5"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("ZX0ZX0ZX0ZX0Z5"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("ZX0ZX0ZX0ZX0Z5"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("ZX0ZX0ZX0ZX0Z5"));
        break;
      case 7 : 
        ecrire_ligne_centree_P(PSTR("8c (Cl blinks)"), 14, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("8P0R808P0R8084"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("R808P0R808P0R1"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("8P0R808P0R8084"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("R808P0R808P0R1"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("8P0R808P0R8084"));
        break;
    }
    break;
  case 15 : 
    ecrire_ligne_centree_P(PSTR("Diamond"), 7, true);
    nb_motifs = 3;
    switch(motif_actuel)
    {
      case 0 : 
        ecrire_ligne_centree_P(PSTR("1/4th of cell"), 13, false);
            ajouter_plan_P(matrice_affichage, 6, PSTR("00000000008004"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("00000000000200"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("0000000000P001"));
        break;
      case 1 : 
        ecrire_ligne_centree_P(PSTR("1 cell"), 6, false);
            ajouter_plan_P(matrice_affichage, 4, PSTR("0000002800P021"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00000000200800"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("0000000P028004"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("00000000800200"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("0000002800P021"));
        break;
      case 2 : 
        ecrire_ligne_centree_P(PSTR("8 cells"), 7, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("R808P0R808P0R1"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("00R02800R02800"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("8P0R808P0R8084"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("02800R02800R00"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("R808P0R808P0R1"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00R02800R02800"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("8P0R808P0R8084"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("02800R02800R00"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("R808P0R808P0R1"));
        break;
    }
    break;
  case 16 : 
    ecrire_ligne_centree_P(PSTR("(111) AA-AB-ABC"), 15, true);
    nb_motifs = 12;
    switch(motif_actuel)
    {
      case 0 : 
        ecrire_ligne_centree_P(PSTR("AA 1 cell"), 9, false);
            ajouter_plan_P(matrice_affichage, 2, PSTR("0000000000P000"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("0000000P020001"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00000020008004"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("0000000000P000"));
        break;
      case 1 : 
        ecrire_ligne_centree_P(PSTR("AAA n cells"), 11, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("880PP0200880P4"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("PP0200880PP020"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("200880PP020081"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("880PP0200880P4"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("PP0200880PP020"));
        break;
      case 2 : 
        ecrire_ligne_centree_P(PSTR("BB 1 cell"), 9, false);
            ajouter_plan_P(matrice_affichage, 2, PSTR("00000020000000"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("0002008000P000"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("0008000P020000"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("00000020000000"));
        break;
      case 3 : 
        ecrire_ligne_centree_P(PSTR("BBB n cells"), 11, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("200880PP020081"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("880PP0200880P4"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("PP0200880PP020"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("200880PP020081"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("880PP0200880P4"));
        break;
      case 4 : 
        ecrire_ligne_centree_P(PSTR("CCC 1 cell"), 10, false);
            ajouter_plan_P(matrice_affichage, 2, PSTR("00080000000000"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("800P0020000000"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("P0020080000000"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("00080000000000"));
        break;
      case 5 : 
        ecrire_ligne_centree_P(PSTR("CCC n cells"), 11, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("PP0200880PP020"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("200880PP020081"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("880PP0200880P4"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("PP0200880PP020"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("200880PP020081"));
        break;
      case 6 : 
        ecrire_ligne_centree_P(PSTR("ABAB 1 cell"), 11, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("00000020000000"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("00020080000000"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("0008000000P001"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00000000008004"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("0000000000P000"));
        break;
      case 7 : 
        ecrire_ligne_centree_P(PSTR("ABAB n cells"), 12, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("2808P0R00800P1"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("8P0R00800P8004"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("R00800P800P021"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("800P800P028084"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("P800P02808P0R0"));
        break;
      case 8 : 
        ecrire_ligne_centree_P(PSTR("ABC 1 cell 2C"), 13, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("00000020000000"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("00020080000000"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("0008002000P001"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00000000008004"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("0000000000P000"));
        break;
      case 9 : 
        ecrire_ligne_centree_P(PSTR("ABC n c. (CFC)"), 14, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("R808P0R808P0R1"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("8P0R808P0R8084"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("R808P0R808P0R1"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("8P0R808P0R8084"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("R808P0R808P0R1"));
        break;
      case 10 : 
        ecrire_ligne_centree_P(PSTR("ABC 1 c. (CFC)"), 14, false);
            ajouter_plan_P(matrice_affichage, 4, PSTR("0000002000P000"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("0000000P028004"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("0000000000P001"));
        break;
      case 11 : 
        ecrire_ligne_centree_P(PSTR("ABC n c. (CFC)"), 14, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("R808P0R808P0R1"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("8P0R808P0R8084"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("R808P0R808P0R1"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("8P0R808P0R8084"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("R808P0R808P0R1"));
        break;
    }
    break;
  case 17 : 
    ecrire_ligne_centree_P(PSTR("Graphene planes"), 15, true);
    nb_motifs = 5;
    switch(motif_actuel)
    {
      case 0 : 
        ecrire_ligne_centree_P(PSTR("1 (111) plane"), 13, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("00000000000001"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("00000000000102"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("00000000008204"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("0000000010@410"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("0000000820P820"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("0000010@410@40"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("0000820P820P80"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("0010@410@410@0"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("0820P820P820P0"));
        break;
      case 1 : 
        ecrire_ligne_centree_P(PSTR("1 B plane"), 9, false);
            ajouter_plan_P(matrice_affichage, 5, PSTR("00000000000102"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00000000008004"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("0000000000@400"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("00000008200820"));
        break;
      case 2 : 
        ecrire_ligne_centree_P(PSTR("1 C plane"), 9, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("00000000000001"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("00000000000100"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("00000000000204"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("0000000010@010"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("0000000800P800"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("0000000@400@40"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00008200820080"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("00100410041000"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("0020P020P020P0"));
        break;
      case 3 : 
        ecrire_ligne_centree_P(PSTR("1 A plane"), 9, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("0000000020P020"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("0000010@010@00"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("0000800P800P80"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("0000@400@400@0"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("08200820082000"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00410041004000"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("0P020P020P0000"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("10@010@0000000"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("00P800P0000000"));
        break;
      case 4 : 
        ecrire_ligne_centree_P(PSTR("ABCABCA planes"), 14, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("R808R800R8P0R1"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("4A404A4@0A4A00"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("028R808R800R84"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("A004A404A4@0A0"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("R8R028R808R800"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("014A004A404A42"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("8P0R8R028R8084"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("A4A014A004A400"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("00R8P0R8R028R1"));
        break;
    }
    break;
  case 18 : 
    ecrire_ligne_centree_P(PSTR("Diamond planes"), 14, true);
    nb_motifs = 4;
    switch(motif_actuel)
    {
      case 0 : 
        ecrire_ligne_centree_P(PSTR("1 B plane"), 9, false);
            ajouter_plan_P(matrice_affichage, 4, PSTR("00000000000001"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00000000008004"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("00000000000200"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("0000000800P020"));
        break;
      case 1 : 
        ecrire_ligne_centree_P(PSTR("1 C plane"), 9, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("00000000000001"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("00000000008004"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00000000000200"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("0000000800P020"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00000000200800"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("0000800P020080"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("00000200800P00"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("0800P0200800P0"));
        break;
      case 2 : 
        ecrire_ligne_centree_P(PSTR("1 A plane"), 9, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("0000000800P020"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("00000000200800"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("0000800P020080"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00000200800P00"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("0800P0200800P0"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00200800P02000"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("0P0200800P0000"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("00800P02000000"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("200800P0000000"));
        break;
      case 3 : 
        ecrire_ligne_centree_P(PSTR("ABCABCA planes"), 14, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("R808P0R808P0R1"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("00R02800R02800"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("8P0R808P0R8084"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("02800R02800R00"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("R808P0R808P0R1"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00R02800R02800"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("8P0R808P0R8084"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("02800R02800R00"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("R808P0R808P0R1"));
        break;
    }
    break;
  case 19 : 
    ecrire_ligne_centree_P(PSTR("Hex-Gra-Dia B"), 13, true);
    nb_motifs = 7;
    switch(motif_actuel)
    {
      case 0 : 
        ecrire_ligne_centree_P(PSTR("1 plane Bdia"), 12, false);
            ajouter_plan_P(matrice_affichage, 4, PSTR("00000000000001"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00000000008004"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("00000000000200"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("0000000800P020"));
        break;
      case 1 : 
        ecrire_ligne_centree_P(PSTR("1 plane B'"), 10, false);
            ajouter_plan_P(matrice_affichage, 4, PSTR("00000000000001"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00000000008004"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00000000008004"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("0000000800P220"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("0000000800P020"));
        break;
      case 2 : 
        ecrire_ligne_centree_P(PSTR("1 plane B''"), 11, false);
            ajouter_plan_P(matrice_affichage, 4, PSTR("00000000000001"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00000000008004"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00000000008004"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("0000000800P020"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("0000000800P020"));
        break;
      case 3 : 
        ecrire_ligne_centree_P(PSTR("1 plane Bdia"), 12, false);
            ajouter_plan_P(matrice_affichage, 4, PSTR("00000000000001"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00000000008004"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("00000000000200"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("0000000800P020"));
        break;
      case 4 : 
        ecrire_ligne_centree_P(PSTR("1 plane B'"), 10, false);
            ajouter_plan_P(matrice_affichage, 4, PSTR("00000000000001"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00000000008004"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00000000008004"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("0000000800P220"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("0000000800P020"));
        break;
      case 5 : 
        ecrire_ligne_centree_P(PSTR("1 plane B''"), 11, false);
            ajouter_plan_P(matrice_affichage, 4, PSTR("00000000000001"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00000000008004"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00000000008004"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("0000000800P020"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("0000000800P020"));
        break;
      case 6 : 
        ecrire_ligne_centree_P(PSTR("1 plane B'"), 10, false);
            ajouter_plan_P(matrice_affichage, 4, PSTR("00000000000001"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00000000008004"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00000000008004"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("0000000800P220"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("0000000800P020"));
        break;
    }
    break;
  case 20 : 
    ecrire_ligne_centree_P(PSTR("Hex-Gra-Dia C"), 13, true);
    nb_motifs = 7;
    switch(motif_actuel)
    {
      case 0 : 
        ecrire_ligne_centree_P(PSTR("1 plane Cdia"), 12, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("00000000000001"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("00000000008004"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00000000000200"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("0000000800P020"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00000000200800"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("0010000P020080"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("00000200800P00"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("0800P0200800P0"));
        break;
      case 1 : 
        ecrire_ligne_centree_P(PSTR("1 plane C'"), 10, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("00000000000001"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("00000000008004"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("00000000008004"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("0000000800P220"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("0000000800P020"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("0000800P220880"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("0000800P020080"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("0800P220880PP0"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("0800P0200800P0"));
        break;
      case 2 : 
        ecrire_ligne_centree_P(PSTR("1 plane C''"), 11, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("00000000000001"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("00000000008004"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("00000000008004"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("0000000800P020"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("0000000800P020"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("0000800P020080"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("0000800P020080"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("0800P0200800P0"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("0800P0200800P0"));
        break;
      case 3 : 
        ecrire_ligne_centree_P(PSTR("1 plane Cdia"), 12, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("00000000000001"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("00000000008004"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00000000000200"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("0000000800P020"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00000000200800"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("0010000P020080"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("00000200800P00"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("0800P0200800P0"));
        break;
      case 4 : 
        ecrire_ligne_centree_P(PSTR("1 plane C'"), 10, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("00000000000001"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("00000000008004"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("00000000008004"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("0000000800P220"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("0000000800P020"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("0000800P220880"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("0000800P020080"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("0800P220880PP0"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("0800P0200800P0"));
        break;
      case 5 : 
        ecrire_ligne_centree_P(PSTR("1 plane C''"), 11, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("00000000000001"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("00000000008004"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("00000000008004"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("0000000800P020"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("0000000800P020"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("0000800P020080"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("0000800P020080"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("0800P0200800P0"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("0800P0200800P0"));
        break;
      case 6 : 
        ecrire_ligne_centree_P(PSTR("1 plane C'"), 10, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("00000000000001"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("00000000008004"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("00000000008004"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("0000000800P220"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("0000000800P020"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("0000800P220880"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("0000800P020080"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("0800P220880PP0"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("0800P0200800P0"));
        break;
    }
    break;
  case 21 : 
    ecrire_ligne_centree_P(PSTR("Hex-Gra-Dia A"), 13, true);
    nb_motifs = 7;
    switch(motif_actuel)
    {
      case 0 : 
        ecrire_ligne_centree_P(PSTR("1 plane Adia"), 12, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("0000000800P020"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("00000000200800"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("0000800P020080"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00000200800P00"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("0800P0200800P0"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00200800P02000"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("0P0200800P0000"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("00800P02000000"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("200800P0000000"));
        break;
      case 1 : 
        ecrire_ligne_centree_P(PSTR("1 plane A'"), 10, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("0000000800P020"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("0000800P220880"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("0000800P020080"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("0800P220880PP0"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("0800P0200800P0"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("0P220880PP2000"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("0P0200800P0000"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("20880PP2000000"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("200800P0000000"));
        break;
      case 2 : 
        ecrire_ligne_centree_P(PSTR("1 plane A''"), 11, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("0000000800P020"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("0000800P020080"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("0000800P020080"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("0800P0200800P0"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("0800P0200800P0"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("0P0200800P0000"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("0P0200800P0000"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("200800P0000000"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("200800P0000000"));
        break;
      case 3 : 
        ecrire_ligne_centree_P(PSTR("1 plane Adia"), 12, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("0000000800P020"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("00000000200800"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("0000800P020080"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00000200800P00"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("0800P0200800P0"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00200800P02000"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("0P0200800P0000"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("00800P02000000"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("200800P0000000"));
        break;
      case 4 : 
        ecrire_ligne_centree_P(PSTR("1 plane A'"), 10, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("0000000800P020"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("0000800P220880"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("0000800P020080"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("0800P220880PP0"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("0800P0200800P0"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("0P220880PP2000"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("0P0200800P0000"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("20880PP2000000"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("200800P0000000"));
        break;
      case 5 : 
        ecrire_ligne_centree_P(PSTR("1 plane A''"), 11, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("0000000800P020"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("0000800P020080"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("0000800P020080"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("0800P0200800P0"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("0800P0200800P0"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("0P0200800P0000"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("0P0200800P0000"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("200800P0000000"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("200800P0000000"));
        break;
      case 6 : 
        ecrire_ligne_centree_P(PSTR("1 plane A'"), 10, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("0000000800P020"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("0000800P220880"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("0000800P020080"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("0800P220880PP0"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("0800P0200800P0"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("0P220880PP2000"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("0P0200800P0000"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("20880PP2000000"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("200800P0000000"));
        break;
    }
    break;
  case 22 : 
    ecrire_ligne_centree_P(PSTR("Hex-Gra-Dia BCA"), 15, true);
    nb_motifs = 7;
    switch(motif_actuel)
    {
      case 0 : 
        ecrire_ligne_centree_P(PSTR("1 plane BCAdia"), 14, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("R808P0R808P0R1"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("00R02800R02800"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("8P0R808P0R8084"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("02800R02800R00"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("R808P0R808P0R1"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00R02800R02800"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("8P0R808P0R8084"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("02800R02800R00"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("R808P0R808P0R1"));
        break;
      case 1 : 
        ecrire_ligne_centree_P(PSTR("1 plane BCA'"), 12, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("R808P0R808P0R1"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("8PRR:88PRR:884"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("8P0R808P0R8084"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("R288PRR:88PR21"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("R808P0R808P0R1"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("8PRR:88PRR:884"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("8P0R808P0R8084"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("R288PRR:88PR21"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("R808P0R808P0R1"));
        break;
      case 2 : 
        ecrire_ligne_centree_P(PSTR("1 plane BCA''"), 13, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("R808P0R808P0R1"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("8P0R808P0R8084"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("8P0R808P0R8084"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("R808P0R808P0R1"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("R808P0R808P0R1"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("8P0R808P0R8084"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("8P0R808P0R8084"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("R808P0R808P0R1"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("R808P0R808P0R1"));
        break;
      case 3 : 
        ecrire_ligne_centree_P(PSTR("1 plane BCAdia"), 14, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("R808P0R808P0R1"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("00R02800R02800"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("8P0R808P0R8084"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("02800R02800R00"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("R808P0R808P0R1"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00R02800R02800"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("8P0R808P0R8084"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("02800R02800R00"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("R808P0R808P0R1"));
        break;
      case 4 : 
        ecrire_ligne_centree_P(PSTR("1 plane BCA'"), 12, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("R808P0R808P0R1"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("8PRR:88PRR:884"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("8P0R808P0R8084"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("R288PRR:88PR21"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("R808P0R808P0R1"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("8PRR:88PRR:884"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("8P0R808P0R8084"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("R288PRR:88PR21"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("R808P0R808P0R1"));
        break;
      case 5 : 
        ecrire_ligne_centree_P(PSTR("1 plane BCA''"), 13, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("R808P0R808P0R1"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("8P0R808P0R8084"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("8P0R808P0R8084"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("R808P0R808P0R1"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("R808P0R808P0R1"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("8P0R808P0R8084"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("8P0R808P0R8084"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("R808P0R808P0R1"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("R808P0R808P0R1"));
        break;
      case 6 : 
        ecrire_ligne_centree_P(PSTR("1 plane BCA'"), 12, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("R808P0R808P0R1"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("8PRR:88PRR:884"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("8P0R808P0R8084"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("R288PRR:88PR21"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("R808P0R808P0R1"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("8PRR:88PRR:884"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("8P0R808P0R8084"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("R288PRR:88PR21"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("R808P0R808P0R1"));
        break;
    }
    break;
  case 23 : 
    ecrire_ligne_centree_P(PSTR("Hex-Gra-Dia"), 11, true);
    nb_motifs = 4;
    switch(motif_actuel)
    {
      case 0 : 
        ecrire_ligne_centree_P(PSTR("Graphene planes"), 15, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("R808R800R8P0R1"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("4A404A4@0A4A00"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("028R808R800R84"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("A004A404A4@0A0"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("R8R028R808R800"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("014A004A404A42"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("8P0R8R028R8084"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("A4A014A004A400"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("00R8P0R8R028R1"));
        break;
      case 1 : 
        ecrire_ligne_centree_P(PSTR("Diamond planes"), 14, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("R808P0R808P0R1"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("00R02800R02800"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("8P0R808P0R8084"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("02800R02800R00"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("R808P0R808P0R1"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00R02800R02800"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("8P0R808P0R8084"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("02800R02800R00"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("R808P0R808P0R1"));
        break;
      case 2 : 
        ecrire_ligne_centree_P(PSTR("Graphene planes"), 15, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("R808R800R8P0R1"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("4A404A4@0A4A00"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("028R808R800R84"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("A004A404A4@0A0"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("R8R028R808R800"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("014A004A404A42"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("8P0R8R028R8084"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("A4A014A004A400"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("00R8P0R8R028R1"));
        break;
      case 3 : 
        ecrire_ligne_centree_P(PSTR("Diamond planes"), 14, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("R808P0R808P0R1"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("00R02800R02800"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("8P0R808P0R8084"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("02800R02800R00"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("R808P0R808P0R1"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00R02800R02800"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("8P0R808P0R8084"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("02800R02800R00"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("R808P0R808P0R1"));
        break;
    }
    break;
  case 24 : 
    ecrire_ligne_centree_P(PSTR("Geometry"), 8, true);
    nb_motifs = 5;
    switch(motif_actuel)
    {
      case 0 : 
        ecrire_ligne_centree_P(PSTR("Ball"), 4, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("00000020000000"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("00071l?Ql70000"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("00h?SnOcn?Ph00"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("01lOcnOcnOal00"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("21lOcnoknOal20"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("01lOcnOcnOal00"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00h?SnOcn?Ph00"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("00071l?Ql70000"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("00000020000000"));
        break;
      case 1 : 
        ecrire_ligne_centree_P(PSTR("Full cone"), 9, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("040`60h60`4000"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("P60h7Pl7Ph60P0"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("`70n7ho7hn70`0"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("`7Po7loglo7P`0"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("h7Po7noono7Ph0"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("`7Po7loglo7P`0"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("`70n7ho7hn70`0"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("P60h7Pl7Ph60P0"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("040`60h60`4000"));
        break;
      case 2 : 
        ecrire_ligne_centree_P(PSTR("Half cone"), 9, false);
            ajouter_plan_P(matrice_affichage, 2, PSTR("000041P<100000"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("000P>3hn3P8000"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("000P?7oo7P8000"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("000P>3hn3P8000"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("000041P<100000"));
        break;
      case 3 : 
        ecrire_ligne_centree_P(PSTR("Hyperboloid 1"), 13, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("041P<1`L1P<100"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("P<1`N3`N3`L1P1"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("P>3`O7ho7`N3P1"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("P>3ho7ho7hn3P1"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("`N3ho7mo7hn3`3"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("P>3ho7ho7hn3P1"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("P>3`O7ho7`N3P1"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("P<1`N3`N3`L1P1"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("041P<1`L1P<100"));
        break;
      case 4 : 
        ecrire_ligne_centree_P(PSTR("Hyperboloid 2"), 13, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("000041P<100000"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("000P>3`N3P8000"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("041`O7ho7`L100"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("P>3ho_oo_hn3P1"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("P>3hooooohn3P1"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("P>3ho_oo_hn3P1"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("041`O7ho7`L100"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("000P>3`N3P8000"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("000041P<100000"));
        break;
    }
    break;
  case 25 : 
    ecrire_ligne_centree_P(PSTR("Alphabet"), 8, true);
    nb_motifs = 26;
    switch(motif_actuel)
    {
      case 0 : 
        ecrire_ligne_centree_P(PSTR("A"), 1, false);
            ajouter_plan_P(matrice_affichage, 2, PSTR("00108108100000"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00000008008000"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("00000008000100"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00000008008000"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00108108100000"));
        break;
      case 1 : 
        ecrire_ligne_centree_P(PSTR("B"), 1, false);
            ajouter_plan_P(matrice_affichage, 2, PSTR("00108108108100"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00100008000100"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("00100008000100"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00100008000100"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00008100108000"));
        break;
      case 2 : 
        ecrire_ligne_centree_P(PSTR("C"), 1, false);
            ajouter_plan_P(matrice_affichage, 2, PSTR("00008108108000"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00100000000100"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("00100000000100"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00100000000100"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00008000008000"));
        break;
      case 3 : 
        ecrire_ligne_centree_P(PSTR("D"), 1, false);
            ajouter_plan_P(matrice_affichage, 2, PSTR("00108108108100"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00100000000100"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("00100000000100"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00100000000100"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00008108108000"));
        break;
      case 4 : 
        ecrire_ligne_centree_P(PSTR("E"), 1, false);
            ajouter_plan_P(matrice_affichage, 2, PSTR("00108108108100"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00100008000100"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("00100008000100"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00100008000100"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00100000000100"));
        break;
      case 5 : 
        ecrire_ligne_centree_P(PSTR("F"), 1, false);
            ajouter_plan_P(matrice_affichage, 2, PSTR("00108108108100"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00000008000100"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("00000008000100"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00000008000100"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00000000000100"));
        break;
      case 6 : 
        ecrire_ligne_centree_P(PSTR("G"), 1, false);
            ajouter_plan_P(matrice_affichage, 2, PSTR("00008108108000"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00100000000100"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("00100100000100"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00100100000100"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00108100008000"));
        break;
      case 7 : 
        ecrire_ligne_centree_P(PSTR("H"), 1, false);
            ajouter_plan_P(matrice_affichage, 2, PSTR("00108108108100"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00000008000000"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("00000008000000"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00000008000000"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00108108108100"));
        break;
      case 8 : 
        ecrire_ligne_centree_P(PSTR("I"), 1, false);
            ajouter_plan_P(matrice_affichage, 2, PSTR("00100000000100"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00100000000100"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("00108108108100"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00100000000100"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00100000000100"));
        break;
      case 9 : 
        ecrire_ligne_centree_P(PSTR("J"), 1, false);
            ajouter_plan_P(matrice_affichage, 2, PSTR("00008000000100"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00100000000100"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("00108108108100"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00000000000100"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00000000000100"));
        break;
      case 10 : 
        ecrire_ligne_centree_P(PSTR("K"), 1, false);
            ajouter_plan_P(matrice_affichage, 2, PSTR("00108108108100"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00000008000000"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("00000100100000"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00008000008000"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00100000000100"));
        break;
      case 11 : 
        ecrire_ligne_centree_P(PSTR("L"), 1, false);
            ajouter_plan_P(matrice_affichage, 2, PSTR("00108108108100"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00100000000000"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("00100000000000"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00100000000000"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00100000000000"));
        break;
      case 12 : 
        ecrire_ligne_centree_P(PSTR("M"), 1, false);
            ajouter_plan_P(matrice_affichage, 2, PSTR("00108108108100"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00000000008000"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("00000000100000"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00000000008000"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00108108108100"));
        break;
      case 13 : 
        ecrire_ligne_centree_P(PSTR("N"), 1, false);
            ajouter_plan_P(matrice_affichage, 2, PSTR("00108108108100"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00000000100000"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("00000008000000"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00000100000000"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00108108108100"));
        break;
      case 14 : 
        ecrire_ligne_centree_P(PSTR("O"), 1, false);
            ajouter_plan_P(matrice_affichage, 2, PSTR("00008108108000"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00100000000100"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("00100000000100"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00100000000100"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00008108108000"));
        break;
      case 15 : 
        ecrire_ligne_centree_P(PSTR("P"), 1, false);
            ajouter_plan_P(matrice_affichage, 2, PSTR("00108108108100"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00000008000100"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("00000008000100"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00000008000100"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00000000108000"));
        break;
      case 16 : 
        ecrire_ligne_centree_P(PSTR("Q"), 1, false);
            ajouter_plan_P(matrice_affichage, 2, PSTR("00008108108000"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00100000000100"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("00100100000100"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00008000000100"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00100108108000"));
        break;
      case 17 : 
        ecrire_ligne_centree_P(PSTR("R"), 1, false);
            ajouter_plan_P(matrice_affichage, 2, PSTR("00108108108100"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00000008000100"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("00000108000100"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00008008000100"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00100000108000"));
        break;
      case 18 : 
        ecrire_ligne_centree_P(PSTR("S"), 1, false);
            ajouter_plan_P(matrice_affichage, 2, PSTR("00100000108000"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00100008000100"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("00100008000100"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00100008000100"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00008100000100"));
        break;
      case 19 : 
        ecrire_ligne_centree_P(PSTR("T"), 1, false);
            ajouter_plan_P(matrice_affichage, 2, PSTR("00000000000100"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00000000000100"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("00108108108100"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00000000000100"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00000000000100"));
        break;
      case 20 : 
        ecrire_ligne_centree_P(PSTR("U"), 1, false);
            ajouter_plan_P(matrice_affichage, 2, PSTR("00008108108100"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00100000000000"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("00100000000000"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00100000000000"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00008108108100"));
        break;
      case 21 : 
        ecrire_ligne_centree_P(PSTR("V"), 1, false);
            ajouter_plan_P(matrice_affichage, 2, PSTR("00000108108100"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00008000000000"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("00100000000000"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00008000000000"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00000108108100"));
        break;
      case 22 : 
        ecrire_ligne_centree_P(PSTR("W"), 1, false);
            ajouter_plan_P(matrice_affichage, 2, PSTR("00008108108100"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00100000000000"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("00008100000000"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00100000000000"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00008108108100"));
        break;
      case 23 : 
        ecrire_ligne_centree_P(PSTR("X"), 1, false);
            ajouter_plan_P(matrice_affichage, 2, PSTR("00108000008100"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00000100100000"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("00000008000000"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00000100100000"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00108000008100"));
        break;
      case 24 : 
        ecrire_ligne_centree_P(PSTR("Y"), 1, false);
            ajouter_plan_P(matrice_affichage, 2, PSTR("00000000008100"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00000000100000"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("00108108000000"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00000000100000"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00000000008100"));
        break;
      case 25 : 
        ecrire_ligne_centree_P(PSTR("Z"), 1, false);
            ajouter_plan_P(matrice_affichage, 2, PSTR("00108000000100"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00100100000100"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("00100008000100"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00100000100100"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00100000008100"));
        break;
    }
    break;
  case 26 : 
    ecrire_ligne_centree_P(PSTR("Chiffres"), 8, true);
    nb_motifs = 10;
    switch(motif_actuel)
    {
      case 0 : 
        ecrire_ligne_centree_P(PSTR("0"), 1, false);
            ajouter_plan_P(matrice_affichage, 2, PSTR("00008108108000"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00100000100100"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("00100008000100"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00100100000100"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00008108108000"));
        break;
      case 1 : 
        ecrire_ligne_centree_P(PSTR("1"), 1, false);
            ajouter_plan_P(matrice_affichage, 2, PSTR("00100000100000"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00100000008000"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("00108108108100"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00100000000000"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00100000000000"));
        break;
      case 2 : 
        ecrire_ligne_centree_P(PSTR("2"), 1, false);
            ajouter_plan_P(matrice_affichage, 2, PSTR("00100000008000"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00108000000100"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("00100100000100"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00100008000100"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00100000108000"));
        break;
      case 3 : 
        ecrire_ligne_centree_P(PSTR("3"), 1, false);
            ajouter_plan_P(matrice_affichage, 2, PSTR("00008000008000"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00100000000100"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("00100008000100"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00100008000100"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00008100108000"));
        break;
      case 4 : 
        ecrire_ligne_centree_P(PSTR("4"), 1, false);
            ajouter_plan_P(matrice_affichage, 2, PSTR("00000108000000"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00000100100000"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("00000100008000"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00108108108100"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00000100000000"));
        break;
      case 5 : 
        ecrire_ligne_centree_P(PSTR("5"), 1, false);
            ajouter_plan_P(matrice_affichage, 2, PSTR("00008008108100"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00100008000100"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("00100008000100"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00100008000100"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00008100000100"));
        break;
      case 6 : 
        ecrire_ligne_centree_P(PSTR("6"), 1, false);
            ajouter_plan_P(matrice_affichage, 2, PSTR("00008108108000"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00100008000100"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("00100008000100"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00100008000100"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00008100008000"));
        break;
      case 7 : 
        ecrire_ligne_centree_P(PSTR("7"), 1, false);
            ajouter_plan_P(matrice_affichage, 2, PSTR("00000000000100"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00108100000100"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("00000008000100"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00000000100100"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00000000008100"));
        break;
      case 8 : 
        ecrire_ligne_centree_P(PSTR("8"), 1, false);
            ajouter_plan_P(matrice_affichage, 2, PSTR("00008100108000"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00100008000100"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("00100008000100"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00100008000100"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00008100108000"));
        break;
      case 9 : 
        ecrire_ligne_centree_P(PSTR("9"), 1, false);
            ajouter_plan_P(matrice_affichage, 2, PSTR("00000000108000"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00100008000100"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("00100008000100"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00100008000100"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00008108108000"));
        break;
    }
    break;
  case 27 : 
    ecrire_ligne_centree_P(PSTR("Emoticones"), 10, true);
    nb_motifs = 13;
    switch(motif_actuel)
    {
      case 0 : 
        ecrire_ligne_centree_P(PSTR("*"), 1, false);
            ajouter_plan_P(matrice_affichage, 3, PSTR("00000000008000"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("00000000100100"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00000000008000"));
        break;
      case 1 : 
        ecrire_ligne_centree_P(PSTR("battery"), 7, false);
            ajouter_plan_P(matrice_affichage, 2, PSTR("08108108108100"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("08108108100101"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("08108108000101"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("08108100000101"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("08108108108100"));
        break;
      case 2 : 
        ecrire_ligne_centree_P(PSTR("coeur"), 5, false);
            ajouter_plan_P(matrice_affichage, 1, PSTR("00000008100000"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("00000100008000"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00008000008000"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("00100000100000"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00008000008000"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00000100008000"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("00000008100000"));
        break;
      case 3 : 
        ecrire_ligne_centree_P(PSTR(":"), 1, false);
            ajouter_plan_P(matrice_affichage, 4, PSTR("00000100100000"));
        break;
      case 4 : 
        ecrire_ligne_centree_P(PSTR("Boum boum"), 9, false);
            ajouter_plan_P(matrice_affichage, 2, PSTR("00020h=Q400000"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00@71lOc^H`000"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("20h?Snooomk600"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00@71lOc^H`000"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00020h=Q400000"));
        break;
      case 5 : 
        ecrire_ligne_centree_P(PSTR("-"), 1, false);
            ajouter_plan_P(matrice_affichage, 2, PSTR("00000008000000"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00000008000000"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("00000008000000"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00000008000000"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00000008000000"));
        break;
      case 6 : 
        ecrire_ligne_centree_P(PSTR("SpaceInvad"), 10, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("08000108100000"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("00100108108000"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("08008108008100"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00100108108101"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("00100108108101"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("08008108008100"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00100108108000"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("08000108100000"));
        break;
      case 7 : 
        ecrire_ligne_centree_P(PSTR("lol"), 3, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("00000000008101"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("00000000008000"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("00000000008000"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00000108100000"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("00000100100000"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00000108100000"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("08108000000000"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("08000000000000"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("08000000000000"));
        break;
      case 8 : 
        ecrire_ligne_centree_P(PSTR("message"), 7, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("00000008108100"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("00000008000001"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("00000008008001"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00000008000001"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("00000008008001"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00000008000001"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00000008008001"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("00000100000001"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("00008108108100"));
        break;
      case 9 : 
        ecrire_ligne_centree_P(PSTR("!"), 1, false);
            ajouter_plan_P(matrice_affichage, 4, PSTR("00100108108100"));
        break;
      case 10 : 
        ecrire_ligne_centree_P(PSTR("?"), 1, false);
            ajouter_plan_P(matrice_affichage, 2, PSTR("00000000008000"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00000000000100"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("00100100000100"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00000008000100"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00000000108000"));
        break;
      case 11 : 
        ecrire_ligne_centree_P(PSTR("time"), 4, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("00008108108000"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("00100000000100"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("08000000000001"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("08000000000001"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("08000008108001"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("08000100000001"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("08000000000001"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("00100000000000"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("00008108108100"));
        break;
      case 12 : 
        ecrire_ligne_centree_P(PSTR("Verre"), 5, false);
            ajouter_plan_P(matrice_affichage, 2, PSTR("00100000108100"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("00100008000000"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("00108108000000"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("00100008000000"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("00100000108100"));
        break;
    }
    break;
  case 28 : 
    ecrire_ligne_centree_P(PSTR("GIF - Sinus"), 11, true);
    nb_motifs = 16;
    switch(motif_actuel)
    {
      case 0 : 
        ecrire_ligne_centree_P(PSTR("1"), 1, false);
            ajouter_plan_horizontal_P(matrice_affichage, 0, PSTR("Hf3P80000P>3H6"));
            ajouter_plan_horizontal_P(matrice_affichage, 1, PSTR("700041P<100070"));
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("P94@@0000@A4P1"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("00X02222200X00"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("00@8P0@@08P@00"));
            ajouter_plan_horizontal_P(matrice_affichage, 7, PSTR("00051D51D50000"));
            ajouter_plan_horizontal_P(matrice_affichage, 8, PSTR("00020X8PX20000"));
        break;
      case 1 : 
        ecrire_ligne_centree_P(PSTR("2"), 1, false);
            ajouter_plan_horizontal_P(matrice_affichage, 0, PSTR("?R2P<1P<1P:2?4"));
            ajouter_plan_horizontal_P(matrice_affichage, 1, PSTR("@E5@@0000@E5@2"));
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("00X02202200X00"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("P8@000@@000@P1"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("0008P00008P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("00051421450000"));
            ajouter_plan_horizontal_P(matrice_affichage, 7, PSTR("0002008P020000"));
            ajouter_plan_horizontal_P(matrice_affichage, 8, PSTR("00000h50h00000"));
        break;
      case 2 : 
        ecrire_ligne_centree_P(PSTR("3"), 1, false);
            ajouter_plan_horizontal_P(matrice_affichage, 0, PSTR("736@D1P<1@C670"));
            ajouter_plan_horizontal_P(matrice_affichage, 1, PSTR("8PXP:2022P8X84"));
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("@DA8P0@@08TA@2"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("00051401450000"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("P802008P0200P1"));
            ajouter_plan_horizontal_P(matrice_affichage, 7, PSTR("00000X20X00000"));
            ajouter_plan_horizontal_P(matrice_affichage, 8, PSTR("00000@50@00000"));
        break;
      case 3 : 
        ecrire_ligne_centree_P(PSTR("4"), 1, false);
            ajouter_plan_horizontal_P(matrice_affichage, 0, PSTR("21\@B2P:2@A\20"));
            ajouter_plan_horizontal_P(matrice_affichage, 1, PSTR("52B8T1@D18RB50"));
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("8P0P80000P8084"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("00051401450000"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("@D12008P0241@2"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("P8000X00X000P1"));
            ajouter_plan_horizontal_P(matrice_affichage, 7, PSTR("00000@50@00000"));
            ajouter_plan_horizontal_P(matrice_affichage, 8, PSTR("00000020000000"));
        break;
      case 4 : 
        ecrire_ligne_centree_P(PSTR("5"), 1, false);
            ajouter_plan_horizontal_P(matrice_affichage, 0, PSTR("01lHb2@B2Hal00"));
            ajouter_plan_horizontal_P(matrice_affichage, 1, PSTR("200000P8000020"));
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("5227558U572250"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("8P0P80000P8084"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("@D100X00X041@2"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("00000@50@00000"));
            ajouter_plan_horizontal_P(matrice_affichage, 7, PSTR("P80000000000P1"));
            ajouter_plan_horizontal_P(matrice_affichage, 8, PSTR("00000020000000"));
        break;
      case 5 : 
        ecrire_ligne_centree_P(PSTR("6"), 1, false);
            ajouter_plan_horizontal_P(matrice_affichage, 0, PSTR("00h8R2@B28Ph00"));
            ajouter_plan_horizontal_P(matrice_affichage, 1, PSTR("014GA48Q4GA400"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("70004YP<Y00070"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("02200000002200"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("8P0P8@50@P8084"));
            ajouter_plan_horizontal_P(matrice_affichage, 7, PSTR("@D1000000041@2"));
            ajouter_plan_horizontal_P(matrice_affichage, 8, PSTR("P80000200000P1"));
        break;
      case 6 : 
        ecrire_ligne_centree_P(PSTR("7"), 1, false);
            ajouter_plan_horizontal_P(matrice_affichage, 0, PSTR("000?Q48Q4?P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 1, PSTR("00h022@B200h00"));
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("00000X00X00000"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("014@@@50@@A400"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("200000P8000020"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("52204104102250"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("8P0P80000P8084"));
            ajouter_plan_horizontal_P(matrice_affichage, 7, PSTR("00000020000000"));
            ajouter_plan_horizontal_P(matrice_affichage, 8, PSTR("`L1000000041`3"));
        break;
      case 7 : 
        ecrire_ligne_centree_P(PSTR("8"), 1, false);
            ajouter_plan_horizontal_P(matrice_affichage, 0, PSTR("0007148Q470000"));
            ajouter_plan_horizontal_P(matrice_affichage, 1, PSTR("0008PX00X8P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("00@00@E@@00@00"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("00X02202200X00"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("014@@0000@A400"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("700041R<100070"));
            ajouter_plan_horizontal_P(matrice_affichage, 7, PSTR("XZ2P80000P:2X5"));
            ajouter_plan_horizontal_P(matrice_affichage, 8, PSTR("@D1000000041@2"));
        break;
      case 8 : 
        ecrire_ligne_centree_P(PSTR("9"), 1, false);
            ajouter_plan_horizontal_P(matrice_affichage, 0, PSTR("00020X8PX20000"));
            ajouter_plan_horizontal_P(matrice_affichage, 1, PSTR("00051D51D50000"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("00@8P0@@08P@00"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("00X02222200X00"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("P94@@0000@A4P1"));
            ajouter_plan_horizontal_P(matrice_affichage, 7, PSTR("700041P<100070"));
            ajouter_plan_horizontal_P(matrice_affichage, 8, PSTR("Hf3P80000P>3H6"));
        break;
      case 9 : 
        ecrire_ligne_centree_P(PSTR("10"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 0, PSTR("00000h50h00000"));
            ajouter_plan_horizontal_P(matrice_affichage, 1, PSTR("0002008P020000"));
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("00051421450000"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("0008P00008P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("P8@000@@000@P1"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("00X02202200X00"));
            ajouter_plan_horizontal_P(matrice_affichage, 7, PSTR("@E5@@0000@E5@2"));
            ajouter_plan_horizontal_P(matrice_affichage, 8, PSTR("?R2P<1P<1P:2?4"));
        break;
      case 10 : 
        ecrire_ligne_centree_P(PSTR("11"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 0, PSTR("00000@50@00000"));
            ajouter_plan_horizontal_P(matrice_affichage, 1, PSTR("00000X20X00000"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("P802008P0200P1"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("00051401450000"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("@DA8P0@@08TA@2"));
            ajouter_plan_horizontal_P(matrice_affichage, 7, PSTR("8PXP:2022P8X84"));
            ajouter_plan_horizontal_P(matrice_affichage, 8, PSTR("736@D1P<1@C670"));
        break;
      case 11 : 
        ecrire_ligne_centree_P(PSTR("12"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 0, PSTR("00000020000000"));
            ajouter_plan_horizontal_P(matrice_affichage, 1, PSTR("00000@50@00000"));
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("P8000X00X000P1"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("@D12008P0241@2"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("00051401450000"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("8P0P80000P8084"));
            ajouter_plan_horizontal_P(matrice_affichage, 7, PSTR("52B8T1@D18RB50"));
            ajouter_plan_horizontal_P(matrice_affichage, 8, PSTR("21\@B2P:2@A\20"));
        break;
      case 12 : 
        ecrire_ligne_centree_P(PSTR("13"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 0, PSTR("00000020000000"));
            ajouter_plan_horizontal_P(matrice_affichage, 1, PSTR("P80000000000P1"));
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("00000@50@00000"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("@D100X00X041@2"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("8P0P80000P8084"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("5227558U572250"));
            ajouter_plan_horizontal_P(matrice_affichage, 7, PSTR("200000P8000020"));
            ajouter_plan_horizontal_P(matrice_affichage, 8, PSTR("01lHb2@B2Hal00"));
        break;
      case 13 : 
        ecrire_ligne_centree_P(PSTR("14"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 0, PSTR("P80000200000P1"));
            ajouter_plan_horizontal_P(matrice_affichage, 1, PSTR("@D1000000041@2"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("8P0P8@50@P8084"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("02200000002200"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("70004YP<Y00070"));
            ajouter_plan_horizontal_P(matrice_affichage, 7, PSTR("014GA48Q4GA400"));
            ajouter_plan_horizontal_P(matrice_affichage, 8, PSTR("00h8R2@B28Ph00"));
        break;
      case 14 : 
        ecrire_ligne_centree_P(PSTR("15"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 0, PSTR("`L1000000041`3"));
            ajouter_plan_horizontal_P(matrice_affichage, 1, PSTR("00000020000000"));
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("8P0P80000P8084"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("52204104102250"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("200000P8000020"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("014@@@50@@A400"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("00000X00X00000"));
            ajouter_plan_horizontal_P(matrice_affichage, 7, PSTR("00h022@B200h00"));
            ajouter_plan_horizontal_P(matrice_affichage, 8, PSTR("000?Q48Q4?P000"));
        break;
      case 15 : 
        ecrire_ligne_centree_P(PSTR("16"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 0, PSTR("@D1000000041@2"));
            ajouter_plan_horizontal_P(matrice_affichage, 1, PSTR("XZ2P80000P:2X5"));
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("700041R<100070"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("014@@0000@A400"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("00X02202200X00"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("00@00@E@@00@00"));
            ajouter_plan_horizontal_P(matrice_affichage, 7, PSTR("0008PX00X8P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 8, PSTR("0007148Q470000"));
        break;
    }
    break;
  case 29 : 
    ecrire_ligne_centree_P(PSTR("GIF - Ellipse"), 13, true);
    nb_motifs = 8;
    switch(motif_actuel)
    {
      case 0 : 
        ecrire_ligne_centree_P(PSTR("1"), 1, false);
            ajouter_plan_horizontal_P(matrice_affichage, 0, PSTR("00000@20@00000"));
            ajouter_plan_horizontal_P(matrice_affichage, 1, PSTR("00020@20@20000"));
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("00020@20@20000"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("00020@20@20000"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("00@20@70@20@00"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("00020@20@20000"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("00020@20@20000"));
            ajouter_plan_horizontal_P(matrice_affichage, 7, PSTR("00020@20@20000"));
            ajouter_plan_horizontal_P(matrice_affichage, 8, PSTR("00000@20@00000"));
        break;
      case 1 : 
        ecrire_ligne_centree_P(PSTR("2"), 1, false);
            ajouter_plan_horizontal_P(matrice_affichage, 0, PSTR("00000020000000"));
            ajouter_plan_horizontal_P(matrice_affichage, 1, PSTR("00020h70h20000"));
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("00@70h70h70@00"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("00h70h70h70h00"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("20h70h?Ph70h20"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("00h70h70h70h00"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("00@70h70h70@00"));
            ajouter_plan_horizontal_P(matrice_affichage, 7, PSTR("00020h70h20000"));
            ajouter_plan_horizontal_P(matrice_affichage, 8, PSTR("00000020000000"));
        break;
      case 2 : 
        ecrire_ligne_centree_P(PSTR("3"), 1, false);
            ajouter_plan_horizontal_P(matrice_affichage, 1, PSTR("00000020000000"));
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("00h71l?Ql70h00"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("71l?Ql?Ql?Ql70"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("71l?QlOal?Ql70"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("71l?Ql?Ql?Ql70"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("00h71l?Ql70h00"));
            ajouter_plan_horizontal_P(matrice_affichage, 7, PSTR("00000020000000"));
        break;
      case 3 : 
        ecrire_ligne_centree_P(PSTR("4"), 1, false);
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("00000020000000"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("00h?SnOcn?Ph00"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("21lOcnoknOal20"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("00h?SnOcn?Ph00"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("00000020000000"));
        break;
      case 4 : 
        ecrire_ligne_centree_P(PSTR("5"), 1, false);
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("00000020000000"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("00@OgooooO`@00"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("00000020000000"));
        break;
      case 5 : 
        ecrire_ligne_centree_P(PSTR("6"), 1, false);
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("00000020000000"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("00001lOal00000"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("00023nokn20000"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("00001lOal00000"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("00000020000000"));
        break;
      case 6 : 
        ecrire_ligne_centree_P(PSTR("7"), 1, false);
            ajouter_plan_horizontal_P(matrice_affichage, 1, PSTR("00000020000000"));
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("000000?P000000"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("000000?P000000"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("00000@O`@00000"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("000000?P000000"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("000000?P000000"));
            ajouter_plan_horizontal_P(matrice_affichage, 7, PSTR("00000020000000"));
        break;
      case 7 : 
        ecrire_ligne_centree_P(PSTR("8"), 1, false);
            ajouter_plan_horizontal_P(matrice_affichage, 0, PSTR("00000020000000"));
            ajouter_plan_horizontal_P(matrice_affichage, 1, PSTR("00000@70@00000"));
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("00000h70h00000"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("00000h70h00000"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("00020h?Ph20000"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("00000h70h00000"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("00000h70h00000"));
            ajouter_plan_horizontal_P(matrice_affichage, 7, PSTR("00000@70@00000"));
            ajouter_plan_horizontal_P(matrice_affichage, 8, PSTR("00000020000000"));
        break;
    }
    break;
  case 30 : 
    ecrire_ligne_centree_P(PSTR("GIF - Aretes"), 12, true);
    nb_motifs = 51;
    switch(motif_actuel)
    {
      case 0 : 
        ecrire_ligne_centree_P(PSTR("01"), 2, false);
        break;
      case 1 : 
        ecrire_ligne_centree_P(PSTR("02"), 2, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("08000000000000"));
        break;
      case 2 : 
        ecrire_ligne_centree_P(PSTR("03"), 2, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("0H100000000000"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("08000000000000"));
        break;
      case 3 : 
        ecrire_ligne_centree_P(PSTR("04"), 2, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("0h108000000000"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("08000000000000"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("08000000000000"));
        break;
      case 4 : 
        ecrire_ligne_centree_P(PSTR("05"), 2, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("1h108100000000"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("08000000000000"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("08000000000000"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("08000000000000"));
        break;
      case 5 : 
        ecrire_ligne_centree_P(PSTR("06"), 2, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("3h108108000000"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("08000000000000"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("08000000000000"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("08000000000000"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("08000000000000"));
        break;
      case 6 : 
        ecrire_ligne_centree_P(PSTR("07"), 2, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("7h108108100000"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("08000000000000"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("08000000000000"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("08000000000000"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("08000000000000"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("08000000000000"));
        break;
      case 7 : 
        ecrire_ligne_centree_P(PSTR("08"), 2, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("?h108108108000"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("08000000000000"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("08000000000000"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("08000000000000"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("08000000000000"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("08000000000000"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("08000000000000"));
        break;
      case 8 : 
        ecrire_ligne_centree_P(PSTR("09"), 2, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("Oh108108108100"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("08000000000000"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("08000000000000"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("08000000000000"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("08000000000000"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("08000000000000"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("08000000000000"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("08000000000000"));
        break;
      case 9 : 
        ecrire_ligne_centree_P(PSTR("10"), 2, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("oh108108108101"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("08000000000000"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("08000000000000"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("08000000000000"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("08000000000000"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("08000000000000"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("08000000000000"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("08000000000000"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("08000000000000"));
        break;
      case 10 : 
        ecrire_ligne_centree_P(PSTR("11"), 2, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("ol108108108103"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("08000000000000"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("08000000000000"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("08000000000000"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("08000000000000"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("08000000000000"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("08000000000000"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("0H100000000000"));
        break;
      case 11 : 
        ecrire_ligne_centree_P(PSTR("12"), 2, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("ol1P8108108107"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("08000000000000"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("08000000000000"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("08000000000000"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("08000000000000"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("08000000000000"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("0h108000000000"));
        break;
      case 12 : 
        ecrire_ligne_centree_P(PSTR("13"), 2, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("ol1P<108108117"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("08000000000000"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("08000000000000"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("08000000000000"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("08000000000000"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("1h108100000000"));
        break;
      case 13 : 
        ecrire_ligne_centree_P(PSTR("14"), 2, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("ol1P<1P8108137"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("08000000000000"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("08000000000000"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("08000000000000"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("3h108108000000"));
        break;
      case 14 : 
        ecrire_ligne_centree_P(PSTR("15"), 2, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("ol1P<1P<108177"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("08000000000000"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("08000000000000"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("7h108108100000"));
        break;
      case 15 : 
        ecrire_ligne_centree_P(PSTR("16"), 2, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("ol1P<1P<1P81?7"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("08000000000000"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("?h108108108000"));
        break;
      case 16 : 
        ecrire_ligne_centree_P(PSTR("17"), 2, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("ol1P<1P<1P<1O7"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("Oh108108108100"));
        break;
      case 17 : 
        ecrire_ligne_centree_P(PSTR("18"), 2, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("ol1P<1P<1P<1o7"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("oh108108108101"));
        break;
      case 18 : 
        ecrire_ligne_centree_P(PSTR("19"), 2, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("ol1P<1P<1P<1o7"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("ol108108108103"));
        break;
      case 19 : 
        ecrire_ligne_centree_P(PSTR("20"), 2, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("ol1P<1P<1P<1o7"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("ol1P8108108107"));
        break;
      case 20 : 
        ecrire_ligne_centree_P(PSTR("21"), 2, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("ol1P<1P<1P<1o7"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("ol1P<108108117"));
        break;
      case 21 : 
        ecrire_ligne_centree_P(PSTR("22"), 2, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("ol1P<1P<1P<1o7"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("ol1P<1P8108137"));
        break;
      case 22 : 
        ecrire_ligne_centree_P(PSTR("23"), 2, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("ol1P<1P<1P<1o7"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("ol1P<1P<108177"));
        break;
      case 23 : 
        ecrire_ligne_centree_P(PSTR("24"), 2, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("ol1P<1P<1P<1o7"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("P8000000000001"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("ol1P<1P<1P81?7"));
        break;
      case 24 : 
        ecrire_ligne_centree_P(PSTR("25"), 2, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("ol1P<1P<1P<1o7"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("ol1P<1P<1P<1O7"));
        break;
      case 25 : 
        ecrire_ligne_centree_P(PSTR("26"), 2, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("ol1P<1P<1P<1o7"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("ol1P<1P<1P<1o7"));
        break;
      case 26 : 
        ecrire_ligne_centree_P(PSTR("27"), 2, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("od1P<1P<1P<1o7"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("ol1P<1P<1P<1o7"));
        break;
      case 27 : 
        ecrire_ligne_centree_P(PSTR("28"), 2, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("oT0P<1P<1P<1o7"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("ol1P<1P<1P<1o7"));
        break;
      case 28 : 
        ecrire_ligne_centree_P(PSTR("29"), 2, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("o40P41P<1P<1o7"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("ol1P<1P<1P<1o7"));
        break;
      case 29 : 
        ecrire_ligne_centree_P(PSTR("30"), 2, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("n40P40P<1P<1o7"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("ol1P<1P<1P<1o7"));
        break;
      case 30 : 
        ecrire_ligne_centree_P(PSTR("31"), 2, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("l40P40P41P<1o7"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("ol1P<1P<1P<1o7"));
        break;
      case 31 : 
        ecrire_ligne_centree_P(PSTR("32"), 2, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("h40P40P40P<1o7"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("ol1P<1P<1P<1o7"));
        break;
      case 32 : 
        ecrire_ligne_centree_P(PSTR("33"), 2, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("`40P40P40P41o7"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("ol1P<1P<1P<1o7"));
        break;
      case 33 : 
        ecrire_ligne_centree_P(PSTR("34"), 2, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("P40P40P40P40o7"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("ol1P<1P<1P<1o7"));
        break;
      case 34 : 
        ecrire_ligne_centree_P(PSTR("35"), 2, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("040P40P40P40o6"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("od1P<1P<1P<1o7"));
        break;
      case 35 : 
        ecrire_ligne_centree_P(PSTR("36"), 2, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("000P40P40P40o4"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("oT0P<1P<1P<1o7"));
        break;
      case 36 : 
        ecrire_ligne_centree_P(PSTR("37"), 2, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("000040P40P40o0"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("o40P41P<1P<1o7"));
        break;
      case 37 : 
        ecrire_ligne_centree_P(PSTR("38"), 2, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("000000P40P40n0"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("n40P40P<1P<1o7"));
        break;
      case 38 : 
        ecrire_ligne_centree_P(PSTR("39"), 2, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("000000040P40l0"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("l40P40P41P<1o7"));
        break;
      case 39 : 
        ecrire_ligne_centree_P(PSTR("40"), 2, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("000000000P40h0"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("h40P40P40P<1o7"));
        break;
      case 40 : 
        ecrire_ligne_centree_P(PSTR("41"), 2, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("000000000040`0"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("P00000000000P1"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("`40P40P40P41o7"));
        break;
      case 41 : 
        ecrire_ligne_centree_P(PSTR("42"), 2, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("P40P40P40P40o7"));
        break;
      case 42 : 
        ecrire_ligne_centree_P(PSTR("43"), 2, false);
            ajouter_plan_P(matrice_affichage, 1, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("040P40P40P40o6"));
        break;
      case 43 : 
        ecrire_ligne_centree_P(PSTR("44"), 2, false);
            ajouter_plan_P(matrice_affichage, 2, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("000P40P40P40o4"));
        break;
      case 44 : 
        ecrire_ligne_centree_P(PSTR("45"), 2, false);
            ajouter_plan_P(matrice_affichage, 3, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("000040P40P40o0"));
        break;
      case 45 : 
        ecrire_ligne_centree_P(PSTR("46"), 2, false);
            ajouter_plan_P(matrice_affichage, 4, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("000000P40P40n0"));
        break;
      case 46 : 
        ecrire_ligne_centree_P(PSTR("47"), 2, false);
            ajouter_plan_P(matrice_affichage, 5, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("000000040P40l0"));
        break;
      case 47 : 
        ecrire_ligne_centree_P(PSTR("48"), 2, false);
            ajouter_plan_P(matrice_affichage, 6, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("000000000P40h0"));
        break;
      case 48 : 
        ecrire_ligne_centree_P(PSTR("49"), 2, false);
            ajouter_plan_P(matrice_affichage, 7, PSTR("000000000000P0"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("000000000040`0"));
        break;
      case 49 : 
        ecrire_ligne_centree_P(PSTR("50"), 2, false);
            ajouter_plan_P(matrice_affichage, 8, PSTR("000000000000P0"));
        break;
      case 50 : 
        ecrire_ligne_centree_P(PSTR("51"), 2, false);
        break;
    }
    break;
  case 31 : 
    ecrire_ligne_centree_P(PSTR("Aretes"), 6, true);
    nb_motifs = 1;
    switch(motif_actuel)
    {
      case 0 : 
        ecrire_ligne_centree_P(PSTR("01"), 2, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("ol1P<1P<1P<1o7"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("P80000000000P1"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("ol1P<1P<1P<1o7"));
        break;
    }
    break;
  case 32 : 
    ecrire_ligne_centree_P(PSTR("GIF - Segment"), 13, true);
    nb_motifs = 15;
    switch(motif_actuel)
    {
      case 0 : 
        ecrire_ligne_centree_P(PSTR("1"), 1, false);
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("000086730P0000"));
        break;
      case 1 : 
        ecrire_ligne_centree_P(PSTR("2"), 1, false);
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("0020P820P82000"));
        break;
      case 2 : 
        ecrire_ligne_centree_P(PSTR("3"), 1, false);
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("0P810@20@40P80"));
        break;
      case 3 : 
        ecrire_ligne_centree_P(PSTR("4"), 1, false);
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("20@20@20@20@20"));
        break;
      case 4 : 
        ecrire_ligne_centree_P(PSTR("5"), 1, false);
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("80P40@20@10804"));
        break;
      case 5 : 
        ecrire_ligne_centree_P(PSTR("6"), 1, false);
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("02080P2080P200"));
        break;
      case 6 : 
        ecrire_ligne_centree_P(PSTR("7"), 1, false);
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("000P3070608000"));
        break;
      case 7 : 
        ecrire_ligne_centree_P(PSTR("8"), 1, false);
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("000000oh000000"));
        break;
      case 8 : 
        ecrire_ligne_centree_P(PSTR("9"), 1, false);
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("000086730P0000"));
        break;
      case 9 : 
        ecrire_ligne_centree_P(PSTR("10"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("0020P820P82000"));
        break;
      case 10 : 
        ecrire_ligne_centree_P(PSTR("11"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("0P810@20@40P80"));
        break;
      case 11 : 
        ecrire_ligne_centree_P(PSTR("12"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("20@20@20@20@20"));
        break;
      case 12 : 
        ecrire_ligne_centree_P(PSTR("13"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("80P40@20@10804"));
        break;
      case 13 : 
        ecrire_ligne_centree_P(PSTR("14"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("02080P2080P200"));
        break;
      case 14 : 
        ecrire_ligne_centree_P(PSTR("15"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("000P3070608000"));
        break;
    }
    break;
  case 33 : 
    ecrire_ligne_centree_P(PSTR("GIF - Cube 1"), 12, true);
    nb_motifs = 20;
    switch(motif_actuel)
    {
      case 0 : 
        ecrire_ligne_centree_P(PSTR("01"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 1, PSTR("03n@B2@B2@Cn00"));
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("02200000002200"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("02200000002200"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("02200000002200"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("02200000002200"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("02200000002200"));
            ajouter_plan_horizontal_P(matrice_affichage, 7, PSTR("03n@B2@B2@Cn00"));
        break;
      case 1 : 
        ecrire_ligne_centree_P(PSTR("02"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 1, PSTR("0Ql`B2@B2@Il80"));
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("0P0P0000008080"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("0P0P0000008080"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("0P0P0000008080"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("0P0P0000008080"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("0P0P0000008080"));
            ajouter_plan_horizontal_P(matrice_affichage, 7, PSTR("0Ql`B2@B2@Il80"));
        break;
      case 2 : 
        ecrire_ligne_centree_P(PSTR("03"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 1, PSTR("30\HV2P:38aX60"));
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("10004000100040"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("10004000100040"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("10004000100040"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("10004000100040"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("10004000100040"));
            ajouter_plan_horizontal_P(matrice_affichage, 7, PSTR("30\HV2P:38aX60"));
        break;
      case 3 : 
        ecrire_ligne_centree_P(PSTR("04"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 1, PSTR("61X8b3P>2HP\30"));
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("40000104000010"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("40000104000010"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("40000104000010"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("40000104000010"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("40000104000010"));
            ajouter_plan_horizontal_P(matrice_affichage, 7, PSTR("61X8b3P>2HP\30"));
        break;
      case 4 : 
        ecrire_ligne_centree_P(PSTR("05"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 1, PSTR("81l@J2@B2`Al04"));
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("800080000P0004"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("800080000P0004"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("800080000P0004"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("800080000P0004"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("800080000P0004"));
            ajouter_plan_horizontal_P(matrice_affichage, 7, PSTR("81l@J2@B2`Al04"));
        break;
      case 5 : 
        ecrire_ligne_centree_P(PSTR("06"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 1, PSTR("03n@B2@B2@Cn00"));
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("02200000002200"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("02200000002200"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("02200000002200"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("02200000002200"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("02200000002200"));
            ajouter_plan_horizontal_P(matrice_affichage, 7, PSTR("03n@B2@B2@Cn00"));
        break;
      case 6 : 
        ecrire_ligne_centree_P(PSTR("07"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 1, PSTR("0Ql`B2@B2@Il80"));
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("0P0P0000008080"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("0P0P0000008080"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("0P0P0000008080"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("0P0P0000008080"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("0P0P0000008080"));
            ajouter_plan_horizontal_P(matrice_affichage, 7, PSTR("0Ql`B2@B2@Il80"));
        break;
      case 7 : 
        ecrire_ligne_centree_P(PSTR("08"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 1, PSTR("30\HV2P:38aX60"));
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("10004000100040"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("10004000100040"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("10004000100040"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("10004000100040"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("10004000100040"));
            ajouter_plan_horizontal_P(matrice_affichage, 7, PSTR("30\HV2P:38aX60"));
        break;
      case 8 : 
        ecrire_ligne_centree_P(PSTR("09"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 1, PSTR("61X8b3P>2HP\30"));
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("40000104000010"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("40000104000010"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("40000104000010"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("40000104000010"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("40000104000010"));
            ajouter_plan_horizontal_P(matrice_affichage, 7, PSTR("61X8b3P>2HP\30"));
        break;
      case 9 : 
        ecrire_ligne_centree_P(PSTR("10"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 1, PSTR("81l@J2@B2`Al04"));
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("800080000P0004"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("800080000P0004"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("800080000P0004"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("800080000P0004"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("800080000P0004"));
            ajouter_plan_horizontal_P(matrice_affichage, 7, PSTR("81l@J2@B2`Al04"));
        break;
      case 10 : 
        ecrire_ligne_centree_P(PSTR("11"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 1, PSTR("03n@B2@B2@Cn00"));
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("02200000002200"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("02200000002200"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("02200000002200"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("02200000002200"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("02200000002200"));
            ajouter_plan_horizontal_P(matrice_affichage, 7, PSTR("03n@B2@B2@Cn00"));
        break;
      case 11 : 
        ecrire_ligne_centree_P(PSTR("12"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 1, PSTR("0Ql`B2@B2@Il80"));
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("0P0P0000008080"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("0P0P0000008080"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("0P0P0000008080"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("0P0P0000008080"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("0P0P0000008080"));
            ajouter_plan_horizontal_P(matrice_affichage, 7, PSTR("0Ql`B2@B2@Il80"));
        break;
      case 12 : 
        ecrire_ligne_centree_P(PSTR("13"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 1, PSTR("30\HV2P:38aX60"));
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("10004000100040"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("10004000100040"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("10004000100040"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("10004000100040"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("10004000100040"));
            ajouter_plan_horizontal_P(matrice_affichage, 7, PSTR("30\HV2P:38aX60"));
        break;
      case 13 : 
        ecrire_ligne_centree_P(PSTR("14"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 1, PSTR("61X8b3P>2HP\30"));
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("40000104000010"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("40000104000010"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("40000104000010"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("40000104000010"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("40000104000010"));
            ajouter_plan_horizontal_P(matrice_affichage, 7, PSTR("61X8b3P>2HP\30"));
        break;
      case 14 : 
        ecrire_ligne_centree_P(PSTR("15"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 1, PSTR("81l@J2@B2`Al04"));
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("800080000P0004"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("800080000P0004"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("800080000P0004"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("800080000P0004"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("800080000P0004"));
            ajouter_plan_horizontal_P(matrice_affichage, 7, PSTR("81l@J2@B2`Al04"));
        break;
      case 15 : 
        ecrire_ligne_centree_P(PSTR("16"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 1, PSTR("03n@B2@B2@Cn00"));
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("02200000002200"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("02200000002200"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("02200000002200"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("02200000002200"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("02200000002200"));
            ajouter_plan_horizontal_P(matrice_affichage, 7, PSTR("03n@B2@B2@Cn00"));
        break;
      case 16 : 
        ecrire_ligne_centree_P(PSTR("17"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 1, PSTR("0Ql`B2@B2@Il80"));
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("0P0P0000008080"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("0P0P0000008080"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("0P0P0000008080"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("0P0P0000008080"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("0P0P0000008080"));
            ajouter_plan_horizontal_P(matrice_affichage, 7, PSTR("0Ql`B2@B2@Il80"));
        break;
      case 17 : 
        ecrire_ligne_centree_P(PSTR("18"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 1, PSTR("30\HV2P:38aX60"));
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("10004000100040"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("10004000100040"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("10004000100040"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("10004000100040"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("10004000100040"));
            ajouter_plan_horizontal_P(matrice_affichage, 7, PSTR("30\HV2P:38aX60"));
        break;
      case 18 : 
        ecrire_ligne_centree_P(PSTR("19"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 1, PSTR("61X8b3P>2HP\30"));
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("40000104000010"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("40000104000010"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("40000104000010"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("40000104000010"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("40000104000010"));
            ajouter_plan_horizontal_P(matrice_affichage, 7, PSTR("61X8b3P>2HP\30"));
        break;
      case 19 : 
        ecrire_ligne_centree_P(PSTR("20"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 1, PSTR("81l@J2@B2`Al04"));
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("800080000P0004"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("800080000P0004"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("800080000P0004"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("800080000P0004"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("800080000P0004"));
            ajouter_plan_horizontal_P(matrice_affichage, 7, PSTR("81l@J2@B2`Al04"));
        break;
    }
    break;
  case 34 : 
    ecrire_ligne_centree_P(PSTR("GIF - Cube 2"), 12, true);
    nb_motifs = 32;
    switch(motif_actuel)
    {
      case 0 : 
        ecrire_ligne_centree_P(PSTR("01"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("000?Q48Q4?P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("0008P00008P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("0008P00008P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("0008P00008P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("000?Q48Q4?P000"));
        break;
      case 1 : 
        ecrire_ligne_centree_P(PSTR("02"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("000?Q48Q4?P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("0008P00008P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("0008P00008P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("0008P00008P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("000?Q48Q4?P000"));
        break;
      case 2 : 
        ecrire_ligne_centree_P(PSTR("03"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("0087348Q670P00"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("00802000200P00"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("00802000200P00"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("00802000200P00"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("0087348Q670P00"));
        break;
      case 3 : 
        ecrire_ligne_centree_P(PSTR("04"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("0087348Q670P00"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("00802000200P00"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("00802000200P00"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("00802000200P00"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("0087348Q670P00"));
        break;
      case 4 : 
        ecrire_ligne_centree_P(PSTR("05"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("00@51\@A\50@00"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("00@000@@000@00"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("00@000@@000@00"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("00@000@@000@00"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("00@51\@A\50@00"));
        break;
      case 5 : 
        ecrire_ligne_centree_P(PSTR("06"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("00P7168S470800"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("00P00202000800"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("00P00202000800"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("00P00202000800"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("00P7168S470800"));
        break;
      case 6 : 
        ecrire_ligne_centree_P(PSTR("07"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("00P7168S470800"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("00P00202000800"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("00P00202000800"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("00P00202000800"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("00P7168S470800"));
        break;
      case 7 : 
        ecrire_ligne_centree_P(PSTR("08"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("000?Q48Q4?P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("0008P00008P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("0008P00008P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("0008P00008P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("000?Q48Q4?P000"));
        break;
      case 8 : 
        ecrire_ligne_centree_P(PSTR("09"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("000?Q48Q4?P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("0008P00008P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("0008P00008P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("0008P00008P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("000?Q48Q4?P000"));
        break;
      case 9 : 
        ecrire_ligne_centree_P(PSTR("10"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("000?Q48Q4?P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("0008P00008P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("0008P00008P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("0008P00008P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("000?Q48Q4?P000"));
        break;
      case 10 : 
        ecrire_ligne_centree_P(PSTR("11"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("0087348Q670P00"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("00802000200P00"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("00802000200P00"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("00802000200P00"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("0087348Q670P00"));
        break;
      case 11 : 
        ecrire_ligne_centree_P(PSTR("12"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("0087348Q670P00"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("00802000200P00"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("00802000200P00"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("00802000200P00"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("0087348Q670P00"));
        break;
      case 12 : 
        ecrire_ligne_centree_P(PSTR("13"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("00@51\@A\50@00"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("00@000@@000@00"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("00@000@@000@00"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("00@000@@000@00"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("00@51\@A\50@00"));
        break;
      case 13 : 
        ecrire_ligne_centree_P(PSTR("14"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("00P7168S470800"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("00P00202000800"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("00P00202000800"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("00P00202000800"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("00P7168S470800"));
        break;
      case 14 : 
        ecrire_ligne_centree_P(PSTR("15"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("00P7168S470800"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("00P00202000800"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("00P00202000800"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("00P00202000800"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("00P7168S470800"));
        break;
      case 15 : 
        ecrire_ligne_centree_P(PSTR("16"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("000?Q48Q4?P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("0008P00008P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("0008P00008P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("0008P00008P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("000?Q48Q4?P000"));
        break;
      case 16 : 
        ecrire_ligne_centree_P(PSTR("17"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("000?Q48Q4?P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("0008P00008P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("0008P00008P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("0008P00008P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("000?Q48Q4?P000"));
        break;
      case 17 : 
        ecrire_ligne_centree_P(PSTR("18"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("000?Q48Q4?P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("0008P00008P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("0008P00008P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("0008P00008P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("000?Q48Q4?P000"));
        break;
      case 18 : 
        ecrire_ligne_centree_P(PSTR("19"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("0087348Q670P00"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("00802000200P00"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("00802000200P00"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("00802000200P00"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("0087348Q670P00"));
        break;
      case 19 : 
        ecrire_ligne_centree_P(PSTR("20"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("0087348Q670P00"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("00802000200P00"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("00802000200P00"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("00802000200P00"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("0087348Q670P00"));
        break;
      case 20 : 
        ecrire_ligne_centree_P(PSTR("21"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("00@51\@A\50@00"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("00@000@@000@00"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("00@000@@000@00"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("00@000@@000@00"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("00@51\@A\50@00"));
        break;
      case 21 : 
        ecrire_ligne_centree_P(PSTR("22"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("00P7168S470800"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("00P00202000800"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("00P00202000800"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("00P00202000800"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("00P7168S470800"));
        break;
      case 22 : 
        ecrire_ligne_centree_P(PSTR("23"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("00P7168S470800"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("00P00202000800"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("00P00202000800"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("00P00202000800"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("00P7168S470800"));
        break;
      case 23 : 
        ecrire_ligne_centree_P(PSTR("24"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("000?Q48Q4?P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("0008P00008P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("0008P00008P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("0008P00008P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("000?Q48Q4?P000"));
        break;
      case 24 : 
        ecrire_ligne_centree_P(PSTR("25"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("000?Q48Q4?P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("0008P00008P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("0008P00008P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("0008P00008P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("000?Q48Q4?P000"));
        break;
      case 25 : 
        ecrire_ligne_centree_P(PSTR("26"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("000?Q48Q4?P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("0008P00008P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("0008P00008P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("0008P00008P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("000?Q48Q4?P000"));
        break;
      case 26 : 
        ecrire_ligne_centree_P(PSTR("27"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("0087348Q670P00"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("00802000200P00"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("00802000200P00"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("00802000200P00"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("0087348Q670P00"));
        break;
      case 27 : 
        ecrire_ligne_centree_P(PSTR("28"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("0087348Q670P00"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("00802000200P00"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("00802000200P00"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("00802000200P00"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("0087348Q670P00"));
        break;
      case 28 : 
        ecrire_ligne_centree_P(PSTR("29"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("00@51\@A\50@00"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("00@000@@000@00"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("00@000@@000@00"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("00@000@@000@00"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("00@51\@A\50@00"));
        break;
      case 29 : 
        ecrire_ligne_centree_P(PSTR("30"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("00P7168S470800"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("00P00202000800"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("00P00202000800"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("00P00202000800"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("00P7168S470800"));
        break;
      case 30 : 
        ecrire_ligne_centree_P(PSTR("31"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("00P7168S470800"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("00P00202000800"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("00P00202000800"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("00P00202000800"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("00P7168S470800"));
        break;
      case 31 : 
        ecrire_ligne_centree_P(PSTR("32"), 2, false);
            ajouter_plan_horizontal_P(matrice_affichage, 2, PSTR("000?Q48Q4?P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 3, PSTR("0008P00008P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 4, PSTR("0008P00008P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 5, PSTR("0008P00008P000"));
            ajouter_plan_horizontal_P(matrice_affichage, 6, PSTR("000?Q48Q4?P000"));
        break;
    }
    break;
    case 35 : 
    ecrire_ligne_centree_P(PSTR("Tests"), 5, true);
    nb_motifs = 3;
    switch(motif_actuel)
    {
      case 0 : 
        ecrire_ligne_centree_P(PSTR("FULL"), 4, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("ooooooooooooo7"));
            ajouter_plan_P(matrice_affichage, 1, PSTR("ooooooooooooo7"));
            ajouter_plan_P(matrice_affichage, 2, PSTR("ooooooooooooo7"));
            ajouter_plan_P(matrice_affichage, 3, PSTR("ooooooooooooo7"));
            ajouter_plan_P(matrice_affichage, 4, PSTR("ooooooooooooo7"));
            ajouter_plan_P(matrice_affichage, 5, PSTR("ooooooooooooo7"));
            ajouter_plan_P(matrice_affichage, 6, PSTR("ooooooooooooo7"));
            ajouter_plan_P(matrice_affichage, 7, PSTR("ooooooooooooo7"));
            ajouter_plan_P(matrice_affichage, 8, PSTR("ooooooooooooo7"));
        break;
      case 1 : 
        ecrire_ligne_centree_P(PSTR("1 LED"), 5, false);
            ajouter_plan_P(matrice_affichage, 0, PSTR("08000000000000"));
        break;
      case 2 : 
        ecrire_ligne_centree_P(PSTR("OFF"), 3, false);
        break;
    }
    break;    

  } //switch(groupe_actuel)

  copier_matrice(matrice_affichage, matrice_backup);

  ecrire_numero(groupe_actuel+1, nb_groupes, true);
  ecrire_numero(motif_actuel+1,  nb_motifs,  false);

  autoriser_affichage = true;
}
