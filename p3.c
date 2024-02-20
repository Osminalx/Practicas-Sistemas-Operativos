// Threads - Hilos
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>

void printMat(int **);

int main(int argc, char const *argv[])
{
    int **Mat = (int**) malloc(sizeof(int *)*10);
    int i,j;
    for(i=0; i <10;i++){
        Mat[i] = (int *) malloc(sizeof(int)*10);
        for(j=0;j<10;j++){
            Mat[i][j] = rand() % 100 +1;

        }
    }
    printMat(Mat);
    for(i=0; i <10;i++)
        free(Mat[i]);

    free(Mat);

    return 0;
}

void printMat(int **M){
    int i,j;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            printf("%5d",M[i][j]);
        }
        printf("\n");
    }
}
