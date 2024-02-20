#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char **argv){
    printf("Soy tu padre :) y tengo un pid %d!!!\n",getpid());
    int a = 0;
    int M[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
    int V[3] = {1,2,3};
    int n = sizeof(V) / sizeof(V[0]);
    pid_t pid = fork();
    if(pid<0){
        perror("Lo sentimos no se pudo crear el proceso :(!!\n");
        return 0;
    }else if(pid == 0){
        
        
        for(int i = 0; i<n;i++){
            a += M[1][i] * V[i];
            printf("El valor de a siendo el primer hijo es: %d\n",a);
        }
        pid_t pid2 = fork();
        if(pid2 == 0){
            for(int i = 0; i<n;i++){
            a += M[2][i] * V[i];
            printf("El valor de a siendo el segundo hijo es: %d\n",a);
        }
        
        }
        //printf("Yo soy el hijo y tengo un pid %d y mi variable es %d\n", getpid(),a);
        

        exit(1);
    }
    wait(NULL);
    //printf("Yo soy el padre y cree un hijo con pid %d y mi variable es %d\n",pid,a);
    for(int i =0; i < n; i++){
        a += M[0][i] * V[i];
    }
    printf("El valor de a siendo el padre es: %d\n",a);

    return 0;
}