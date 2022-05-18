#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NTHREADS  5

/* Variaveis globais */
int x = 0;
pthread_mutex_t x_mutex;
pthread_cond_t x_cond;

void *thread_5 (void *t){  

    
    printf("Seja Bem-Vindo\n");
    pthread_mutex_lock(&x_mutex);
    x++;
    pthread_cond_broadcast(&x_cond);
    pthread_mutex_unlock(&x_mutex);


    pthread_exit(NULL);
}

void *thread_1 (void *t){

    pthread_mutex_lock(&x_mutex);
    while(x < 4){
        pthread_cond_wait(&x_cond,&x_mutex);
    }
    printf("Volte Sempre!\n");
    pthread_mutex_unlock(&x_mutex);

    pthread_exit(NULL);
}

void *thread_2 (void *t){


    pthread_mutex_lock(&x_mutex);
    if(x < 1){
        pthread_cond_wait(&x_cond,&x_mutex);
    }
    printf("Fique a vontade.\n");
    x++;

    if (x==4) {
        pthread_cond_signal(&x_cond);
    }

    pthread_mutex_unlock(&x_mutex);
    pthread_exit(NULL);

}

void *thread_3 (void *t){

    pthread_mutex_lock(&x_mutex);
    if(x<1){
        pthread_cond_wait(&x_cond,&x_mutex);
    }
    printf("Sente-se por favor.\n");
    x++;

    if (x==4) {
        pthread_cond_signal(&x_cond);
    }

    pthread_mutex_unlock(&x_mutex);
    pthread_exit(NULL);

}

void *thread_4 (void *t){

    pthread_mutex_lock(&x_mutex);
    if(x < 1){
        pthread_cond_wait(&x_cond,&x_mutex);
    }
    printf("Aceita um copo d’agua?.\n");
    x++;

    if (x==4) {
        pthread_cond_signal(&x_cond);
    }

    pthread_mutex_unlock(&x_mutex);
    pthread_exit(NULL);

}

int main(int argc, char *argv[]){
    int i;
    pthread_t threads[NTHREADS];


    pthread_mutex_init(&x_mutex, NULL);
    pthread_cond_init (&x_cond, NULL);


    pthread_create(&threads[4], NULL, thread_5, NULL);
    pthread_create(&threads[2], NULL, thread_2, NULL);
    pthread_create(&threads[1], NULL, thread_3, NULL);
    pthread_create(&threads[3], NULL, thread_4, NULL);
    pthread_create(&threads[0], NULL, thread_1, NULL);



    for (i = 0; i < NTHREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    printf ("\nFIM\n");


  pthread_mutex_destroy(&x_mutex);
  pthread_cond_destroy(&x_cond);

  return 0;
}