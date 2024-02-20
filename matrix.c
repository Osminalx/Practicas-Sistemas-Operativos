#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 10000 // Tamaño de las matrices
#define NT 4 // Numero de threads

int A[N][N], B[N][N], C[N][N]; // Matrices para la multiplicación y el resultado
pthread_t threads[NT]; // Arreglo para los threads

// Estructura para pasar argumentos a la función del hilo
struct ThreadArgs {
    int thread_id;
};

// Función que ejecutará cada hilo
void *multiply(void *arg) {
    struct ThreadArgs *args = (struct ThreadArgs *)arg;
    int start_row = args->thread_id * (N / NT);
    int end_row = (args->thread_id + 1) * (N / NT);

    // Multiplicación de matrices
    for (int i = start_row; i < end_row; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    pthread_exit(NULL);
}

int main() {
    // Inicializar matrices A y B con números aleatorios
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }
    }

    // Imprimir matrices A y B
    printf("Matriz A:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz B:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    // Crear threads
    struct ThreadArgs args[NT];
    for (int i = 0; i < NT; i++) {
        args[i].thread_id = i;
        pthread_create(&threads[i], NULL, multiply, (void *)&args[i]);
    }

    // Esperar a que los threads terminen
    for (int i = 0; i < NT; i++) {
        pthread_join(threads[i], NULL);
    }

    // Imprimir la matriz resultante C
    printf("\nMatriz C (resultado de la multiplicación):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
