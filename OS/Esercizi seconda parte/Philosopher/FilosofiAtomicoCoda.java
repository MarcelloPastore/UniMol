import java.util.LinkedList;
public class FilosofiAtomicoCoda implements Runnable {
    static final int NTHREAD=4;             // numero di filosofi
    final int index;                        // indice locale del filosofo
    TavolaAtomicaCoda t;                    // monitor condiviso
    // il filosofo memorizza il proprio indice e il monitor condiviso
    FilosofiAtomicoCoda(int i, TavolaAtomicaCoda t) {
        index = i;
        this.t = t;
    }
    
    // il thread esegue il codiceFilosofo a meno di interruzioni
    public void run()  {
        try { 
            codiceFilosofo(index);
        } catch (InterruptedException e) {
            System.out.println("Il filosofo "+index+" e' stato interrotto");
        }
    }
    // il filosofo pensa e mangia come al solito
    void codiceFilosofo(int index) throws InterruptedException {
        while(true) {
            // PENSA 
            System.out.println("Filosofo " + index +" pensa");
            Thread.sleep(1000);
            
            t.raccogli(index);  // raccoglie atomicamente le bacchette
            //MANGIA
            System.out.println("Filosofo " + index +" mangia");
            Thread.sleep(3000);
            t.deposita(index);  // deposita le bacchette
        }
    }
    public static void main(String args[]) throws InterruptedException {
        int i;
        Thread thread[] = new Thread[NTHREAD];
        TavolaAtomicaCoda t= new TavolaAtomicaCoda(NTHREAD);
        
        // crea NTHREAD filosofi e li esegue
        for(i=0;i<NTHREAD;i++) {
            thread[i] = new Thread(new FilosofiAtomicoCoda(i,t));
            thread[i].start();
            /* Decommentare la linea seguente per sfasare il 
             * filosofo 0 rispetto ai successivi per e 
             * osservare la starvation
             * Ridurre anche NTHREAD a 4
             */
            if (i==0) Thread.sleep(2000);
        }
        // esce lasciando i filosofi al loro destino
    }
}
/* monitor TavolaAtomicaCoda per la gestione atomica delle bacchette */
class TavolaAtomicaCoda {
    private boolean b[];        // le bacchette
    private final int NFIL;     // il numero di filosofi
    private LinkedList<Integer> coda;// coda esplicita
    // crea le NFIL bacchette e le inizializza a true (presenti)
    // NOTA: non serve sincronizzarlo e' prima della creazione dei filosofi
    TavolaAtomicaCoda(int i) { 
        int j;
        NFIL=i;                 // memorizza il numero dei filosofi
        b = new boolean[NFIL];  // crea le bacchette
        for (j=0;j<NFIL;j++)    // inizializza le bacchette a true
            b[j] = true;
        coda = new LinkedList<Integer>();   // crea la coda esplicita
    }
    // raccoglie le bacchette in modo atomico
    synchronized void raccogli(int i) throws InterruptedException {
        // accoda il filosofo
        coda.add(i);
        // finche' non è il primo della coda o non ci sono le due bacchette o attende
        while (i != coda.peek() || !(b[i] && b[(i+1)%NFIL]))
            wait();
        // toglie il filosofo dalla coda
        coda.remove();
            
        // raccoglie entrambe le bacchette
        b[i]=false;             // deposita la bacchetta sx
        b[(i+1)%NFIL] = false;  // deposita la bacchetta dx
        notifyAll();            // notifica eventuali filosofi che 
                                // potrebbero mangiare ma non erano i primi
                                // della coda
    }
    // deposita entrambe le bacchette e notifichiamo TUTTI i filosofi
    synchronized void deposita(int i) {
        b[i]=true;              // deposita la bacchetta sx
        b[(i+1)%NFIL] = true;   // deposita la bacchetta dx
        notifyAll();            // notifica tutti i filosofi
    }
}