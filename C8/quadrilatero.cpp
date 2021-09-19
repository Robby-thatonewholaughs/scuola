#include <stdio.h>
#include <stdlib.h>

/* Lorenzo Lingesso - Christian Ruzza 3CI 24/11/2020
Quadrilatero
Scrivi un programma che legge in input il valore di due lati di un quadrilatero,
individua se si tratta di un quadrato o di un rettangoloe ne calcola il perimetro e l'area. */

int main()
{
	float lato1, lato2, area, perimetro;
	do
	{
		system("cls");
		printf("Inserisci il primo lato --> ");
		scanf("%f",&lato1);
	}while(lato1<=0);

	do
	{
		system("cls");
		printf("Inserisci il primo lato --> %.2f",lato1);
		printf("\nInserisci il secondo lato --> ");
		scanf("%f",&lato2);
	}while(lato2<=0);

	if(lato1==lato2)
	{
		area=lato1*lato1;
		perimetro=lato1*4;
		printf("Il quadrilatero e' un quadrato\nL'area misura: %.2f cm\nIl perimetro misura: %.2f cm",area,perimetro);
	}else
	{
		area=lato1*lato2;
		perimetro=(lato1+lato2)*2;
		printf("Il quadrilatero e' un rettangolo\nL'area misura: %.2f cm\nIl perimetro misura: %.2f cm",area,perimetro);
	}
}
