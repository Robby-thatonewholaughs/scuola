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
      // Visualizzo un messaggio di errore in caso il valore inserito non sia corretto
      if ( r != 0 && r != 1 && r != 2){
          System.out.println("Il valore inserito non e' corretto");
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
    }while(r<0||r>2);
    //Verifico che il valore inserito dall'utente sia corretto

    //Definisco uno switch-case che esegue l'opzione selezionata dall'utente
    switch(r){
      case 0:
      {
        System.out.println("Programma terminato");
        break;
      }
      case 1:
      {
        System.out.println("Hello World");
        break;
      }
      case 2:
      {
        System.out.println("Il mio nome e cognome è : Christian Ruzza" );
        break;
      }
    }
  }
}
