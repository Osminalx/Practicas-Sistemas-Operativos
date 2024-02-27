#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/wait.h>

#define NumOfThreads 4
#define MaxArrLen 8

int Array[MaxArrLen];
int finalSum;

pthread_mutex_t the_mutex;

void randGen(int *arr){
    for (int i = 0; i < MaxArrLen +1; i++)
    {
        arr[i] = rand() %10;
    }
    
}

void printArr(int *array){
    for (int i = 0
    ; i < MaxArrLen+1; i++)
    {
        printf("%d \n",array[i]);
    }
}

void *arrSum(void *thread){
    int locSum = 0;
    int tId = thread;
    int sep = MaxArrLen/NumOfThreads;
    int init = tId * sep;
    int end =(tId +1 )*sep;
    printf("hola soy el thread %d",tId);
    for (int i = init; i < end; i++)
    {
        locSum+=Array[i];
    }
    printf("sumalocal: %d \n",locSum);
    pthread_mutex_lock(&the_mutex);
    finalSum += locSum;
    pthread_mutex_unlock(&the_mutex);
    pthread_exit(NULL);
}


int main(int argc, char const *argv[])
{
    randGen(Array);
    printArr(Array);
    pthread_t T[NumOfThreads];
    pthread_mutex_init(&the_mutex,0);
    finalSum=0;
    for (int i = 0; i < NumOfThreads; i++)
    {
        pthread_create(&T[i],NULL,arrSum,(void *)i);
    }

    for (int j = 0; j < NumOfThreads; j++)
    {
        pthread_join(T[j],NULL);
    }
    printf("Suma final: %d \n",finalSum);
    pthread_mutex_destroy(&the_mutex);
    return 0;
}
