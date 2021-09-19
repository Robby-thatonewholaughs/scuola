/*
Christian Ruzza                   3CI                          25/11/2020
Esercizio numero 3 esercitazioni pseudocodifica
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n1;
  int n2;
  printf("Inserisci un primo numero ---> ");
  scanf("%d",&n1);
  printf("Inserisci un secondo numero ---> ");
  scanf("%d",&n2);
  while(n1<50){
    printf("%d \n", n1);
    n1=n1+n2;
  }
  return 0;
}
