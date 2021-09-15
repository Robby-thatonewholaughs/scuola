/*
Christian Ruzza 3CI 18/02/2021

Scrivere un programma che:
- definisce un vettore di interi  di dimensione a piacere
- definisce una variabile di stato per per indicare se il vettore e' stato caricato  o meno.
- visualizza un menu che permette di scegliere i valori 1,2,3,4,5
-In base al valore scelto:
se scelto 1: effettua il caricamento del vettore e la variabile di stato viene posta a 1
se scelto 2: visualizza il contenuto del vettore (se il vettore era caricato)  oppure
                    richiede il caricamento del vettore  (se il vettore non era caricato)
se scelto 3: effettua la ricerca del primo elemento :
                    ovvero, passato un numero intero input, ricerca quel numero nel vettore e ritorna un messaggio
                     con:
                    - la posizione del primo elemento del vettore che contiene quel numero (se trovato)
                    -  l'indicazione che quel numero non e' presente nel vettore
se scelto 4: effettua la ricerca di tutti gli elementi:
                    ovvero, passato un numero intero input, ricerca quel numero nel vettore e ritorna un messaggio
                     con:
                    - le posizioni degli elementi del vettore che contengono quel numero(se trovati)
                    - l'indicazione che quel numero non e' presente nel vettore
se scelto 5: effettua

se scelto 6: effettua

se scelto 7: effettua

se scelto 8: effettua l'uscita da programma
*/

#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define DIM 10
#define DIM1 DIM*2

void menu(int *scelta) //funzione utile per il menu
{
    do
    {
        printf("VETTORI");
        printf("\n1)Carica un vettore randomicamente");
        printf("\n2)Carica un vettore manualmente");
        printf("\n3)Visualizza un vettore");
        printf("\n4)Cerca un valore (ricerca sequenziale)");
        printf("\n5)Cerca piu' valori");
        printf("\n6)Ordina (crescente)");
        printf("\n7)Ordina (decrescente)");
        printf("\n8)Cerca un valore (ricerca dicotomica)");
        printf("\n9)Fondi i due vettori in un terzo vettore");
        printf("\n10)Esci");
        printf("\nScegli l'opzione ---> ");
        scanf("%d",scelta);
    }while(*scelta<1||*scelta>9);
}

void scelta_vettore(int *scelta)
{
  do{
      printf("Quale vettore hai intenzione di utilizzare, il primo o il secondo?");
      scanf("%d",scelta);
    }while(*scelta<1||*scelta>2);
}

void carica_vettore_random(int vet[DIM]) //funzione utile a caricare al vettore
{
    int i = 0;
    srand(time(0));
    for(i=0;i<DIM;i++)
    {
      vet[i]=rand()%1000;
    }
  printf("\nIl vettore e' stato caricato randomicamente\n");
}

void carica_vettore_manual(int vet[DIM]) //funzione utile a caricare al vettore
{
    int i = 0;
    for(i=0;i<DIM;i++)
    {
      printf("\nInserisci il valore da dare alla #%d posizione del vettore\n",i+1);
      scanf("%d",vet[i]);
    }
  printf("\nIl vettore e' stato caricato correttamente\n");
}

