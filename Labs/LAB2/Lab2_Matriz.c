#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "timer.h"

int nthreads;

float *mat1;
float *mat2;
float *saida_sequencial;
float *saida_concorrente;

int nthreads;
pthread_t *tid;

typedef struct {
    int id, dim;
}tArgs;

void mult_sequencial(int dim){


    for (int i = 0; i<dim; i++){
        for (int j = 0; j< dim; j++){
            mat1[i*dim+j] = 2;
            mat2[i*dim+j] = 2;
        }
    }

    for (int i = 0; i<dim; i++){
        for (int j = 0; j< dim; j++){
            saida_sequencial[i*dim+j] = mat1[i*dim+j] * mat2[i*dim+j];
        }
    }

    //     printf("MATRIZ 1 SEQUENCIAL \n");
    
    // for (int i = 0; i<dim; i++){
    //     for (int j = 0; j< dim; j++){
    //         printf("%.1f ",mat1[i*dim+j]);

    //     }
    //     printf("\n");
    // }
    //     printf("\nMATRIZ 2 SEQUENCIAL \n");

    // for (int i = 0; i<dim; i++){
    //     for (int j = 0; j< dim; j++){
    //         printf("%.1f ",mat2[i*dim+j]);

    //     }
    //     printf("\n");
    // }
        

    // printf("\n MATRIZ RESULTADO SEQUENCIAL\n");
    // for (int i = 0; i<dim; i++){
    //     for (int j = 0; j< dim; j++){
    //         printf("%.1f ",saida_sequencial[i*dim+j]);

    //     }
    //     printf("\n");
    // }

}

void * mult_concorrente(void *arg){
    tArgs *args = (tArgs*) arg;

    for (int i = args->id; i< args->dim; i++){
        for (int j = args->id; j< args->dim; j++){
            saida_concorrente[i*args-> dim + j] = mat1[i*args-> dim + j] * mat2[i*args-> dim + j];
        }
    }
    pthread_exit(NULL);
}

int main(int argc, char* argv[]){

    int dim;
    double inicio, fim, delta;
    tArgs *args;

    GET_TIME(inicio);
    if (argc < 2){
        printf("Digite %s <dimensao da matriz>\n", argv[0]);
        return 1;
    }

    dim = atoi(argv[1]);
    nthreads = atoi(argv[2]);
    
    mat1 = (float *) malloc(sizeof(float)*dim * dim);
    if (mat1 == NULL){
        printf("ERRO-- malloc\n");
        return 2;
    }
    mat2 = (float *) malloc(sizeof(float)*dim * dim);
    if (mat2 == NULL){
        printf("ERRO-- malloc\n");
        return 2;
    }
    saida_sequencial = (float *) malloc(sizeof(float)*dim * dim);
    if (saida_sequencial == NULL){
        printf("ERRO-- malloc\n");
        return 2;
    }
    saida_concorrente = (float *) malloc(sizeof(float)*dim * dim);
    if (saida_concorrente == NULL){
        printf("ERRO-- malloc\n");
        return 2;
    }
    

    mult_sequencial(dim);

    GET_TIME(fim);
    delta = fim - inicio;
    printf("\nTempo para a multiplicacao sequencial: %.5f segundos\n", delta);

    GET_TIME(inicio);

    //     printf("MATRIZ 1 CONCORRENTE \n");
    
    // for (int i = 0; i<dim; i++){
    //     for (int j = 0; j< dim; j++){
    //         printf("%.1f ",mat1[i*dim+j]);

    //     }
    //     printf("\n");
    // }
    //     printf("\nMATRIZ 2 CONCORRENTE \n");

    // for (int i = 0; i<dim; i++){
    //     for (int j = 0; j< dim; j++){
    //         printf("%.1f ",mat2[i*dim+j]);

    //     }
    //     printf("\n");
    // }

    tid = (pthread_t*) malloc(sizeof(pthread_t)*nthreads);
    if(tid==NULL){
    printf("\nERRO--malloc\n"); 
    return 1;
    }

    args = (tArgs*) malloc(sizeof(tArgs)*nthreads);
    if (args == NULL){
        printf("\nERRO -- malloc\n");
    }
    
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

    // printf("\n MATRIZ RESULTADO CONCORRENTE\n");
    // for (int i = 0; i<dim; i++){
    //     for (int j = 0; j< dim; j++){
    //         printf("%.1f ",saida_concorrente[i*dim+j]);

    //     }
    //     printf("\n");
    // }

    GET_TIME(fim);
    delta = fim - inicio;
    printf("\nTempo para a multiplicacao concorrente: %.5f segundos\n", delta);


    free(mat1);
    free(mat2);
    free(saida_concorrente);
    free(saida_sequencial);
    free(tid);
    free(args);

    return 0;
}