/*
Christian Ruzza                   3CI                          26/11/2020
programma menu'
*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>

int main()
{
  int s;//definizione variabile per la scelta
  int c; //definizione di una variabile per il programma 1
  int i; //definizione di una variabile per il programma 1
  char p; //definizione di una variabile per il programma 2
do{
  //Visualizzazione del menÃ¹ e scelta dell'utente
  do{
    system("cls");
    printf(" 1)Tabella codici Ascii \n \n ");
    printf("2)Codifica Ascii di un Carattere \n \n ");
    printf("3)Carattere corrispondente ad un codice Ascii \n \n ");
    printf("4)Trasforma un carattere minuscolo in maiuscolo \n \n ");
    printf("5)Esci\n \n");
    printf(" Scegli ---> ");
    scanf("%d",&s);
  }while(s<1||s>5);
  switch (s){
    //Tabella Codici ASCII
    case 1:{
      c=0;
      i=0;
        do{
          i++;
          if(c<3)
          {
            c++;
            printf("%4d = %c ",i,i);
          }else
          {
            c=0;
            printf("\n %4d = %c ",i,i);
          }
        }while(i<256);
        getch();
      break;
    }
    //Codifica ASCII
    case 2:{
        system("cls");
        printf("Immettere il codice ASCII---> ");
        scanf(" %d", &p);
        printf(" \n Il codice ASCII %d corrisponde al carattere %c ",p,p);
        getch();
        break;
      }
      //Carattere corrispondente ad un codice ASCII
    case 3:{
        system("cls");
        printf("Immettere un carattere---> ");
        scanf(" %c", &p);
        printf(" \n Il carattere %c corrisponde al codice ASCII %d ",p,p);
        getch();
        break;
      }
      //Trasformazione di un carattere da minuscolo a maiuscolo senza l'uso di toupper
    case 4:{
      system("cls");
			printf("Inserisci una lettere minuscola --> ");
			fflush(stdin);
			scanf("%c",&p);
			if (p>='a'&& p<='z')
			p=p-32;
			printf("La lettera maiuscola e' %c", p);
			getch();
			break;
      }
    }
  }while(s!=5);
}
