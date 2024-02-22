#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/wait.h>

#define NumOfThreads 4
#define MaxArrLen 10

int Array[MaxArrLen];

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

void arrSum(){
}


int main(int argc, char const *argv[])
{
    randGen(Array);
    printArr(Array);
    return 0;
}
