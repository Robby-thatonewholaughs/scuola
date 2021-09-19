/*
Christian Ruzza                    3CI                           27/11/2020
Questa e' una calcolatrice capace di eseguire le 4 operazioni di base
sia con numeri decimali che con numeri interi
*/
#include <stdio.h>
#include <stdlib.h>
#include <CMATH>
#include <conio.h>
#include <windows.h>

void addizione()
{
  double n1 = 0;
  double n2 = 0;
  system("cls");
  printf("Inserisci il primo numero ---> ");
  scanf("%lf",&n1);
  printf("Inserisci il secondo numero ---> ");
  scanf("%lf",&n2);
  r=n1+n2;
  printf("Il risultato e' %f ",r);
  getch();
}

void sottrazione()
{
  double n1 = 0;
  double n2 = 0;
  system("cls");
  printf("Inserisci il primo numero ---> ");
  scanf("%lf",&n1);
  printf("Inserisci il secondo numero ---> ");
  scanf("%lf",&n2);
  r=n1-n2;
  printf("Il risultato e' %f ",r);
}

void moltiplicazione()
{
  double n1 = 0;
  double n2 = 0;
  system("cls");
  printf("Inserisci il primo numero ---> ");
  scanf("%lf",&n1);
  printf("Inserisci il secondo numero ---> ");
  scanf("%lf",&n2);
  r=n1*n2;
  printf("Il risultato e' %f ",r);
  getch();
}

void divisione()
{
  double n1 = 0;
  double n2 = 0;
  system("cls");
  printf("Inserisci il dividendo ---> ");
  scanf("%lf",&n1);
  printf("Inserisci il divisore ---> ");
  scanf("%lf",&n2);
  r=n1/n2;
  printf("Il risultato e' %f ",r);
  getch();
}

int main()
{
  int s;
  double n1;
  double n2;
  double r;
  do{
    //Visualizzazione menu' e scelta
    do{
      system("cls");
      printf("Calcolatrice \n\n");
      printf("1) Addizione \n\n");
      printf("2) Sottrazione \n\n");
      printf("3) Moltiplicazione\n\n");
      printf("4) Divisione\n\n");
      printf("5) Esci\n\n");
      printf("La tua scelta ---> ");
      scanf("%d",&s);
      }while(s<1||s>5);
      switch (s)
      {
        //Addizione
        case 1: {
          addizione();
          break;
        }
        //Sottrazione
        case 2: {
          sottrazione();
          break;
        }
        //Moltiplicazione
        case 3: {
          moltiplicazione();
          break;
        }
        //Divisione
        case 4: {
          divisione();
          break;
        }
      }
    }while(s!=5);
}
