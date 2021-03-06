/* Disciplina: Computacao Concorrente */
/* Prof.: Silvana Rossetto */
/* Módulo 2 - Laboratório: 8 */
/* Codigo: Leitores e escritores usando monitores em Java */
/* Nome: Hugo Nascimento da Silva*/
/* DRE: 120152161*/
/* -------------------------------------------------------------------*/

// classe para recurso compatilhado
class Compatilhado{

    // variável compartilhada entre as threads
    private int x;

    public Compatilhado() {
        this.x = 0;
    }

    public void setX(int x) {
        this.x = x;
    }

    public int getX() {
        return x;
    }

    public void incrementar(){
        ++this.x;
    }


}

// Monitor que implementa a logica do padrao leitores/escritores
class LE {
    private int leit, escr;

    // Construtor
    LE() {
        this.leit = 0; //leitores lendo (0 ou mais)
        this.escr = 0; //escritor escrevendo (0 ou 1)
    }

    // Entrada para leitores
    public synchronized void EntraLeitor (int id) {
        try {
            while (this.escr > 0) {
                //if (this.escr > 0) {
                System.out.println ("le.leitorBloqueado("+id+")");
                wait();  //bloqueia pela condicao logica da aplicacao
            }
            this.leit++;  //registra que ha mais um leitor lendo
            System.out.println ("le.leitorLendo("+id+")");
        } catch (InterruptedException e) { }
    }

    // Saida para leitores
    public synchronized void SaiLeitor (int id) {
        this.leit--; //registra que um leitor saiu
        if (this.leit == 0)
            this.notify(); //libera escritor (caso exista escritor bloqueado)
        System.out.println ("le.leitorSaindo("+id+")");
    }

    // Entrada para escritores
    public synchronized void EntraEscritor (int id) {
        try {
            while ((this.leit > 0) || (this.escr > 0)) {
                //if ((this.leit > 0) || (this.escr > 0)) {
                System.out.println ("le.escritorBloqueado("+id+")");
                wait();  //bloqueia pela condicao logica da aplicacao
            }
            this.escr++; //registra que ha um escritor escrevendo
            System.out.println ("le.escritorEscrevendo("+id+")");
        } catch (InterruptedException e) { }
    }

    // Saida para escritores
    public synchronized void SaiEscritor (int id) {
        this.escr--; //registra que o escritor saiu
        notifyAll(); //libera leitores e escritores (caso existam leitores ou escritores bloqueados)
        System.out.println ("le.escritorSaindo("+id+")");
    }
}



//Aplicacao de exemplo--------------------------------------------------------
// Leitor
class Leitor extends Thread {
    int id; //identificador da thread
    int delay; //atraso bobo
    LE monitor;//objeto monitor para coordenar a lógica de execução das threads
    Compatilhado x; // variável x compatilhada
    // Construtor
    Leitor (int id, int delayTime, LE m, Compatilhado x) {
        this.id = id;
        this.delay = delayTime;
        this.monitor = m;
        this.x = x;
    }

    // Método executado pela thread
    public void run () {
        double j=777777777.7, i;
        try {
            for (;;) {
                this.monitor.EntraLeitor(this.id);
                for (i=0; i<100000000; i++) {j=j/2;} //...loop bobo para simbolizar o tempo de leitura

                System.out.println(this.x.getX() % 2 == 0 ? "@@@ Variavel par @@@" : "@@@ Variavel impar @@@");

                this.monitor.SaiLeitor(this.id);
                sleep(this.delay);
            }
        } catch (InterruptedException e) { return; }
    }
}

//--------------------------------------------------------
// Escritor
class Escritor extends Thread {
    int id; //identificador da thread
    int delay; //atraso bobo...
    LE monitor; //objeto monitor para coordenar a lógica de execução das threads
    Compatilhado x; // variável x compatilhada
    // Construtor
    Escritor (int id, int delayTime, LE m, Compatilhado x) {
        this.id = id;
        this.delay = delayTime;
        this.monitor = m;
        this.x = x;
    }

    // Método executado pela thread
    public void run () {
        double j=777777777.7, i;
        try {
            for (;;) {
                this.monitor.EntraEscritor(this.id);
                for (i=0; i<100000000; i++) {j=j/2;} //...loop bobo para simbolizar o tempo de escrita
                this.x.incrementar();
                this.monitor.SaiEscritor(this.id);
                sleep(this.delay); //atraso bobo...
            }
        } catch (InterruptedException e) { return; }
    }
}
//--------------------------------------------------------
//Classe Leitor e escritor

class LeitoreEscritor extends Thread{
    int id; //identificador da thread
    int delay; //atraso bobo...
    LE monitor; //objeto monitor para coordenar a lógica de execução das threads
    Compatilhado x; // variável x compatilhada

    LeitoreEscritor (int id, int delayTime, LE m, Compatilhado x) {
        this.id = id;
        this.delay = delayTime;
        this.monitor = m;
        this.x = x;
    }

    public void run () {
        double j=777777777.7, i;
        try {
            for (;;) {

                this.monitor.EntraLeitor(this.id);
                System.out.println("@@@ Valor da variavel: " + this.x.getX()+" @@@");
                this.monitor.SaiLeitor(this.id);

                this.monitor.EntraEscritor(this.id);
                for (i=0; i<100000000; i++) {j=j/2;} //...loop bobo para simbolizar o tempo de escrita
                this.x.setX(this.id);
                this.monitor.SaiEscritor(this.id);
                sleep(this.delay); //atraso bobo...
            }
        } catch (InterruptedException e) { return; }
    }

}


//--------------------------------------------------------
// Classe principal
class LeitorEscritor {
    static final int L = 4;
    static final int E = 3;
    static final int lee = 3;

    public static void main (String[] args) {
        int i;
        LE monitor = new LE();            // Monitor (objeto compartilhado entre leitores e escritores)
        Leitor[] l = new Leitor[L];       // Threads leitores
        Escritor[] e = new Escritor[E];   // Threads escritores
        LeitoreEscritor[] LeE = new LeitoreEscritor[lee]; // Threads de leitores e escritores
        Compatilhado x = new Compatilhado(); // variável compatilhada

        //inicia o log de saida
        System.out.println ("import verificaLE");
        System.out.println ("le = verificaLE.LE()");

        for (i=0; i<L; i++) {
            l[i] = new Leitor(i+1, (i+1)*500, monitor,x);
            l[i].start();
        }
        for (i=0; i<E; i++) {
            e[i] = new Escritor(i+1, (i+1)*500, monitor,x);
            e[i].start();
        }

        for (i=0; i<E; i++) {
            LeE[i] = new LeitoreEscritor(i+1, (i+1)*500, monitor,x);
            LeE[i].start();
        }
    }
}