#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/wait.h>

#define NT 51
pthread_t Threads[NT];
pthread_mutex_t mutex;
int resultado;

void *suma(void *i){
    int id = i;
    pthread_mutex_lock(&mutex);
    int r = resultado;
    for (int  j = 0; j < 2000; j++)
        for (int k = 0; k < 2000; k++)
    resultado = r+id;
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
    resultado=0;
    int i,error;
    pthread_mutex_init(&mutex,0);

    for(i=0; i<NT;i++){
        error = pthread_create(&Threads[i],NULL,suma,(void *)i);
        pthread_join(&Threads[i],NULL);
        if (error != 0)
        {
            printf("Error: Thread failed %d,i");
        }
        wait(NULL);
        printf("The sum is %d",resultado);
        
    }    
    return 0;
}
