/* Disciplina: Computacao Concorrente */
/* Prof.: Silvana Rossetto */
/* Módulo 1 - Laboratório: 2 */
/* Codigo: "Multiplicação de matrizes" usando threads em C*/
/* Nome: Hugo Nascimento da Silva*/
/* DRE: 120152161*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include "timer.h"

float *mat1;
float *mat2;
float *saida_sequencial;
float *saida_concorrente;

int nthreads; // Quantidade de threads.
pthread_t *tid; // Identificador da thread no sistema.

typedef struct {
    int id, dim;
}tArgs;

/*  Função verificar():

    Responsável por verificar se as matrizes coincidem após a execução da multiplicação concorrente e sequencial.
*/
void verificar(int dim){

    for (int i = 0; i<dim; i++){
        for (int j = 0; j< dim; j++){
            if(saida_concorrente[i*dim+j] != saida_sequencial[i*dim+j]){
                printf("\nERRO--Verificar\n");
                break;
            }
        }
    }
    printf("\nSEM ERRO--Verificar\n");

}

/*  Função alocar_memo():

    Responsável por alocar memoria para as estruturas utilizadas.
*/
void alocar_memo(int dim){

    mat1 = (float *) malloc(sizeof(float)*dim * dim);
    if (mat1 == NULL){
        printf("ERRO-- malloc\n");
        exit(-1);
    }
    mat2 = (float *) malloc(sizeof(float)*dim * dim);
    if (mat2 == NULL){
        printf("ERRO-- malloc\n");
        exit(-1);
    }
    saida_sequencial = (float *) malloc(sizeof(float)*dim * dim);
    if (saida_sequencial == NULL){
        printf("ERRO-- malloc\n");
        exit(-1);
    }
    saida_concorrente = (float *) malloc(sizeof(float)*dim * dim);
    if (saida_concorrente == NULL){
        printf("ERRO-- malloc\n");
        exit(-1);
    }
}


/*  Função mult_sequencial():

    Responsável por fazer a multiplicação de matrizes sequencialmente sem a utilização de threads.
*/
void mult_sequencial(int dim){

    for(int i = 0;i < dim; i++){
      for(int j = 0; j < dim; j++){
         for(int k = 0; k < dim; k++){
            saida_sequencial[i * dim + j] += mat1[i * dim + k] * mat2[k * dim + j];
         }
      }
   }
}

/*  Função mult_concorrente():

    Responsável por realizar a multiplicação de matrizes utilizando threads,
    essa função será a função que as threads irão executar. Cada thread é responsável por uma linha da matriz, 
    seguindo assim até percorrer toda a matriz.
*/

void * mult_concorrente(void *arg){
    tArgs *args = (tArgs*) arg;

    for(int i = args->id;i < args->dim; i+=nthreads){
      for(int j = 0; j < args->dim; j++){
         for(int k = 0; k < args->dim; k++){
            saida_concorrente[i * args->dim + j] += mat1[i * args->dim + k] * mat2[k * args->dim + j];
         }
      }
   }
   pthread_exit(NULL);
}

/*  Função gerar_mat():

    Gera matrizes quadradas aleatórias com valores até 100, 
    além disso, incializa as matrizes de saída com todas as posições zeradas.
*/

void gerar_mat(int dim){

    srand(time(NULL));
    for (int i = 0; i<dim; i++){
        for (int j = 0; j< dim; j++){
            saida_sequencial[i * dim + j] = 0;
            saida_concorrente[i * dim + j] = 0;
            mat1[i*dim+j] = rand() % 100;
            mat2[i*dim+j] = rand() % 100;
        }
    }
}

int main(int argc, char* argv[]){

    int dim; // Dimensão das matrizes
    double inicio, fim, delta; // Variáveis para guardar o tempo de cada execução;
    tArgs *args;

    if (argc < 3){
        printf("Digite %s <dimensao da matriz> <numero de threads>\n", argv[0]);
        return 1;
    }
    dim = atoi(argv[1]);
    nthreads = atoi(argv[2]);
    
    alocar_memo(dim); // Alocando memória antes de qualquer execução
    gerar_mat(dim); //Gerando as matrizes quadradas aleatórias.

    // Da linha 144 até a linha 146 estamos analizando a quantidade de tempo que a multiplicação sequencial levará.
    GET_TIME(inicio); 
    mult_sequencial(dim);
    GET_TIME(fim);
    delta = fim - inicio;
    printf("\nTempo para a multiplicacao sequencial: %.5f segundos\n", delta);

    tid = (pthread_t*) malloc(sizeof(pthread_t)*nthreads);
    if(tid==NULL){
    printf("\nERRO--malloc\n"); 
    return 1;
    }

    args = (tArgs*) malloc(sizeof(tArgs)*nthreads);
    if (args == NULL){
        printf("\nERRO -- malloc\n");
    }

    // Da linha 162 até a linha 180 estamos analizando a quantidade de tempo que a multiplicação concorrente levará.
    GET_TIME(inicio);

    for (int i = 0; i < nthreads; i++){
        (args + i)->dim = dim;
        (args + i)->id = i;
        if(pthread_create(tid+i, NULL, mult_concorrente, (void *) (args+i))){
            printf("--ERRO: pthread_create()\n");
            exit(-1);
        }
    }
    
    for (int i = 0; i < nthreads; i++){
        if (pthread_join(*(tid+i), NULL)) {
            printf("--ERRO: pthread_join() \n");
            exit(-1);
        }
    }

    GET_TIME(fim);
    delta = fim - inicio;
    printf("\nTempo para a multiplicacao concorrente foi de [%.5f segundos], com [%d threads]\n", delta, nthreads);

    verificar(dim); // Verifica se o resultado foi igual como esperado.


    //Liberação de memória.
    free(mat1);
    free(mat2);
    free(saida_concorrente);
    free(saida_sequencial);
    free(tid);
    free(args);

    return 0;
}
