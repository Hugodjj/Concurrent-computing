#include <stdio.h>
#include <pthread.h>

#define TAM 10000 // Tamanho original do array
#define TAM_T1 5000 // Tamanho para a thread 1
#define TAM_T2 5000 // Tamanho para a thread 2


typedef struct {
   int *A,posicaoInicial, posicaoFinal;
} t_Args;

/*
Preenche o array com quantas posições forem necessárias.
*/
int* preencherArray() {
    int i, *array;

    array = calloc(TAM, sizeof(int));
    
    for (i = 0; i < TAM; i++) {
        array[i] = i;
    }
    return array;
}

void *elevar(void * arg){

    t_Args *args = (t_Args *) arg;
    
    for (int i = args->posicaoInicial; i < args->posicaoFinal; i++) {
        args->A[i] = args->A[i] * args->A[i]; 
    }

    pthread_exit(NULL);
}

int main(void){

    pthread_t tid_1, tid_2; // identificador da thread
    int *array = preencherArray();
    t_Args *thread1, *thread2; //argumentos para a thread

/**
 * Thread 1 é responsável por varrer o array da posição 0 até a posição 4999.
 */
    thread1 = malloc(sizeof(t_Args));
    thread1 -> A = array;
    thread1 -> posicaoInicial = 0;
    thread1 -> posicaoFinal = (TAM_T1 - 1);

/**
 * Thread 2 é responsável por varrer o array da posição 5000 até a posição 10000.
 */

    thread2 -> A = array;


    pthread_exit(NULL);

    return 0;
}