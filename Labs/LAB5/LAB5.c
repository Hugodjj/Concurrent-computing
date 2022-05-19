/* Disciplina: Computacao Concorrente */
/* Prof.: Silvana Rossetto */
/* Módulo 2 - Laboratório: 5 */
/* Codigo: "Esse programa printa frases em uma determinada ordem." usando threads em C*/
/* Nome: Hugo Nascimento da Silva*/
/* DRE: 120152161*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NTHREADS  5 // quantidade de threads

/* Variaveis globais */
int x = 0;
pthread_mutex_t x_mutex; // variável de exclusão mútua das threads
pthread_cond_t x_cond;

// thread 5 resposável por imprimir a frase "Seja bem-vindo"
void *thread_5 (void *t){  


    
    printf("Seja Bem-Vindo\n"); // printa indepentente de qualquer verificação
    pthread_mutex_lock(&x_mutex);
    x++; // incrementa a variável global
    pthread_cond_broadcast(&x_cond);
    pthread_mutex_unlock(&x_mutex);


    pthread_exit(NULL);
}

// thread 1 resposável por imprimir a frase "Volte sempre" sempre por último.
void *thread_1 (void *t){

    pthread_mutex_lock(&x_mutex);
    while(x < 4){// enquanto x não for 4 espera o sinal das outras threads para executar
        pthread_cond_wait(&x_cond,&x_mutex);
    }
    printf("Volte Sempre!\n"); // quando x==4 imprime a frase
    pthread_mutex_unlock(&x_mutex);

    pthread_exit(NULL);
}

/*
As threads 2, 3 e 4 não tem ordem de execução definida, podem se misturar.
*/

void *thread_2 (void *t){


    pthread_mutex_lock(&x_mutex);
    if(x < 1){ // verifica se x é menor que 1, se x for menor que 1 significa que a thread 5 não executou ainda
        pthread_cond_wait(&x_cond,&x_mutex);
    }
    printf("Fique a vontade.\n");
    x++;

    if (x==4) { // se x for 4 manda um sinal para desbloquear a thread 1 que printará "Volte sempre"
        pthread_cond_signal(&x_cond);
    }

    pthread_mutex_unlock(&x_mutex);
    pthread_exit(NULL);

}

void *thread_3 (void *t){

    pthread_mutex_lock(&x_mutex);
    if(x<1){// verifica se x é menor que 1, se x for menor que 1 significa que a thread 5 não executou ainda
        pthread_cond_wait(&x_cond,&x_mutex);
    }
    printf("Sente-se por favor.\n");
    x++;

    if (x==4) {// se x for 4 manda um sinal para desbloquear a thread 1 que printará "Volte sempre"
        pthread_cond_signal(&x_cond);
    }

    pthread_mutex_unlock(&x_mutex);
    pthread_exit(NULL);

}

void *thread_4 (void *t){

    pthread_mutex_lock(&x_mutex);
    if(x < 1){// verifica se x é menor que 1, se x for menor que 1 significa que a thread 5 não executou ainda
        pthread_cond_wait(&x_cond,&x_mutex);
    }
    printf("Aceita um copo d’agua?.\n");
    x++;

    if (x==4) {// se x for 4 manda um sinal para desbloquear a thread 1 que printará "Volte sempre"
        pthread_cond_signal(&x_cond);
    }

    pthread_mutex_unlock(&x_mutex);
    pthread_exit(NULL);

}

int main(int argc, char *argv[]){
    int i;
    pthread_t threads[NTHREADS];

    // inicializa as variáveis globais
    pthread_mutex_init(&x_mutex, NULL);
    pthread_cond_init (&x_cond, NULL);

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
    pthread_mutex_destroy(&x_mutex);
    pthread_cond_destroy(&x_cond);

  return 0;
}