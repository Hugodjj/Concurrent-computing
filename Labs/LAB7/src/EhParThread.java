import java.util.ArrayList;

class S1{

    private ArrayList<Integer> numeros;
    private int num;


    public S1(ArrayList<Integer> numeros) {
        this.numeros = numeros;
        this.num = 0;
    }

    public synchronized void inc(){
        this.num++;
    }

    public synchronized int get(){
        return this.num;
    }

    public synchronized int get(int x){
        return this.numeros.get(x);
    }

}

class T1 extends Thread{
    private int id;

    S1 objetoS;


    public T1(int id, S1 objetoS) {
        this.id = id;
        this.objetoS = objetoS;
    }

    public void run(){
        for (int i = id; i < 100000; i+= EhParThread.NT){
            if((this.objetoS.get(i)%2) == 0){
                objetoS.inc();
            }
        }
    }
}

public class EhParThread {

    public static final int NT = 2;

    public static void main(String[] args) {
        ArrayList<Integer> arrayNumeros = new ArrayList<>();
        Thread[] threads = new Thread[NT];

        for (int i = 0; i< 100000; i++){
            arrayNumeros.add(i);
        }
        S1 s1 = new S1(arrayNumeros);

        for (int i = 0; i< threads.length; i++){
            threads[i] = new T1(i,s1);
        }

        for (int i = 0; i<threads.length; i++){
            threads[i].start();
        }
        for (int i = 0; i< threads.length; i++){
            try { threads[i].join(); } catch (InterruptedException e) { return; }
        }
        System.out.println("Existem " +s1.get()+ " numeros pares.");
    }
}
