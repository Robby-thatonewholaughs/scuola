/*
Christian Ruzza 4CI
Esercizio:Realizzare un algoritmo che produca lo scontrino di cassa dell’acquisto di uno o più libri, per i clienti della libreria “Tutto Libri”.
L’algoritmo, dopo aver ricevuto il numero di libri che il cliente vuole comprare, acquisisce altrettanti valori, cioè gli importi di tutti i libri, 
che sommati forniranno l’importo totale della spesa.Su questo totale, per via della campagna promozionale, è applicato uno sconto da calcolare e da 
detrarre, così formato: fino a 50,00 euro lo sconto è del 5%, da 50,01 a 150,00 euro lo sconto è del 10%, oltre lo sconto è del 15%.
L’algoritmo visualizza l’importo totale della spesa, il valore dello sconto che viene applicato, e l’importo di spesa finale effettivamente 
pagato, tutti espressi in euro.
*/

#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <math.h>

//funzione che ritorna in output lo sconto in base all'importo passato in input
float getSconto(float importo)
{
 float sconto;
 if (importo<50)
	{
		printf("\n\nSiccome ha pagato meno di 50 euro, c'e lo sconto del 5%\n");
		sconto=importo*5/100;		
	}   
 if (importo>=50.01 && importo<=150)
	{
		printf("\n\nhai pagato tra i 50 euro e i 150 euro, c'e lo sconto del 10%\n");
		sconto=importo*10/100;	
	}	
 if(importo>150.01)
	{
		printf("\n\nDato che ha pagato piu di 150 euro, c'e lo sconto del 15%\n");
		sconto=importo*15/100;
	}
	return (sconto);
}

int main()
{
	int nl, contaprezzo; //nl sono il numero di libri
	float prezzoScontato, prezzo, somprezzo, sconto;
	
	printf("inserire il numero di libri comprati --> ");
	scanf("%d", &nl);
	contaprezzo=0;
	do
	{
		
		printf("\nInserire il prezzo del libro --> ");
		scanf("%f", &prezzo);
		somprezzo=somprezzo+prezzo;  //somma dei prezzi inseriti
		contaprezzo=contaprezzo+1;  //conta quante volte ho inserito il prezzo
		
	}while(contaprezzo<nl);
	sconto=getSconto (somprezzo);
	prezzoScontato=somprezzo-sconto;
	printf("\nIl prezzo totale= %.2f Euro, sconto di= %.2f, prezzo scontato di= %.2f Euro\n", somprezzo,sconto,prezzoScontato);
}

