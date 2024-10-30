package it.unimol.ristorante.ui;

import it.unimol.ristorante.app.ricette.GestoreRicette;
import it.unimol.ristorante.app.ricette.Ingrediente;
import it.unimol.ristorante.app.ricette.Ricetta;
import it.unimol.ristorante.app.cuochi.GestoreCuochi;

import java.util.Scanner;

public class TerminalUI {
    private GestoreRicette gestoreRicette;
    private GestoreCuochi gestoreCuochi;
    
    public TerminalUI() {
        this.gestoreRicette = new GestoreRicette();
        this.gestoreCuochi = new GestoreCuochi();
    }
    
    public void mainMenu() {
        int risposta;
        do {
            System.out.println("Benvenuto");
            
            System.out.println("1. Inserimento ricetta");
            System.out.println("2. Inserimento cuoco");
            System.out.println("3. Associazione cuoco-ricetta");
            System.out.println("0. ESCI");
            
            risposta = this.readInt();
            
            switch (risposta) {
                case 1:
                    this.insertRicetta();
                    break;
                    
                case 2:
                    this.insertCuoco();
                    break;
                    
                case 3:
                    this.assignCuocoToRicetta();
                    break;
            }
        } while (risposta != 0);
    }
    
    public void insertRicetta() {
        System.out.println("Nome ricetta: ");
        String nomeRicetta = this.readString();
        Ingrediente[] ingredienti = new Ingrediente[0];
        Ricetta ricetta = new Ricetta(nomeRicetta, ingredienti);
        this.gestoreRicette.addRicetta(ricetta);
    }
    
    public void insertCuoco() {
        System.out.println("DA IMPLEMENTARE");
    }
    
    public void assignCuocoToRicetta() {
        System.out.println("DA IMPLEMENTARE");
    }
    
    private int readInt() {
        return new Scanner(System.in).nextInt();
    }
    
    private String readString() {
        return new Scanner(System.in).nextLine();
    }
    
    private float readFloat() {
        return new Scanner(System.in).nextFloat();
    }
}
