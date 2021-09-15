/*
Christian Ruzza 3CI 11/02/2020
Progettare l’algoritmo che dopo aver acquisito 20 numeri interi e positivi nel vettore LATO, ognuno rappresentante il lato di un quadrato,
provvede a calcolare il perimetro e l’area di ciascuno di essi.
I valori calcolati devono essere posti in due distinti vettori, PERIMETRO e AREA, ciascuno sempre di 20 elementi.
Dopo tale calcolo, l’algoritmo visualizzerà in forma tabellare i valori relativi ai 20 quadrati,
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define DIM 20

void input_lato(double lato[]) //funzione che prende in input i lati dei 20 quadrati
{
  int i=0;
  for(i=0;i<DIM;i++)
  {
    do
    {
        system("cls");
        printf("Inserisci il %d lato ---> ",i+1);
        scanf("%lf",&lato[i]);
    }while(lato[i]<0);
  }
}

void calcolo_perimetro(double lato[],double perimetro[]) //funzione utile al calcolo del perimetro dei 20 quadrati
{
  int i=0;
  for(i=0;i<DIM;i++)
  {
    perimetro[i]=lato[i]*4;
  }
}

void calcolo_area(double lato[],double area[]) //funzione utile al calcolo dell'area dei 20 quadrati
{
  int i=0;
  for(i=0;i<DIM;i++)
  {
    area[i]=lato[i]*lato[i];
  }
}

void output_risultato(double lato[],double perimetro[],double area[]) //funzione utile a dare in output i risultati delle operazioni precedenti
{
  int i=0;
  printf("Lato    Perimetro    Area\n");
  for(i=0;i<DIM;i++)
  {
    printf("\n%7.1f %7.1f %7.1f ",lato[i],perimetro[i],area[i]);
  }
}

int main()
{
  double lato[DIM],perimetro[DIM],area[DIM]; //definizione di tre array da 20 elementi utili a memorizzare i 20 lati, aree e perimetri dei quadrati
  input_lato(lato); //richiamo della funzione utile a prendere in input i lati dei quadrati
  calcolo_perimetro(lato,perimetro); //richiamo alla funzione che calcola il perimetro
  calcolo_area(lato,area); //richiamo alla funzione che calcola l'area
  output_risultato(lato,perimetro,area);//richiamo alla funzione di output dei risultati
  getch();
}
