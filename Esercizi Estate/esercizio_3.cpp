/*
Christian Ruzza 4CI

Scrivere un programma che realizzi il gioco del Master Mind. Bisogna indovinare in 10 tentativi
un numero di 4 cifre pensato dal computer. Il numero in realtà sarà composto da 4 cifre singole
contenute in un vettore di tipo int di 4 posizioni. Ad ogni tiro il computer risponde indicando quante
cifre giuste al posto giusto e quante cifre giuste al posto sbagliato ci sono nel vostro numero.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define DIM 4

/*
Sottoprogramma che randomizza l'array numeri
numeri = array randomizzato dal pc
*/
void randomizzaArray(int numeri[DIM])
{
	srand(time(0));
	for(int i=0;i<DIM;i++)
  {
		numeri[i] = rand()%(9 - 1 + 1) + 1;			//range da 1 a 9
  }
}

/*
Sottoprogramma che fa effettuare la gicoata all'utente
giocata = array nel quale l'utente effettuerà la giocata
*/
void effettuaGiocata(int giocata[DIM])
{
	for(int j=0;j<DIM;j++)
		{
			do
			{
				printf("\nNumero #%d--> ",j+1);
				scanf("%d",&giocata[j]);
			}while(giocata[j]<0||giocata[j]>9);
		}
}

/*
Funzione che controlla quante posizioni giuste e sbagliate ci sono nella giocata dell'utente, confrontando i due array precedenti
Ritorna quante posizioni giuste ha inserito l'utente. 4 = vincita nel main
*/
int controlloGiocata(int numeri[DIM], int giocata[DIM])
{
	int contatore=0, contatoreP=0, temp[DIM];					//temp = array temporaneo che serve per indicare quali numeri nell'array numeri sono stati indovinati e se nella loro posizione o meno
	for(int i=0;i<DIM;i++)
  {
		temp[i]=numeri[i];
  }
	for(int i=0;i<DIM;i++)
	{
		for(int j=0;j<DIM;j++)
		{		
			if(giocata[i]==temp[j]&&i==j)
			{
				contatoreP++;
				temp[j]=10;
			}
		}
	}		
	for(int i=0;i<DIM;i++)
	{
		for(int j=0;j<DIM;j++)
		{		
			if(giocata[i]==temp[j]&&i!=j)
			{
				contatore++;
				temp[j]=11;
			}
		}
	}
	printf("\nPosozioni giuste --> %d\nPosizioni sbagliate --> %d\n",contatoreP,contatore);
	system("pause");
	return contatoreP;
}
/*
Sottoprogramma che stampa l'array numeri (soluzione)
*/
void soluzione(int numeri[DIM])
{
	for(int i=0;i<DIM;i++)
		printf("%d",numeri[i]);
}

int main()
{
	int numeri[DIM], giocata[DIM], contatore;
	randomizzaArray(numeri);
	for(int i=0;i<10;i++)
	{
		effettuaGiocata(giocata);
		contatore=controlloGiocata(numeri,giocata);
		if(contatore==4)
		{
			printf("\nHAI VINTO!\nLa soluzione era --> ");
			soluzione(numeri);
			return 0;
		}
	}
	printf("\nHAI PERSO!\nLa soluzione era --> ");
	soluzione(numeri);
}
