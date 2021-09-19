/*
Christian Ruzza 3CI

Scrivere un programma che permetta all'utente di inserire un'intera frase. Il programma
successivamente visualizzi il numero di parole che compone la frase. Si supponga che una frase sia
costituita di parole, dove una parola è una sequenza di caratteri diversi dallo spazio e delimitata da
uno o piu' spazi a destra e sinistra. Uno o piu' spazi possono aprire o chiudere la frase.
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#define DIM 100

int contaParole(char frase[DIM])
{
	int i, contatore=0;
	for(i=0;i<strlen(frase);i++)
	{
		if(frase[i]<'A'||frase[i]>'Z')
    {
			contatore++;
    }
	}
	return contatore;
}

int main()
{
	char frase[DIM], nParole;
	printf("Inserisci la frase --> ");
	gets(frase);
	nParole=contaParole(frase);
	printf("Le parole nella frase '%s' sono: %d",frase,nParole);
}
