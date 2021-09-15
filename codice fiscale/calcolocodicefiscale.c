/*
Ruzza 4CI 14/09/2021
Il programma seguente ha lo scopo di chiedere in input all'utente i dati necessari
a calcolare il suo codice fiscale controllandoli formalmente per evitare che vengano
inseriti dati che mandino in tilt il programma e poi elaborandoli per calcolare il
codice fiscale e stamparlo infine in output.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define DIM 20

//procedura che prenderà in input un nome inserito dall'utente, controllandolo attraverso dei controlli formali
void input_nome(char nome[])
{

    int i;
    int check = 0;

    do
    {
        if(check==1)
        {
            printf("Non hai inserito il nome di una persona");
            check=0;
        }

        printf ("Inserisci il nome --> ");
        scanf("%s",nome);

        for (i = 0; i < strlen(nome); i++)
            nome[i] = toupper (nome[i]);

        i = 0;
        do
        {
            if ((nome[i] < 'A' || nome[i] > 'Z' ) && nome[i] != ' ')
                check = 1;
            i++;

        }while (i < strlen (nome) && check == 0);

    }while(check==1);
}

//procedura che prenderà in input un cognome inserito dall'utente, controllandolo attraverso dei controlli formali
void input_cognome(char cognome[])
{

    int i;
    int check = 0;
    do
    {
        if(check==1)
        {
            printf("Non hai inserito il cognome di una persona");
            check=0;
        }
        printf("Inserisci il cognome --> ");
        scanf("%s",cognome);

        for (i = 0; i < strlen (cognome); i++)
            cognome[i] = toupper (cognome[i]);

        i = 0;
        do
        {
            if ((cognome[i] < 'A' || cognome[i] > 'Z' ) && cognome[i] != ' ' && cognome[i] != '\'')
                check = 1;
            i++;
        }while (i < strlen (cognome) && check == 0);

    }while(check==1);
}

//procedura che convertirà il cognome secondo le regole del codice fiscale e lo trasformerà nei primi tre caratteri di cf
void cod_cogn(char cognome[], char cf[])
{
    int i, x=0, cn=0;

    for(i = 0;i < strlen(cognome);i++)
    {
        cognome[i] = toupper(cognome[i]);
    }

    for(i = 0;i < strlen(cognome);i++)
    {
        if(cognome[i]!='A'&&cognome[i]!='E'&&cognome[i]!='I'&&cognome[i]!='O'&&cognome[i]!='U'&&cognome[i]!=' '&&cognome[i]!=39&&cn<3)
        {
            cf[cn]=cognome[i];
            cn++;
        }
    }

    if(cn<3)
    {
        for(i=0;i<strlen(cognome);i++)
        {
            if((cognome[i]=='A'||cognome[i]=='E'||cognome[i]=='I'||cognome[i]=='O'||cognome[i]=='U')&&cn<3)
            {
                cf[cn]=cognome[i];
                cn++;
            }
        }
    }

    if(cn<3)
    {
        for(i=cn;i<3;i++)
        {
            cf[cn]='X';
        }
    }
}

//procedura che convertirà il nome secondo le regole del codice fiscale e lo trasformerà nei secondi tre caratteri di cf
void cod_nome(char nome[], char cf[])
{
    int i, n=0, cn=0, j=0;

    for(i = 0;i < strlen(nome);i++)
    {
        nome[i] = toupper(nome[i]);
    }

    for(i = 0;i < strlen(nome);i++)
    {
        if(nome[i]!='A'&&nome[i]!='E'&&nome[i]!='I'&&nome[i]!='O'&&nome[i]!='U'&&nome[i]!=' ')
        {
            j++;
        }
    }

    if(j>3)
    {
        for(i = 0;i < strlen(nome);i++)
        {
            if(nome[i]!='A'&&nome[i]!='E'&&nome[i]!='I'&&nome[i]!='O'&&nome[i]!='U'&&nome[i]!=' '&&cn<3)
            {
                if(n!=1)
                {
                    cf[cn+3]=nome[i];
                    cn++;
                }
                n++;
            }
        }
    }

    if(j<4)
    {
        for(i = 0;i < strlen(nome);i++)
        {
            if(nome[i]!='A'&&nome[i]!='E'&&nome[i]!='I'&&nome[i]!='O'&&nome[i]!='U'&&nome[i]!=' '&&cn<3)
            {
                cf[cn+3]=nome[i];
                cn++;
            }
        }
    }

    if(cn<3)
    {
        for(i=0;i<strlen(nome);i++)
        {
            if((nome[i]=='A'||nome[i]=='E'||nome[i]=='I'||nome[i]=='O'||nome[i]=='U')&&cn<2)
            {
                cf[cn+3]=nome[i];
                cn++;
            }
        }
        for(i=cn;i<3;i++)
        {
            cf[cn+3]='X';
        }
    }

}

//procedura che convertirà l'anno aaaa inserito dall'utente in formato aa e lo metterà alla posizione 6 e 7 di cf
void cod_nascita_anno(char cf[])
{
    int aaaa, anno[2], c1, c2, i;

    do
    {
        printf("Inserisci l'anno di nascita --> ");
        scanf("%d",&aaaa);
    }while(aaaa<1900||aaaa>2100);

    aaaa=aaaa%100;
    c1=aaaa/10;
    c2=aaaa%10;
    cf[6]=c1 + 48;
    cf[7]=c2 + 48;
}

//procedura che convertirà il mese con una tabella di conversione e lo metterà nella posizione 8 di cf
void cod_nascita_mese(char cf[], int *mm)
{
    int i, n=8;
    char mese;

    do
    {
        printf("Inserisci il mese di nascita --> ");
        scanf("%d",mm);
    }while(*mm<0||*mm>13);

    switch(*mm)
    {
        case 1:
        {
            mese='A';
            break;
        }
        case 2:
        {
            mese='B';
            break;
        }
        case 3:
        {
            mese='C';
            break;
        }
        case 4:
        {
            mese='D';
            break;
        }
        case 5:
        {
            mese='E';
            break;
        }
        case 6:
        {
            mese='H';
            break;
        }
        case 7:
        {
            mese='L';
            break;
        }
        case 8:
        {
            mese='M';
            break;
        }
        case 9:
        {
            mese='P';
            break;
        }
        case 10:
        {
            mese='R';
            break;
        }
        case 11:
        {
            mese='S';
            break;
        }
        case 12:
        {
            mese='T';
            break;
        }
    }

    cf[n]=mese;
}

//sottoprogramma che convertirà il giorno, in base anche al sesso della persona, e lo metterà nelle posizioni 9 e 10 di cf
void cod_nascita_giorno(char cf[], int mm)
{
    int gg, c1, c2, i=0;
    char sesso;

    do
    {
        printf("Inserisci il sesso --> ");
        scanf(" %c",&sesso);
        sesso = toupper(sesso);
    }while(sesso!='M'&&sesso!='F');

    if(mm==11||mm==6||mm==4||mm==9)
    {
        do
        {
            printf("Inserisci il giorno di nascita --> ");
            scanf("%d",&gg);
        }while(gg<0||gg>31);

        if(sesso=='F')
        {
            gg=gg+40;
        }

    }else if(mm==2)
    {
        do
        {
            printf("Inserisci il giorno di nascita --> ");
            scanf("%d",&gg);
        }while(gg<0||gg>28);

        if(sesso=='F')
        {
            gg=gg+40;
        }

    }else
    {
        do
        {
            printf("Inserisci il giorno di nascita --> ");
            scanf("%d",&gg);
        }while(gg<0||gg>32);

        if(sesso=='F')
        {
            gg=gg+40;
        }

    }

    c1=gg/10;
    c2=gg%10;
    cf[9]=c1+48;
    cf[10]=c2+48;
}

//procedura che prenderà in input il codice del comune di nascita, attraverso anche dei controlli formali per evitare errori e lo metterà nelle posizioni 11, 12, 13 e 14 di cf
int luogo_nascita(char cf[])
{
    char luogo[100], luogo_file[100], luogo_file_tmp[100];
    int i, j=0;
    FILE *fp;

    fp = fopen ("province.csv", "r");

    printf("Inserisci il luogo di nascita --> ");
    getchar();
    scanf("%[^\n]",luogo);              //"%[^\n]"=leggere una stringa con gli spazi usufreondo della scanf

    while(!feof(fp))
    {
        fgets(luogo_file, sizeof(luogo_file), fp);              //legge da file ogni comune


        for(i=0;i<strlen(luogo);i++)
            luogo_file_tmp[i] = luogo_file[i];         //viene riempito il comune senza il codice nella variabile temporanea

        if(strcmp(luogo,luogo_file_tmp)==0)
        {
            for(i=0;i<strlen(luogo)+6;i++)
            {
                if (i>strlen(luogo))
                {
                    luogo_file_tmp[j] = luogo_file[i];          //viene rempito il codice nella variabile temporanea
                    j++;
                }
            }
            luogo_file_tmp[4]='\0';

            cf[11]=luogo_file_tmp[0];
            cf[12]=luogo_file_tmp[1];
            cf[13]=luogo_file_tmp[2];
            cf[14]=luogo_file_tmp[3];
            return 0;
        }
    }
}

//procedura che calcolerà il control internal number attraverso una conversione dei caratteri in base alla posizione(pari o dispari), sommandoli tra di loro e dividendo per 26 il risultato: il resto andrà poi convertito in lettera secondo un ulteriore algoritmo e sarà la posizione 16 di cf
void cin(char cf[])
{
    int i, cn=0, cp=0, cd=0;
    char pari[7], dispari[8], contenitore;

    for(i=0;i<16;i++)
    {
        if((i+1)%2==0)
        {
            pari[cp]=cf[i];
            cp++;
        }else
        {
            dispari[cd]=cf[i];
            cd++;
        }
    }

    for(i=0;i<8;i++)
    {
        contenitore=dispari[i];
        switch(contenitore)
        {
            case '0':
            {
                cn=cn+1;
                break;
            }

            case '1':
            {
                cn=cn+0;
                break;
            }

            case '2':
            {
                cn=cn+5;
                break;
            }

            case '3':
            {
                cn=cn+7;
                break;
            }

            case '4':
            {
                cn=cn+9;
                break;
            }

            case '5':
            {
                cn=cn+13;
                break;
            }

            case '6':
            {
                cn=cn+15;
                break;
            }

            case '7':
            {
                cn=cn+17;
                break;
            }

            case '8':
            {
                cn=cn+19;
                break;
            }

            case '9':
            {
                cn=cn+21;
                break;
            }

            case 'A':
            {
                cn=cn+1;
                break;
            }

            case 'B':
            {
                cn=cn+0;
                break;
            }

            case 'C':
            {
                cn=cn+5;
                break;
            }

            case 'D':
            {
                cn=cn+7;
                break;
            }

            case 'E':
            {
                cn=cn+9;
                break;
            }

            case 'F':
            {
                cn=cn+13;
                break;
            }

            case 'G':
            {
                cn=cn+15;
                break;
            }

            case 'H':
            {
                cn=cn+17;
                break;
            }

            case 'I':
            {
                cn=cn+19;
                break;
            }

            case 'J':
            {
                cn=cn+21;
                break;
            }

            case 'K':
            {
                cn=cn+2;
                break;
            }

            case 'L':
            {
                cn=cn+4;
                break;
            }

            case 'M':
            {
                cn=cn+18;
                break;
            }

            case 'N':
            {
                cn=cn+20;
                break;
            }

            case 'O':
            {
                cn=cn+11;
                break;
            }

            case 'P':
            {
                cn=cn+3;
                break;
            }

            case 'Q':
            {
                cn=cn+6;
                break;
            }

            case 'R':
            {
                cn=cn+8;
                break;
            }

            case 'S':
            {
                cn=cn+12;
                break;
            }

            case 'T':
            {
                cn=cn+14;
                break;
            }

            case 'U':
            {
                cn=cn+16;
                break;
            }

            case 'V':
            {
                cn=cn+10;
                break;
            }

            case 'W':
            {
                cn=cn+22;
                break;
            }

            case 'X':
            {
                cn=cn+25;
                break;
            }

            case 'Y':
            {
                cn=cn+24;
                break;
            }

            case 'Z':
            {
                cn=cn+23;
                break;
            }
        }
    }

    for(i=0;i<7;i++)
    {
        contenitore=pari[i];
        switch(contenitore)
        {
            case '0':
            {
                cn=cn+0;
                break;
            }

            case '1':
            {
                cn=cn+1;
                break;
            }

            case '2':
            {
                cn=cn+2;
                break;
            }

            case '3':
            {
                cn=cn+3;
                break;
            }

            case '4':
            {
                cn=cn+4;
                break;
            }

            case '5':
            {
                cn=cn+5;
                break;
            }

            case '6':
            {
                cn=cn+6;
                break;
            }

            case '7':
            {
                cn=cn+7;
                break;
            }

            case '8':
            {
                cn=cn+8;
                break;
            }

            case '9':
            {
                cn=cn+9;
                break;
            }

            case 'A':
            {
                cn=cn+0;
                break;
            }

            case 'B':
            {
                cn=cn+1;
                break;
            }

            case 'C':
            {
                cn=cn+2;
                break;
            }

            case 'D':
            {
                cn=cn+3;
                break;
            }

            case 'E':
            {
                cn=cn+4;
                break;
            }

            case 'F':
            {
                cn=cn+5;
                break;
            }

            case 'G':
            {
                cn=cn+6;
                break;
            }

            case 'H':
            {
                cn=cn+7;
                break;
            }

            case 'I':
            {
                cn=cn+8;
                break;
            }

            case 'J':
            {
                cn=cn+9;
                break;
            }

            case 'K':
            {
                cn=cn+10;
                break;
            }

            case 'L':
            {
                cn=cn+11;
                break;
            }

            case 'M':
            {
                cn=cn+12;
                break;
            }

            case 'N':
            {
                cn=cn+13;
                break;
            }

            case 'O':
            {
                cn=cn+14;
                break;
            }

            case 'P':
            {
                cn=cn+15;
                break;
            }

            case 'Q':
            {
                cn=cn+16;
                break;
            }

            case 'R':
            {
                cn=cn+17;
                break;
            }

            case 'S':
            {
                cn=cn+18;
                break;
            }

            case 'T':
            {
                cn=cn+19;
                break;
            }

            case 'U':
            {
                cn=cn+20;
                break;
            }

            case 'V':
            {
                cn=cn+21;
                break;
            }

            case 'W':
            {
                cn=cn+22;
                break;
            }

            case 'X':
            {
                cn=cn+23;
                break;
            }

            case 'Y':
            {
                cn=cn+24;
                break;
            }

            case 'Z':
            {
                cn=cn+25;
                break;
            }
        }
    }

    cf[15]=cn%26+65;
}

int main ()
{
    char nome[DIM], cognome[DIM], cf[16];			//nome=variabile che contiene il nome, cognome=variabile che contiene il cognome, cf=stringa che contiene tutto il codice fiscale, cf_cogn=stringa che contiene solo il cognome in codice fiscale, cf_nome=stringa che contiene solo il nome in codice fiscamle
    int mm,i;																	//variabile che contiene il mese
    input_nome(nome);
    input_cognome(cognome);

    cod_cogn(cognome, cf);
    cod_nome(nome, cf);
    cod_nascita_anno(cf);
    cod_nascita_mese(cf, &mm);
    cod_nascita_giorno(cf, mm);
    luogo_nascita(cf);
    cin(cf);

    for(i=0;i<16;i++)
    {
        printf("%c",cf[i]);
    }
}
