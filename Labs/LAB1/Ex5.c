/* Disciplina: Computacao Concorrente */
/* Prof.: Silvana Rossetto */
/* Módulo 1 - Laboratório: 2 */
/* Codigo: "Eleva todas as posições de um vetor ao quadrado" usando threads em C*/
/* Nome: Hugo Nascimento da Silva*/
/* DRE: 120152161*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define TAM 10000  // Tamanho original do array
#define TAM_T1 5000 // Tamanho para a thread 1
#define TAM_T2 5000 // Tamanho para a thread 2
#define NTHREADS 2  // Número total de threads que serão criadas

// Estrutura para armazenar os argumentos das threads.
typedef struct {
    int *A, posicaoInicial, posicaoFinal;
} t_Args;

// A função "preencherArray()" cria um array sequencial de 0 até n-1

int *preencherArray(){
    int i, *array;
    array = calloc(TAM, sizeof(int));

    for (i = 0; i < TAM; i++) {
        array[i] = i;
    }
    return array;
}

void *elevar(void *arg) {

    t_Args *args = (t_Args *)arg;

    for (int i = args->posicaoInicial; i <= args->posicaoFinal; i++) { // A posição inicial e final variam de acordo com a thread.
        args->A[i] = args->A[i] * args->A[i];
    }

    free(arg); // Libera alocação feita na main
    pthread_exit(NULL);
}

int main(void) {
    int aux[TAM];            // vetor auxiliar para ajudar com a verificação
    pthread_t tid[NTHREADS]; // identificador das threads
    int *array = preencherArray(); // criando um array sequencial
    t_Args *thread1, *thread2; // argumentos para as threads

    /*
     Aqui estamos copiando o vetor array sequencial para um vetor auxiliar,
     afim de fazer a verificação no futuro.
    */
    for (int i = 0; i < TAM; i++) {
        aux[i] = array[i];
    }

    /**
     * Thread 1 é responsável por varrer o array da posição 0 até a posição 4999.
     */
    thread1 = malloc(sizeof(t_Args));
    if (thread1 == NULL) {
        printf("--ERRO: malloc()\n"); exit(-1);
    }

    thread1->A = array;
    thread1->posicaoInicial = 0;
    thread1->posicaoFinal = (TAM_T1 - 1);

    /*
     * Thread 2 é responsável por varrer o array da posição 5000 até a posição 10000.
     */

    thread2 = malloc(sizeof(t_Args));

    if (thread1 == NULL) {
        printf("--ERRO: malloc()\n"); exit(-1);
    }

    thread2->A = array;
    thread2->posicaoInicial = TAM_T2;
    thread2->posicaoFinal = TAM;

    // Aqui estamos criando as duas threads necessárias.
    if (pthread_create(&tid[0], NULL, elevar, (void *)thread1)) {
        printf("--ERRO: pthread_create()\n");
        exit(-1);
    }
    
    if (pthread_create(&tid[1], NULL, elevar, (void *)thread2)) {
        printf("--ERRO: pthread_create()\n");
        exit(-1);
    }

    // Espera as threads anteriores terminarem
    for (int j = 0; j < NTHREADS; j++){
        if (pthread_join(tid[j], NULL)) {
            printf("--ERRO: pthread_join() \n");
            exit(-1);
        }
    }
    
    /*
    Aqui fazemos a verificação se função "elevar()" funcionou. Estamos pegando o vetor auxiliar criado anteriormente,
    após isso, verificamos se a posição do array auxiliar é igual a posição do array elevado ao quadrado.
    */
    for (int j; j < TAM; j++) {
        if (array[j] == aux[j] * aux[j]) {
            continue;
        }
        else {
            printf("\nERRO\n");
            printf("\n%d, erro aqui\n", aux[j]);
            break;
        }
    }
    printf("\nTUDO CERTO!\n\n");

    return 0;
}