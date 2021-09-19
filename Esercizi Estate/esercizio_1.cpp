/*
Christian Ruzza 4-CI 

Scrivere un programma che chieda in input una parola (cioè una stringa di caratteri) 
e dica se la parola è palindroma, ovvero leggibile nello stesso modo da destra a sinistra e
viceversa (es. ANNA).
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#define DIM 15
#define ERR -1
#define SUCC 0

/*
Funzione che inverte la stringa immessa precedentemente nel main, la mette in una seconda stringa e controlla se è palindroma comparande queste due
stringa = stringa di partenza
*/
int controlloPalindroma(char stringa[DIM])
{
	int isPalindroma, i, j;
	char comparaStringa[DIM];
	for(i=strlen(stringa), j=0; i>=0 ; i--, j++)
  {
		comparaStringa[j]=stringa[i-1];					//-1 perché si parte da 0
  }
	if(strcmp(stringa,comparaStringa)==SUCC)
  {
		isPalindroma=SUCC;
  }
	else
  {
		isPalindroma=ERR;
  }
}

int main()
{
	char stringa[DIM];
	int isPalindroma;
	printf("Inserisci la parola --> ");
	scanf("%s",stringa);
	isPalindroma=controlloPalindroma(stringa);
	if(isPalindroma==SUCC)
  {
		printf("\nLa parola %s e' palindroma",stringa);
  }
	else
  {
		printf("\nLa parola %s NON e' palindroma",stringa);
  }
}
