/* Disciplina: Computacao Concorrente */
/* Prof.: Silvana Rossetto */
/* Módulo 1 - Laboratório: 4 */
/* Codigo: "Esse programa calcula e substitui pela raiz quadrada todos os números primos presentes no array." usando threads em C*/
/* Nome: Hugo Nascimento da Silva*/
/* DRE: 120152161*/

#include <stdio.h>
#include <stdlib.h> 
#include <pthread.h>
#include <time.h>
#include <math.h>
#include "timer.h"

long long int dim; // dimensão dos vetores
// Vetor de entrada sera utilizado como base para criação dos vetores concorrentes,
// nthreads são a quantidade de threads,
// var global para a comunicação cas threads;
int *vetorEntrada, nthreads, varGlobal; 
float *vetorSequencial, *vetorConcorrente; 
pthread_mutex_t mutex; // variavel para dar lock e impedir a condição de corrida
pthread_t *tid; // identificador das threads no sistema.

// função que verifica primalidade dos números.
int ehPrimo(long long int n) {
    if (n<=1)
    return 0;
    
    if (n==2)
    return 1;
    
    if (n%2==0)
    return 0;
    
    for (int i=3; i<sqrt(n)+1; i+=2)
        if(n%i==0) return 0;
    return 1;
}
// função das threads 
void *tarefa(void* arg){
    float* vetorThreads = (float *) arg;
    int i = 0;
    while(i < dim){

        pthread_mutex_lock(&mutex);
        i = varGlobal++;
        pthread_mutex_unlock(&mutex);

        if (ehPrimo(vetorEntrada[i]))
            vetorThreads[i] = sqrt(vetorEntrada[i]);
        else
            vetorThreads[i] = vetorEntrada[i];

    }
    pthread_exit(NULL);
}
// Gerando vetores de números aleatórios
void gerar_vet(int dim){

    srand(time(NULL));
    for (int i = 0; i<dim; i++){
        vetorEntrada[i] = rand() % 10000000000;
    }
}

void alocar_memo(int dim){

    vetorEntrada = (int *) malloc(sizeof(int)*dim);
    if (vetorEntrada == NULL){
        printf("ERRO-- malloc 1\n");
        exit(-1);
    }

    vetorSequencial = (float *) malloc(sizeof(float)*dim);
    if (vetorSequencial == NULL){
        printf("ERRO-- malloc 2\n");
        exit(-1);
    }

    vetorConcorrente = (float *) malloc(sizeof(float)*dim);
    if (vetorSequencial == NULL){
        printf("ERRO-- malloc 3\n");
        exit(-1);
    }

    tid = (pthread_t *)malloc(sizeof(pthread_t) * nthreads);
    if (tid == NULL){
        fprintf(stderr, "ERRO--malloc 4\n");
        exit(-1);
    }
}

void free_memo(){
    free(vetorConcorrente);
    free(tid);
    free(vetorSequencial);
    free(vetorEntrada);
}

int main(int argc, char *argv[]){

    double inicio, fim;

    if (argc < 3){
        fprintf(stderr, "Digite: %s <dimensao do vetor> <numero threads>\n", argv[0]);
        return 1;
    }
    dim = atoll(argv[1]);
    nthreads = atoi(argv[2]);

    alocar_memo(dim);
    gerar_vet(dim);
    // programa sequencial
    GET_TIME(inicio);
    for (long long int i = 0; i< dim; i++){

        if (ehPrimo(vetorEntrada[i]))
            vetorSequencial[i] = sqrt(vetorEntrada[i]);
        else
            vetorSequencial[i] = vetorEntrada[i];
    }
    GET_TIME(fim);
    printf("\nTEMPO TEMPO TEMPO SEQUENCIAL: %lf\n", fim - inicio);
    // programa concorrente
    GET_TIME(inicio);
    pthread_mutex_init(&mutex,NULL);

    for (long int i = 0; i < nthreads; i++){
        if (pthread_create(tid + i, NULL, tarefa, (void *)vetorConcorrente)){
            fprintf(stderr, "ERRO--pthread_create\n");
            return 3;
        }
    }

    for (long int i = 0; i < nthreads; i++){
        if (pthread_join(*(tid + i), NULL)){
            fprintf(stderr, "ERRO--pthread_create\n");
            return 3;
        }
    }
    pthread_mutex_destroy(&mutex);
    GET_TIME(fim);
    printf("\n\nTEMPO CONCORRENTEEE: %lf\n\n", fim - inicio);

    // Corretude -- Verificando se os vetores são diferentes
    for (long int i = 0; i<dim; i++){
        if(vetorConcorrente[i] != vetorSequencial[i]){
            return 1;
        }
    }

    free_memo();

    return 0;
}