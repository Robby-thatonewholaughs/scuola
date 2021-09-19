/*
Christian Ruzza                   3CI                          25/11/2020
Esercizio numero 1 esercitazioni pseudocodifica
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n;
  printf("Inserisci un numero ---> ");
  scanf("%d",&n);
  while(n>10){
    printf("%d \n", n);
    n=n-3;
  }
  return 0;
}
