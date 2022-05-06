/* Disciplina: Computacao Concorrente */
/* Prof.: Silvana Rossetto */
/* Módulo 1 - Laboratório: 2 */
/* Codigo: "Encontrar o maior e menor elemento em um vetor" usando threads em C*/
/* Nome: Hugo Nascimento da Silva*/
/* DRE: 120152161*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include "timer.h"

long int dim;   // dimensao do vetor de entrada
int nthreads;   // numero de threads
pthread_t *tid; // identificadores das threads no sistema
double *vetor;  // vetor de entrada com dimensao dim

typedef struct{
    double maior_conc_thread, menor_conc_thread;
} tReturnMaiorMenor;

// fluxo das threads
void *tarefa(void *arg){
    long int id = (long int)arg; // identificador da thread

    long int tamBloco = dim / nthreads; // tamanho do bloco de cada thread
    long int ini = id * tamBloco;       // elemento inicial do bloco da thread
    long int fim;                       // elemento final(nao processado) do bloco da thread

    tReturnMaiorMenor *maiorMenor;

    maiorMenor = (double *)malloc(sizeof(tReturnMaiorMenor));

    if (maiorMenor == NULL){
        exit(1);
    }

    if (id == nthreads - 1){
        fim = dim;
    }
    else
        fim = ini + tamBloco; // trata o resto se houver

    maiorMenor->maior_conc_thread = vetor[0];// maior numero recebe o vetor[0], só para garantir que temos um valor válido sempre.
    maiorMenor->menor_conc_thread = vetor[0];// menor numero recebe o vetor[0], só para garantir que temos um valor válido sempre.

    // iterando pelo vetor procurando o maior e menor elemento.
    for (long int i = ini; i < fim; i++){
        if (vetor[i] > maiorMenor->maior_conc_thread){
            maiorMenor->maior_conc_thread = vetor[i];
        }
        if (vetor[i] < maiorMenor->menor_conc_thread){
            maiorMenor->menor_conc_thread = vetor[i];
        }
    }
    // retorna o resultado do maior e menor local
    pthread_exit((void *)maiorMenor);
}
//preenche o vetor
void preencher_vet(long int dim){

    for (long int i = 0; i < dim; i++)
        vetor[i] = 1000.1 / (i + 1);
        
}

void alocar_memo(long int dim){
    vetor = (double *)malloc(sizeof(double) * dim);
    if (vetor == NULL){
        fprintf(stderr, "ERRO--malloc\n");
        exit(-1);
    }

    tid = (pthread_t *)malloc(sizeof(pthread_t) * nthreads);
    if (tid == NULL){
        fprintf(stderr, "ERRO--malloc\n");
        exit(-1);
    }
}

// fluxo principal
int main(int argc, char *argv[]){
    double maior_seq, menor_seq, maior_conc, menor_conc;
    double ini, fim;            // tomada de tempo
    tReturnMaiorMenor *retorno; // valor de retorno das threads

    // recebe e valida os parametros de entrada (dimensao do vetor, numero de threads)
    if (argc < 3)
    {
        fprintf(stderr, "Digite: %s <dimensao do vetor> <numero threads>\n", argv[0]);
        return 1;
    }
    dim = atoll(argv[1]);
    nthreads = atoi(argv[2]);
    // aloca memoria para estruturas utilizadas
    alocar_memo(dim);
    // preenche o vetor de entrada
    preencher_vet(dim);

    // maior e menor sequencial
    GET_TIME(ini);
    maior_seq = vetor[0];
    menor_seq = vetor[0];
    for (long int i = 0; i < dim; i++){
        if (vetor[i] > maior_seq){
            maior_seq = vetor[i];
        }
        if (vetor[i] < menor_seq){
            menor_seq = vetor[i];
        }
    }
    GET_TIME(fim);
    printf("Tempo sequencial:  %lf\n", fim - ini);

    // maior e menor concorrente
    GET_TIME(ini);

    // criar as threads
    for (long int i = 0; i < nthreads; i++){
        if (pthread_create(tid + i, NULL, tarefa, (void *)i)){
            fprintf(stderr, "ERRO--pthread_create\n");
            return 3;
        }
    }

    maior_conc = vetor[0];
    menor_conc = vetor[0];

    // aguardar o termino das threads
    for (long int i = 0; i < nthreads; i++){
        if (pthread_join(*(tid + i), (void**) &retorno)){
            fprintf(stderr, "ERRO--pthread_create\n");
            return 3;
        // vendo o maior e menor de cada thread
        }

        if (maior_conc < retorno->maior_conc_thread){
            maior_conc = retorno->maior_conc_thread;
        }
        if (menor_conc > retorno->menor_conc_thread){
            menor_conc = retorno->menor_conc_thread;
        }
    }
    GET_TIME(fim);
    printf("\nTempo concorrente:  %lf\n", fim - ini);

    printf("Solucao Sequencial:\n");
    printf("O maior numero encontrado foi %lf e o menor foi %lf\n", maior_seq, menor_seq);
    printf("Solucao Concorrente:\n");
    printf("O maior numero encontrado foi %lf e o menor foi %lf\n", maior_conc, menor_conc);

    // libera as areas de memoria alocadas
    free(vetor);
    free(tid);

    return 0;
}