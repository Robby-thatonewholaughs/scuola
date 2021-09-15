/*
Lorenzo Lingesso-Ruzza Christian 28/01/2021 3CI
In questo esercizio l'algoritmo prende in input due date tramite una procedura
che oltre al leggere le date ne controlla la correttezza, proseguendo poi con
una seconda procedura che conta i giorni di distanza tra le due date inserite, ma
tutto ciò solo dopo aver controllato che le due date siano all'interno dello
stesso anno
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void controllo_data(int *gg,int *mm,int *aaaa) //vengono chieste in input le due date e controllate formalmente
{
  int leap = 0;
	do{
		do{
			do
			{
				system("cls");
				printf("inserire data \n");
				printf("inserisci il giorno ----> ");
				scanf("%d",&*gg);
			}while(*gg<1||*gg>31);
			do
			{
				system("cls");
				printf("inserire data \n");
				printf("inserisci il giorno ----> %d \n",*gg);
				printf("inserisci il mese ----> ");
				scanf("%d",&*mm);
			}while(*mm<1||*mm>12);
		}while((*mm==4||*mm==6||*mm==9||*mm==11)&&*gg==31);
	}while(*mm==2&&*gg>29);
	do{
		system("cls");
		printf("inserire data \n");
		printf("inserisci il giorno ----> %d \n",*gg);
		printf("inserisci il mese ----> %d \n",*mm);
		printf("Inserisci L'anno ----> ");
		scanf("%d",&*aaaa);
		if(*aaaa%400==0||*aaaa%4==0&&*aaaa%100>0){
			leap=1;
			}else
      {
        leap=0;
			}
	}while(leap=1&&*gg>29&&*mm==2||leap==0&&*gg==29&&*mm==2);
}

void giorni_trascorsi(int anno[],int gg, int mm,int gg1,int mm1) //vengono calcolati i giorni di distanza tra le due date
{
	int contaGiorni,i,mm2,gg2;
	if(mm>mm1)
	{
		gg2=gg1;
		gg1=gg;
		gg=gg2;
		mm2=mm1;
		mm1=mm;
		mm=mm2;
	}
	if(mm==1||mm==3||mm==5||mm==7||mm==8||mm==10||mm==11)
	{
		contaGiorni=31-gg;
	}
	else if(mm==2)
	{
		contaGiorni=29-gg;
	}
	else
	{
		contaGiorni=30-gg;
	}

	for(i=mm;i<mm1;i++)
	{
		contaGiorni=contaGiorni+anno[i];
	}
	if(mm1==1||mm1==3||mm1==5||mm1==7||mm1==8||mm1==10||mm1==11)
	{
		contaGiorni=contaGiorni-(31-gg1);
	}
	else if(mm1==2)
	{
		contaGiorni=contaGiorni-(29-gg1);
	}
	else
	{
		contaGiorni=contaGiorni-(30-gg1);
	}
	printf("I giorni trascorsi sono: %d \n",contaGiorni);
}

int main()
{
  int gg,mm,aaaa,gg1,mm1,aaaa1,i;
  int anno[12]={31,29,31,30,31,30,31,31,30,31,30,31};
  printf("Inserire due date dello stesso anno e vi verra' detto quanti giorni ci sono tra l'una e l'altra\n");
  system("PAUSE");
  controllo_data(&gg,&mm,&aaaa);
  do
  {
    controllo_data(&gg1,&mm1,&aaaa1);
  }while(aaaa!=aaaa1);
  giorni_trascorsi(anno,gg,mm,gg1,mm1);
  system("PAUSE");
}
