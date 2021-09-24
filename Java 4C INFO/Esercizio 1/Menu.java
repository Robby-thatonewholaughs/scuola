/*
Christian Ruzza 4CI 24-09-2021

Lo scopo di questo programma e' quello di visualizzare un menu facendo un controllo formale che fa ciclare il menu
visualizzando anche un messaggio di errore in caso l'utente inserisca un dato sbagliato, dopodiche' viene sviluppata
una switch-case che gestisce le scelte dell'utente
*/
import java.util.Scanner;

public class Menu {
  // Scrivere un programma con un menu di scelta
  public static void main(String[] args)
  {
    int r=0;
    // Costruisco la struttura del menù creando anche un ciclo
    do{
      do{
        // Visualizzo un messaggio di errore in caso il valore inserito non sia corretto
        if ( r != 0 && r != 1 && r != 2){
            System.out.print("\033[H\033[2J"); //Viene pulito lo schermo
            System.out.flush();
            System.out.println("Il valore inserito non e' corretto");
            new Scanner(System.in).nextLine();
            System.out.print("\033[H\033[2J"); //Viene pulito lo schermo
            System.out.flush();
        }
        System.out.println("Esegui la tua selezione");
        System.out.println("Seleziona un evento:");
        System.out.println(" 0 - Termini il programma");
        System.out.println(" 1 - Stampa Hello World");
        System.out.println(" 2 - Mi presento");
        System.out.print("Inserisci la tua scelta: ");
        Scanner in = new Scanner(System.in);
        // Acquisisco il valore per la scelta
        r = in.nextInt();
        //Verifico che il valore inserito dall'utente sia corretto
      }while(r<0||r>2);
      //Cancello cio' che c'e' scritto nella console
      System.out.print("\033[H\033[2J");
      System.out.flush();
      //Definisco uno switch-case che esegue l'opzione selezionata dall'utente
      switch(r){
        case 0:
        {
          System.out.println("Programma terminato");
          break;
        }
        case 1:
        {
          System.out.println("Hello World!");
          System.out.println("Premere un tasto per continuare..." );
          break;
        }
        case 2:
        {
          System.out.println("Il mio nome e cognome è : Christian Ruzza" );
          System.out.println("Premere un tasto per continuare..." );
          break;
        }
      }
      new Scanner(System.in).nextLine(); //Viene messo in pausa il programma aspettando che l'utente prema un tasto
      System.out.print("\033[H\033[2J");
      System.out.flush();
    }while(r!=0);
  }
}
