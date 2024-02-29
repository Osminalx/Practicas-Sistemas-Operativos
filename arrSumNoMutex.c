#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/wait.h>

#define NumOfThreads 4
#define MaxArrLen 8

int Array[MaxArrLen];
int finalSum;

void randGen(int *arr){
    for (int i = 0; i < MaxArrLen; i++)
    {
        arr[i] = rand() %10;
    }
}

void printArr(int *array){
    for (int i = 0; i < MaxArrLen; i++)
    {
        printf("%d \n",array[i]);
    }
}

void *arrSum(void *thread){
    int locSum = 0;
    int tId = (int)thread;
    int sep = MaxArrLen/NumOfThreads;
    int init = tId * sep;
    int end =(tId +1 )*sep;
    printf("hola soy el thread %d",tId);
    for (int i = init; i < end; i++)
    {
        locSum += Array[i];
    }
    printf("sumalocal: %d \n",locSum);
    pthread_exit((void *)locSum);
}

int main(int argc, char const *argv[])
{
    randGen(Array);
    printArr(Array);
    pthread_t T[NumOfThreads];
    finalSum=0;
    for (int i = 0; i < NumOfThreads; i++)
    {
        pthread_create(&T[i],NULL,arrSum,(void *)i);
    }

    for (int j = 0; j < NumOfThreads; j++)
    {
        int locSum;
        pthread_join(T[j], (void **)&locSum);
        finalSum += locSum;
    }
    printf("Suma final: %d \n",finalSum);
    return 0;
}
