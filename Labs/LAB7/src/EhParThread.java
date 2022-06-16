/* Disciplina: Computacao Concorrente */
/* Prof.: Silvana Rossetto */
/* Módulo 2 - Laboratório: 7 */
/* Codigo: "Esse programa verifica quantos numeros pares existem em um array de numeros inteiros." usando threads em C*/
/* Nome: Hugo Nascimento da Silva*/
/* DRE: 120152161*/

import java.util.ArrayList;

//Classe que para recursos compartilhados entre as threads

class S1{

    // recursos compartilhados
    private ArrayList<Integer> numeros;
    private int num;

    // construtor da classe
    public S1(ArrayList<Integer> numeros) {
        this.numeros = numeros;
        this.num = 0;
    }

    // métodos de sincronização entre as threads
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

//classe que estende Thread e implementa a tarefa de cada thread do programa
class T1 extends Thread{
    // id da thread
    private int id;

    // objeto compartilhado com as outras threads
    S1 objetoS;


    // construtor
    public T1(int id, S1 objetoS) {
        this.id = id;
        this.objetoS = objetoS;
    }

    // método main da thread
    public void run(){
        for (int i = id; i < 100000; i+= EhParThread.NT){
            if((this.objetoS.get(i)%2) == 0){
                objetoS.inc();
            }
        }
    }
}

// classe principal
public class EhParThread {

    public static final int NT = 2;

    public static void main(String[] args) {
        // vetor de numeros
        ArrayList<Integer> arrayNumeros = new ArrayList<>();
        // vetor de threads
        Thread[] threads = new Thread[NT];

        // instanciando um objeto para utilizar recursos compartilhados
        S1 s1 = new S1(arrayNumeros);

        // preenchendo o array
        for (int i = 0; i< 100000; i++){
            arrayNumeros.add(i);
        }
        // criação das threads
        for (int i = 0; i< threads.length; i++){
            threads[i] = new T1(i,s1);
        }

        // inicio das threads
        for (int i = 0; i<threads.length; i++){
            threads[i].start();
        }

        // espera todas as threads terminarem.
        for (int i = 0; i< threads.length; i++){
            try { threads[i].join(); } catch (InterruptedException e) { return; }
        }
        System.out.println("Existem " +s1.get()+ " numeros pares.");
    }
}
