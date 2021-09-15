/*
Christian Ruzza 3CI 18/2/21
Scrivere un programma che:
leggere  in un primo vettore i voti riportati da uno studente in diverse materie,
e costruire un nuovo vettore contenente solo i voti sufficienti e stamparne il contenuto */

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define DIM 10

void input(float vet[])//Procedura utile a prendere in input i voti
{
	int i, j;
	
	for(i=0;i<DIM;i++)
	{
		j=i+1;
		do{
			system("cls");
			printf("Inserisci il voto #%d ---> ",j);
			scanf("%f",&vet[i]);
		}while(vet[i]<0||vet[i]>10);
	}
}
/*
 La procedura input ha il compito di prendere in input i voti dello studente
 parametri input:
 //
 parametri output:
 -vet
*/

void output(float vet_suff[DIM], float vet[DIM])//Procedura che visualizza solo i voti sufficienti, stampando anche la posizione in cui si trovano
{
	int i;
	
	printf("I voti sufficienti sono: ");
	
	for(i=0;i<DIM;i++)
	{
		if(vet[i]>=6)
		{
			vet_suff[i]=vet[i];
			printf("%.2f(%d)  ",vet_suff[i], i);
		}
	}
}
/*
 La procedura output serve a mandare in output i voti sufficienti che sono stati presi in input
 Parametri input:
 -vet
 Parametri output:
 -vet_suff
*/

int main()
{
	float vet[DIM], vet_suff[DIM];
	input(vet);//richiamo alla funzione input con passaggio del vettore vet come parametro
	output(vet_suff, vet);//richiamo alla funzione aoutput con passaggio dei vettori vet_suff e vet
}
