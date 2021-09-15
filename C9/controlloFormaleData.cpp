/*
Christian Ruzza                           3 CI                                   12/11/2020
Controllo Formale della data
Viene letta una data in formato gg-mm-aaaa e bisogna controllare che la data sia reale evitando
casi come il 30 febbraio o il 31 novembre
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define SUCC 1

int controllo_data()
{
    int gg,mm,aaaa,leap;
	gg=0;
	mm=0;
	aaaa=0;
	leap=0;
    do{
		do{
			do
			{
				system("cls");
				printf("inserire data \n");
				printf("inserisci il giorno ----> ");
				scanf("%d",&gg);
			}while(gg<1||gg>31);
			do
			{
				system("cls");
				printf("inserire data \n");
				printf("inserisci il giorno ----> %d \n",gg);
				printf("inserisci il mese ----> ");
				scanf("%d",&mm);
			}while(mm<1||mm>12);
		}while((mm==4||mm==6||mm==9||mm==11)&&gg==31);
	}while(mm==2&&gg>29);
	do{
		system("cls");
		printf("inserire data \n");
		printf("inserisci il giorno ----> %d \n",gg);
		printf("inserisci il mese ----> %d \n",mm);
		printf("Inserisci L'anno ----> ");
		scanf("%d",&aaaa);
		if(aaaa%400==0||aaaa%4==0&&aaaa%100>0){
			leap=1;
			}else{
						leap=0;
						}
	}while(leap=1&&gg>29&&mm==2||leap==0&&gg==29&&mm==2);
	return SUCC;
}

int main()
{
	if(controllo_data == SUCC)
        printf("La data e' giusta");
	return 0;
}
