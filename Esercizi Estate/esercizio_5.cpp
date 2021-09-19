/*
Christian Ruzza - Lorenzo Lingesso 01/09/2021
Questo programma ha lo scopo di inserire randomicamente dei numeri in una matrice di
n righe ed m colonne e di trovare il numero minimo e quello massimo di ogni
riga e successivamente effettuare la media dei numeri presenti in ogni colonna
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIMRIGHE 10
//potrebbe essere usata una sola costante dato che i loro valori sono uguali
//ma ne vengono usate due in modo che anche in evenienza di modificare il
//programma per poter utilizzare due dimensioni diverse esso funzioni
#define DIMCOL 10

void riempimatrice(int matrice[DIMRIGHE][DIMCOL])
{
    int i = 0;
    int j = 0;
    srand(time(0));
    for (i = 0; i < DIMRIGHE; i++) {
      for (j = 0; j < DIMCOL; j++) {
          matrice[i][j] = rand()%100;
      }
    }
}

void maxRiga(int matrice[DIMCOL][DIMRIGHE])
{
  int max = 0;
  int i = 0;
  int j = 0;
  for (i = 0; i < DIMRIGHE; i++) {
    max = 0;
    for (j = 0; j < DIMCOL; j++) {
      if (matrice[i][j]>max) {
        max = matrice[i][j];
      }
    }
    printf("\nIl numero piu' grande nella riga #%d e' :%d\n",i+1,max);
  }
}

void minimoMat(int matrice[DIMRIGHE][DIMCOL])
{
  int min = 0;
  int i = 0;
  int j = 0;
  min = 101;
  for (i = 0; i < DIMRIGHE; i++) {
    for (j = 0; j < DIMCOL; j++) {
      if (matrice[i][j]<min) {
        min = matrice[i][j];
      }
    }
  }
  printf("\nIl numero piu' piccolo della matrice e' :%d",min );
}

void mediaCol(int matrice[DIMRIGHE][DIMCOL])
{
  float media = 0;
  int i = 0;
  int j = 0;
  for (i = 0; i < DIMCOL; i++) {
    media = 0;
    for (j = 0; j < DIMRIGHE; j++) {
      media = media + matrice[i][j];
    }
    media = media/DIMRIGHE;
    printf("\nLa media nella colonna #%d e' :%2.2f\n",i+1,media);
  }
}

int main()
{
  int matrice[DIMRIGHE][DIMCOL];
  riempimatrice(matrice);
  maxRiga(matrice);
  printf("\n---------------------\n");
  mediaCol(matrice);
  printf("\n---------------------\n");
  minimoMat(matrice);
}
