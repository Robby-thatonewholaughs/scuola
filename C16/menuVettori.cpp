/*
Christian Ruzza 3CI 18/02/2021

Scrivere un programma che:
- definisce un vettore di interi  di dimensione a piacere
- definisce una variabile di stato per per indicare se il vettore Ã¨ stato caricato  o meno.
- visualizza un menu che permette di scegliere i valori 1,2,3,4,5
-In base al valore scelto:
se scelto 1: effettua il caricamento del vettore e la variabile di stato viene posta a 1
se scelto 2: visualizza il contenuto del vettore (se il vettore era caricato)  oppure
                    richiede il caricamento del vettore  (se il vettore non era caricato)
se scelto 3: effettua la ricerca del primo elemento :
                    ovvero, passato un numero intero input, ricerca quel numero nel vettore e ritorna un messaggio
                     con:
                    - la posizione del primo elemento del vettore che contiene quel numero (se trovato)
                    -  l'indicazione che quel numero non Ã¨ presente nel vettore
se scelto 4: effettua la ricerca di tutti gli elementi:
                    ovvero, passato un numero intero input, ricerca quel numero nel vettore e ritorna un messaggio
                     con:
                    - le posizioni degli elementi del vettore che contengono quel numero(se trovati)
                    - l'indicazione che quel numero non Ã¨ presente nel vettore
se scelto 5: effettua l'uscita da programma
*/
#include <stdio.h>
#include <stdlib.h>
#define DIM 10

void menu(int *scelta) //funzione utile per il menu
{
    do
    {
        printf("VETTORI");
        printf("\n1)Carica il vettore");
        printf("\n2)Visualizza il vettore");
        printf("\n3)Cerca un valore");
        printf("\n4)Cerca piu' valori");
        printf("\n5)Esci");
        printf("\nScegli l'opzione ---> ");
        scanf("%d",scelta);
    }while(*scelta<1||*scelta>5);
}

void carica_vettore(int vet[DIM],int *flag) //funzione utile a caricare al vettore
{
    int i = 0;
    for(i=0;i<DIM;i++)
    {
        printf("\nInserisci il %d elemento del vettore ---> ",i+1);
        scanf("%d",&vet[i]);
    }
    *flag = 1;
}

void visualizza_vettore(int vet[DIM]) //funzione utile alla visualizzazione del vettore, viene passato il parametro vet che contiene i dati del vettore
{
    int i=0;
    for(i=0;i<DIM;i++)
    {
        printf("\nL'elemento %d del vettore ha valore %d\n",i+1,vet[i]);
    }
}

void cerca_valore(int vet[DIM]) //funzione utile a cercare un valore nel vettore, viene passato il parametro vet che contiene i dati del vettore
{
    int cerca = 0;
    int i = 0;
    int flag = 0;
    printf("\nInserisci il valore che vuoi cercare all'interno del vettore ---> ");
    scanf("%d",&cerca);
    for(i=0;i<DIM;i++)
    {
      if(cerca==vet[i])
      {
        printf("\nL'elemento cercato si trova nell'elemento %d del vettore",i+1);
        flag=1;
        i=DIM;
      }
    }
    if(flag==0)
      {
        printf("\nL'elemento cercato non si trova all'interno del vettore");
      }
}

void cerca_piu_valori(int vet[DIM], int valore) //funzione utile a cercare un valore nel vettore in multiple posizioni, viene passato il parametro vet che contiene i dati del vettore e il parametro valore che contiene il valore da cercare
{
	int i, flag=0;
	for(i=0;i<DIM;i++)
	{
		if(valore==vet[i])
		{
			printf("Valore %d trovato nella posizione %d\n", valore, i+1);
			flag=1;
		}
	}
	if(flag==0)
  {
    printf("Valore non trovato!\n");
  }
}

int main()
{
    int flag = 0;
    int vet[DIM];
    int scelta = 0;
    int valore = 0;
    do
    {
      system("cls");
      menu(&scelta);
      switch(scelta)
      {
          case 1:
          {
              carica_vettore(vet,&flag); //richiamo alla funzione di caricamento del vettore
              break;
          }
          case 2:
          {
              if(flag==1)
              {
                  visualizza_vettore(vet); //richiamo alla funzione di visualizzazione del vettore
              }else
              {
                  printf("\nPurtroppo il vettore e' vuoto, si prega di riempirlo  attraverso la prima opzione");
              }
              system("PAUSE");
              break;
          }
          case 3:
          {
            if(flag==1)
              {
                  cerca_valore(vet); //richiamo alla funzione utile a cercare un valore nel vettore
              }else
              {
                  printf("\nPurtroppo il vettore e' vuoto, si prega di riempirlo  attraverso la prima opzione\n");
              }
              system("PAUSE");
              break;
          }
          case 4:
          {
            if(flag==0)
      			{
      				printf("\nPurtroppo il vettore e' vuoto, si prega di riempirlo  attraverso la prima opzione\n");
      			}else
      			{
      				printf("Inserisci il valore da cercare con stampe multiple--> "); //presa in input del valore da cercare
      				scanf("%d",&valore);
      				cerca_piu_valori(vet, valore); //richiamo alla funzione utile a cercare un valore nel vettore in multiple posizioni
      			}
      			system("pause");
      			break;
          }
      }
    }while(scelta!=5);
}
