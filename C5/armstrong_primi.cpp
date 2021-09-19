/*
Christian Ruzza                      3CI                            11/12/2020
Questo programma attraverso un menu e delle funzioni, trova i numeri
primi e quelli di armstrong a scelta dell'utente
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

int menu()		//Funzione per il menu
{
	int scelta;
	printf("1)Trovare i numeri primi\n");
	printf("2)Trovare i numeri di Armstrong\n");
	printf("3)Esci\n");
	printf("Inserisci la tua scelta ---> ");
	scanf("%d",&scelta);
	return(scelta);
}

void primi(int numero)		//Procedura che calcola i numeri primi
{
	int i, cp;
	cp=0;
	printf("I numeri primi sono: ");

	do
	{
		for(i=2;i<=numero;i++)
		{
			if(numero%i == 0)
				cp++;
		}
		if(cp==1&&numero>3)
			printf("%d, ",numero);
		if(numero==2)
			printf("%d.\n",numero);
		numero--;
		cp=0;
	}while(numero>=0);
	getch();

}

void armstrong(int numero)		//Procedura che calcola se il numero  di Armstrong
{
	int m, c, d, u;
	m=numero/1000;
	c=(numero-(m*1000))/100;
	d=(numero-(m*1000)-(c*100))/10;
	u=(numero-(m*1000)-(c*100)-(d*10));

	m = pow(m,3);
	c = pow(c,3);
	d= pow(d,3);
	u = pow(u,3);


	if(m+c+d+u==numero)
		printf("Il numero %d e' un numero di Armstrong\n",numero);
	else
		printf("Il numero %d NON e' un numero di Armstrong\n",numero);
	getch();
}

int main()
{
	int scelta, numero;

	do
	{
		do
		{
			system("cls");
			scelta = menu();						//Richiamo della funzione menu
		}while(scelta<1||scelta>3);

		switch(scelta)
		{
			case 1:
			{
				do
				{
					system("cls");
					printf("Inserisci il numero finale ---> ");
					scanf("%d",&numero);
				}while(numero<2);
				primi(numero);				//Richiama il sottoprogramma numeri primi
				break;
			}
			case 2:
			{
				do
				{
					system("cls");
					printf("Inserisci il numero ---> ");
					scanf("%d",&numero);
				}while(numero<1||numero>5000);
				armstrong(numero);			//Richiama il sottoprogramma numeri Armstrong
				break;
			}
		}
	}while(scelta!=3);
}
