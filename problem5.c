#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 10
#define NUM_PRODUCERS 1
#define NUM_CONSUMERS 1

char buffer[BUFFER_SIZE];
int siguiente = 0;
bool estaLlena = false;
bool estaVacia = true;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_prod = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_cons = PTHREAD_COND_INITIALIZER;

void *productor(void *arg) {
    char c = 'A';
    while (1) {
        pthread_mutex_lock(&mutex);
        while (estaLlena) {
            pthread_cond_wait(&cond_prod, &mutex);
        }
        buffer[siguiente] = c++;
        siguiente++;
        if (siguiente == BUFFER_SIZE) {
            estaLlena = true;
            estaVacia = false;
        }
        pthread_cond_signal(&cond_cons);
        pthread_mutex_unlock(&mutex);
        if (c > 'Z') {
            break;
        }
    }
    pthread_exit(NULL);
}

void *consumidor(void *arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        while (estaVacia) {
            pthread_cond_wait(&cond_cons, &mutex);
        }
        printf("Consumido: %c\n", buffer[siguiente - 1]);
        siguiente--;
        if (siguiente == 0) {
            estaVacia = true;
            estaLlena = false;
        }
        pthread_cond_signal(&cond_prod);
        pthread_mutex_unlock(&mutex);
        if (siguiente == 0) {
            break;
        }
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t productores[NUM_PRODUCERS];
    pthread_t consumidores[NUM_CONSUMERS];

    for (int i = 0; i < NUM_PRODUCERS; i++) {
        pthread_create(&productores[i], NULL, productor, NULL);
    }

    for (int i = 0; i < NUM_CONSUMERS; i++) {
        pthread_create(&consumidores[i], NULL, consumidor, NULL);
    }

    for (int i = 0; i < NUM_PRODUCERS; i++) {
        pthread_join(productores[i], NULL);
    }

    for (int i = 0; i < NUM_CONSUMERS; i++) {
        pthread_join(consumidores[i], NULL);
    }

    return 0;
}
