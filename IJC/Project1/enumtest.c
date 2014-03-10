// Encoding: ISO-8859-2 
/*
 * Soubor:  enumtest.c - prelozeno gcc
 * Datum:   7.3.2006
 * Autor:   Petr Zemek, FIT, xzemek02@stud.fit.vutbr.cz
 * Projekt: IJC - DU1
 * Popis:   IJC - DU1 a)
 *          Testovaci program - testuje funkcnost enumdny.c a error.c 
 */

#include <stdio.h>
#include <locale.h>
#include "enumdny.h" /* Tisk a cteni hodnot vyctove typu */
#include "error.h"   /* Tisk chybovych zprav */

/**
 * Hlavni program - podle zadani IJC - DU1 a)
 */
int main(void) { /* test funkc� - NEM�NIT!!! */
  enum dny den;  
  
  // nastaveni ceske lokalizace
  char *l = setlocale(LC_ALL,"cs_CZ");  
  if (l == NULL)
    Error("setlocale: Nelze nastavit �eskou lokalizaci\n");  
    
  den = ReadDay();           // �te Po, Pond�l�, Pondeli, PONdeli, ....  
  PrintDayShort(den);        // tiskne Po
  printf("\n"); 
  PrintDayShortASCII(den);   // tiskne Po
  printf("\n"); 
  PrintDayLong(den);         // tiskne Pond�l�
  printf("\n"); 
  PrintDayLongASCII(den);    // tiskne Pondeli
  printf("\n\n");
  
  for( den = Po; den < 10; den++ ) { /* �mysln� chyba */
    PrintDayShortASCII(den);
    printf("\n");
  }
  
  return 0;
}

/* Konec souboru enumtest.c */
