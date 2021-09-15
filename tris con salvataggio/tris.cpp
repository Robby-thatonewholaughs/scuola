//Christian Ruzza 4CI

/*
Realizzare un programma in C Language che implementi il gioco del tris.
Nella scacchiera (3x3) si sfidano due giocatori (il Giocatore A inserisce
il simbolo 'X' , il Giocatore B inserisce il simbolo 'O' ) che inseriscono le loro mosse
in sequenza, fino a che non si raggiunge la vittoria di una delle due squadre.

Inoltre, si potra' salvare e riprendere successivamente la partita grazie alla scrittura-lettura su file
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>

#define DIM 3
#define ERR 1
#define SUCC 0

//procedura che inizializza la matrice
void inizializza(int griglia[DIM][DIM])
{
	int gx,gy;

	for (gx=0; gx<DIM; gx++)
		{
			for (gy=0; gy<DIM; gy++)
				griglia[gx][gy] = -1;
		}
}

//funzione che fa fare la giocata al giocatore e ritorna un valore di errore o successo
int giocata(int griglia[DIM][DIM], int *giocatore)
{
	int gy, gx, valido;
	FILE *fp;

	fp=fopen("partita.txt","a");

	printf("\n");
	printf ("Giocatore %d inserisci le coordinate X --> ", *giocatore);
	scanf("%d",&gx);
	printf ("Giocatore %d inserisci le coordinate Y --> ", *giocatore);
	scanf("%d",&gy);
	printf("\n");

		if ((griglia[gx][gy] != -1) || (gx>2) || (gy>2) || (gx<0) || (gy<0))
		{
			valido = 0;
			if ((gx>2) || (gy>2) || (gx<0) || (gy<0))
			{
					printf("Coordinate non valide\n");
			}
			else
			{
				printf("La cella e' occupata scegli un'altra\n");
			}
		}
		else
		{
			fprintf(fp, "%d ", gx);
			fprintf(fp, "%d ", gy);

			fclose(fp);

			valido = 1;
			griglia[gx][gy] = *giocatore;
		}
	return valido;
}

//procedura che riempe con le X e le O in base alla giocata
void riempi(char *simbolo, int griglia[DIM][DIM])
{
	int gx,gy;

		for (gx=0; gx<DIM; gx++)
		{
			for (gy=0; gy<DIM; gy++)
			{
				if (griglia[gx][gy] == -1)
				{
					*simbolo = '#';
				}
				else
				{
					if (griglia[gx][gy] == 0)
						*simbolo = 'X';
					else
						*simbolo = 'O';
				}

				if (gy<2)
					printf ("%c ", *simbolo);
				else
					printf ("%c\n", *simbolo);
			}
		}
}

//funzione che carica la partita da file e ritorna un valore(errore=1, successo=0)
int carica_partita(int griglia[DIM][DIM])
{
	int gx,gy,i=0,tmp_gx=3,tmp_gy=3;
	char simbolo;
	FILE *fp;

	fp=fopen("partita.txt", "r");

	if (fp == 0)
	{
		printf ("Nessun file trovato!");
		return ERR;
	}

	while(!feof(fp))
	{

		fscanf(fp, "%d", &gx);
		fscanf(fp, "%d", &gy);
		if(tmp_gx==gx&&tmp_gy==gy)
			return SUCC;

		if(i%2==0)
			griglia[gx][gy]=0;
		else
			griglia[gx][gy]=1;

		riempi(&simbolo,griglia);
		system("cls");
		tmp_gx=gx;
		tmp_gy=gy;
		i++;
	}


}


int main() {

	int m=0, o=0, turno=0, giocatore, gx, gy, valido, griglia[DIM][DIM];
	char simbolo, carica;
	FILE *fp;

	inizializza(griglia);

	do{
		system("cls");
		printf("Vuoi caricare la partita precedente? S/N --> ");
		scanf(" %c",&carica);
		carica = toupper(carica);
	}while(carica!='S'&&carica!='N');

	if(carica=='S')
		carica_partita(griglia);
	else
		remove("partita.txt");

	for (turno=0; turno<9; turno++)
	{

		if (turno%2==0)
			giocatore = 0;
		else
			giocatore = 1;

		valido = 0;

		while (valido != 1)
		{
			valido=giocata(griglia, &giocatore);
		}

		riempi(&simbolo, griglia);

		if (( ((griglia[0][0]==1) && (griglia[0][1]==1) && (griglia[0][2]==1)) || ((griglia[1][0]==1) && (griglia[1][1]==1) && (griglia[1][2]==1)) || ((griglia[2][0]==1) && (griglia[2][1]==1) && (griglia[2][2]==1)) || ((griglia[0][0]==1) && (griglia[1][1]==1) && (griglia[2][2]==1)) || ((griglia[2][0]==1) && (griglia[1][1]==1) && (griglia[0][2]==1)) ) || ( ((griglia[0][0]==0) && (griglia[0][1]==0) && (griglia[0][2]==0)) || ((griglia[1][0]==0) && (griglia[1][1]==0) && (griglia[1][2]==0)) || ((griglia[2][0]==0) && (griglia[2][1]==0) && (griglia[2][2]==0)) || ((griglia[0][0]==0) && (griglia[1][1]==0) && (griglia[2][2]==0)) || ((griglia[2][0]==0) && (griglia[1][1]==0) && (griglia[0][2]==0)) ))
		{
			printf ("Il giocatore %d ha vinto!\n", giocatore);
			remove("partita.txt");
			return 0;
		}
	}
	printf ("Pareggio\n");
	remove("partita.txt");

}
