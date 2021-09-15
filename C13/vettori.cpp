/*
Christian Ruzza 4CI 
Questo programma ha lo scopo di prendere in input 20 numeri reali 
e poi stampare i numeri e i loro quadrati sullo schermo.
*/
#include <stdio.h>
#include <stdlib.h>

void input_numeri(int arr[20]) //questa funzione ha lo scopo di prendere in input i 20 numeri e inserirli in un array
{
  int i = 0;
  for(i = 0; i < 20 ;i++)
  {
    printf("\nInserisci il #%d numero del vettore --> ",i+1);
    scanf("%d",&arr[i]);
  }   
}

void calcola_quad(int arr[20],int arr1[20]) //questa funzione calcola i quadrati di ogni numero e li mette in un secondo array
{
  int i = 0;
  for(i = 0; i < 20 ;i++)
  {
    arr1[i] = arr[i] * arr[i];
  }  
}

void stampa_risultati(int arr[20], int arr1[20]) //questa funzione ha lo scopo di stampare i risultati
{
  int i = 0;
  printf("\nRisultati:\n");
  for(i = 0; i < 20; i++)
  {
    printf("\n%2d   |   %2d\n",arr[i],arr1[i]);
  }
}

int main()
{
  int arr[20];
  int arr1[20];
  input_numeri(arr);
  printf("-----------------------------");
  calcola_quad(arr,arr1);
  stampa_risultati(arr,arr1);
}