void visualizza_vettore(int vet[DIM]) //funzione utile alla visualizzazione del vettore, viene passato il parametro vet che contiene i dati del vettore
{
    int i=0;
    for(i=0;i<DIM;i++)
    {
        printf("+----+\n");
        printf("|%4d|\n",vet[i]);
        printf("+----+\n");
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

void cerca_piu_valori(int vet[DIM], int valore)
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
/*
 La procedura cerca_piu_valori e' utile a cercare un valore nel vettore in multiple
 posizioni, viene passato il parametro vet che contiene i dati del vettore e il parametro
 valore che contiene il valore da cercare
*/

void scambia(int pos2,int vet[DIM],int pos1)
{
    int tmp=0;
    tmp=vet[pos2];
    vet[pos2]=vet[pos1];
    vet[pos1]=tmp;
}
/*
La procedura scambia e' utile a scambiare due valori di un vettore, i parametri che vengono
passati sono la posizione nel vettore di entrambi i valori, il vettore e il valore di
scambio
*/

void ordinamento_vettore_crescente(int vet[DIM])
{
    int i = 0;
    int j = 0;
    int min = 0;
    int pos = 0;
    for(j=0;j<DIM;j++)
    {
        min = vet[j];
        for(i=j;i<DIM;i++)
        {
            if(vet[i]<min)
            {
                min=vet[i];
                pos=i;
                scambia(pos,vet,j);
            }
        }
    }
    printf("\nIl vettore e' stato ordinato in ordine crescente\n");
}
/*
La procedura ordinamento_vettore_crescente ha lo scopo di ordinare un vettore
*/

void ordinamento_vettore_decrescente(int vet[DIM])
{
    int i = 0;
    int j = 0;
    int max = 0;
    int pos = 0;
    for(j=0;j<DIM;j++)
    {
        max = vet[j];
        for(i=j;i<DIM;i++)
        {
            if(vet[i]>max)
            {
                max=vet[i];
                pos=i;
                scambia(pos,vet,j);
            }
        }
    }
    printf("\nIl vettore e' stato ordinato in ordine decrescente\n");
}

void ricerca_dicotomica(int vet[DIM])
{
  int num = 0;
  int ind_min = 0;
  int ind_max = DIM;
  int i = (ind_min + ind_max)/2;
  int numero_trovato = 0;
  printf("Inserisci il numero da cercare all'interno del vettore --> ");
  scanf("%d",&num);
  do{
  if(vet[i]==num)
  {
    printf("Il numero e' stato trovato nella posizione %d",i);
    numero_trovato = 1;
  }else if (vet[i]>num)
  {
    ind_max = i;
    i = (ind_min + ind_max)/2;
  }
  else if(vet[i]<num)
  {
    ind_min = i;
    i = (ind_min + ind_max)/2;
  }
  }while(ind_max!=ind_min||numero_trovato==0);
  if(numero_trovato==0)
  {
    printf("Purtroppo il numero non e' stato trovato");
  }
}

void ricerca_dicotomica_decrescente(int vet[DIM])
{
  int num = 0;
  printf("Inserisci il numero da cercare all'interno del vettore --> ");
  scanf("%d",&num);
}

void fusione(int vet1[], int vet2[], int vet3[])
{
  int i;
  	for(i=0;i<(DIM+DIM1);i++)
	{
		if(i<DIM)
		{
			vet3[i]=vet1[i];
		}
		else
		{
			vet3[i]=vet2[i-DIM];
		}
	}
  printf("\nI due vettori sono stati uniti\n");
}

int main()
{
    int flag_1 = 0;
    int flag_2 = 0;
    int vet[DIM];
    int vet1[DIM];
    int vet2[DIM1];
    int scelta = 0;
    int valore = 0;
    int flag_ordine_1 = 0;
    int flag_ordine_2 = 0;
    int scelta_vettore = 0;
    do
    {
      system("cls");
      menu(&scelta);
      switch(scelta)
      {
          case 1:
          {
              scelta_vettore(&scelta_vettore);
              if(scelta_vettore==1){
                carica_vettore_random(vet);
                flag_1 = 1;
              }else if(scelta_vettore==2){
                carica_vettore_random(vet1);
                flag_2 = 1;
              }
              break;
          }
          case 2:
          {
              scelta_vettore(&scelta_vettore);
              if(scelta_vettore==1){
                carica_vettore_manual(vet);
                flag_1 = 1;
              }else if(scelta_vettore==2){
                carica_vettore_manual(vet1);
                flag_2 = 1;
              }
              break;
          }
          case 3:
          {
              scelta_vettore(&scelta_vettore);
              if(scelta_vettore==1)
              {
                if(flag_1==1)
                {
                    visualizza_vettore(vet); //richiamo alla funzione di visualizzazione del vettore
                }else
                {
                    printf("\nPurtroppo il vettore e' vuoto, si prega di riempirlo  attraverso la prima opzione\n");
                }
              }else if(scelta_vettore==2){
                if(flag_2==1)
                {
                    visualizza_vettore(vet1); //richiamo alla funzione di visualizzazione del vettore
                }else
                {
                    printf("\nPurtroppo il vettore e' vuoto, si prega di riempirlo  attraverso la prima opzione\n");
                }
              }
              system("PAUSE");
              break;
          }
          case 4:
          {
            scelta_vettore(&scelta_vettore);
            if(scelta_vettore==1){
              if(flag_1==1)
                {
                    cerca_valore(vet); //richiamo alla funzione utile a cercare un valore nel vettore
                }else
                {
                    printf("\nPurtroppo il vettore e' vuoto, si prega di riempirlo  attraverso la prima opzione\n");
                }
            }else if(scelta_vettore==2){
              if(flag_2==1)
                {
                    cerca_valore(vet1); //richiamo alla funzione utile a cercare un valore nel vettore
                }else
                {
                    printf("\nPurtroppo il vettore e' vuoto, si prega di riempirlo  attraverso la prima opzione\n");
                }
            }
            break;
          }
          case 5:
          {
            scelta_vettore(&scelta_vettore);
            if(scelta_vettore==1){
              if(flag_1==0)
              {
                printf("\nPurtroppo il vettore e' vuoto, si prega di riempirlo  attraverso la prima opzione\n");
              }else
              {
                printf("Inserisci il valore da cercare con stampe multiple--> "); //presa in input del valore da cercare
                scanf("%d",&valore);
                cerca_piu_valori(vet, valore); //richiamo alla funzione utile a cercare un valore nel vettore in multiple posizioni
              }
            }else if(scelta_vettore==2){
              if(flag_2==0)
              {
                printf("\nPurtroppo il vettore e' vuoto, si prega di riempirlo  attraverso la prima opzione\n");
              }else
              {
                printf("Inserisci il valore da cercare con stampe multiple--> "); //presa in input del valore da cercare
                scanf("%d",&valore);
                cerca_piu_valori(vet1, valore); //richiamo alla funzione utile a cercare un valore nel vettore in multiple posizioni
              }
            }
            system("pause");
            break;
          }
          case 6:
          {
              scelta_vettore(&scelta_vettore);
              if(scelta_vettore==1){
                if(flag_1==0)
                {
                  printf("\nPurtroppo il vettore e' vuoto, si prega di riempirlo  attraverso la prima opzione\n");
                  system("pause");
                }else
                {
                ordinamento_vettore_crescente(vet);
                flag_ordine_1 = 1;
               }
              }else if(scelta_vettore==2){
                if(flag_2==0)
                {
                  printf("\nPurtroppo il vettore e' vuoto, si prega di riempirlo  attraverso la prima opzione\n");
                  system("pause");
                }else
                {
                ordinamento_vettore_crescente(vet1);
                flag_ordine_2 = 1;
               }
              }
             system("PAUSE");
             break;
          }
          case 7:
          {
              scelta_vettore(&scelta_vettore);
              if(scelta_vettore==1){
                if(flag_1==0)
                {
                  printf("\nPurtroppo il vettore e' vuoto, si prega di riempirlo  attraverso la prima opzione\n");
                }else
                {
                ordinamento_vettore_decrescente(vet);
                flag_ordine_1 = 2;
                }
              }else if(scelta_vettore==2){
                if(flag_2==0)
                {
                  printf("\nPurtroppo il vettore e' vuoto, si prega di riempirlo  attraverso la prima opzione\n");
                }else
                {
                ordinamento_vettore_decrescente(vet1);
                flag_ordine_2 = 2;
                }
              }
              system("pause");
              break;
          }
          case 8:
          {
              scelta_vettore(&scelta_vettore);
              if(scelta_vettore==1){
                if(flag_1==0)
                {
                  printf("\nPurtroppo il vettore e' vuoto, si prega di riempirlo  attraverso la prima opzione\n");
                }else
                {
                 if(flag_ordine_1==0)
                 {
                   printf("\nErrore: Il vettore non e' stato ordinato\n");
                 }
                 if(flag_ordine_1==1)
                 {
                   ricerca_dicotomica(vet);
                 }else
                 {
                   ricerca_dicotomica_decrescente(vet);
                 }
                }
              }else if(scelta_vettore==2){
                if(flag_1==0)
                {
                  printf("\nPurtroppo il vettore e' vuoto, si prega di riempirlo  attraverso la prima opzione\n");
                }else
                {
                 if(flag_ordine_1==0)
                 {
                   printf("\nErrore: Il vettore non e' stato ordinato\n");
                 }
                 if(flag_ordine_1==1)
                 {
                   ricerca_dicotomica(vet1);
                 }else
                 {
                   ricerca_dicotomica_decrescente(vet1);
                 }
                }
              }
              system("pause");
              break;
          }
          case 9:
          {
            fusione(vet,vet1,vet2);
            ordinamento_vettore_crescente(vet2);
          }
      }
    }while(scelta!=10);
}
