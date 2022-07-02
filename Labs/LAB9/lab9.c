/* Disciplina: Computacao Concorrente */
/* Prof.: Silvana Rossetto */
/* Módulo 3 - Laboratório: 9 */
/* Codigo: "Esse programa printa frases em uma determinada ordem." usando threads e semáforos em C*/
/* Nome: Hugo Nascimento da Silva*/
/* DRE: 120152161*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

#define NTHREADS  5 // quantidade de threads

/* Variaveis globais */
int x = 0;
sem_t sem_1; // semáforo 1 que ficará responsável pela lógica das threads do meio
sem_t sem_2; // semáforo 2 que recebera o sinal quando estiver pronta para executar

// thread 5 resposável por imprimir a frase "Seja bem-vindo"
void *thread_5 (void *t){  


    printf("Seja Bem-Vindo\n"); // printa indepentente de qualquer verificação

    x++; // incrementa a variável global
   sem_post(&sem_1);


    pthread_exit(NULL);
}

// thread 1 resposável por imprimir a frase "Volte sempre" sempre por último.
void *thread_1 (void *t){

    sem_wait(&sem_2);
    printf("Volte Sempre!\n");


    pthread_exit(NULL);
}

/*
As threads 2, 3 e 4 não tem ordem de execução definida, podem se misturar.
*/

void *thread_2 (void *t){


    sem_wait(&sem_1);
    printf("Fique a vontade.\n");
    x++;

    if (x==4) {// se x for 4 libera o sinal para desbloquear a thread 1 que printará "Volte sempre"
    
        sem_post(&sem_2);
    }
    sem_post(&sem_1);
    pthread_exit(NULL);

}

void *thread_3 (void *t){

    sem_wait(&sem_1);

    printf("Sente-se por favor.\n");
    x++;

    if (x==4) {// se x for 4 libera o sinal para desbloquear a thread 1 que printará "Volte sempre"
    
        sem_post(&sem_2);
    }

    sem_post(&sem_1);
    pthread_exit(NULL);

}

void *thread_4 (void *t){

    
    sem_wait(&sem_1);
    printf("Aceita um copo de agua?.\n");
    x++;

    if (x==4) {// se x for 4 libera o sinal para desbloquear a thread 1 que printará "Volte sempre"
    
        sem_post(&sem_2);
    }
    sem_post(&sem_1);
    pthread_exit(NULL);

}

int main(int argc, char *argv[]){
    int i;
    pthread_t threads[NTHREADS];

    // inicializa as variáveis globais
    sem_init(&sem_1,0,0);
    sem_init(&sem_2,0,0);

    // cria as threads
    pthread_create(&threads[4], NULL, thread_5, NULL);
    pthread_create(&threads[2], NULL, thread_2, NULL);
    pthread_create(&threads[1], NULL, thread_3, NULL);
    pthread_create(&threads[3], NULL, thread_4, NULL);
    pthread_create(&threads[0], NULL, thread_1, NULL);


    // espera todas as threads terminarem
    for (i = 0; i < NTHREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    printf ("\nFIM\n");

    // desaloca memória e destrói as variáveis globais
    sem_destroy(&sem_1);
    sem_destroy(&sem_2);

  return 0;
}