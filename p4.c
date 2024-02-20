#include <pthread.h>
#include <stdio.h>
#include <sys/wait.h>

#define NT 5

void printT(void *id){
    int i = (int) id;
    printf("Saludos desde el thread #%d\n",i);
    pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
    pthread_t T[NT];// Número de núcleos del procesador disponibles
    int i,e;
    for(i=0;i<NT;i++){
        pthread_create(&T[i],NULL,printT,(void *)i);

        if(e != 0)
            printf("Error\n");
    }
    wait(NULL);

    return 0;
}
