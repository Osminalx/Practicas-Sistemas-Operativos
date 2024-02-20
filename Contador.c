#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NumberOfThreads 10
#define NumberOfRequest 100

char FILENAME[]="Contador.txt";
FILE *file = NULL;

pthread_mutex_t the_mutex;

int read_file();
int write_file(int);
void *contador(void *);

int main(void){
	//Configuration
	if((file=fopen(FILENAME,"w"))==NULL){
		printf("The file could't be created :(");
		return 0;
	}
	fprintf(file, "%d", 0);
	fclose(file);
	//Semaphore creation
	pthread_mutex_init(&the_mutex, 0); 
	pthread_t T[NumberOfThreads];
	//Thread creation
	for(int i=0; i<NumberOfThreads;i++){
		pthread_create(&T[i],0,contador,0); 
		pthread_join(&T[i],0);
	}
	pthread_mutex_destroy(&the_mutex);

}

void *contador(void *id){
	//Semaphore blocking
	pthread_mutex_init(&the_mutex,0);
	for(int i=0;i<NumberOfRequest;i++){


	}
	pthread_mutex_destroy(&the_mutex);
}


int read_file(){
	int contador;
	if((file=fopen(FILENAME,"r"))==NULL){
		printf("The file could't be readed :(");
		return -1;
	}
	fscanf(file,"%d",&contador);
	fclose(file);
	return contador;
}

int write_file(int c){
	if((file=fopen(FILENAME,"w"))==NULL){
		printf("The file could't be created :(");
		return -1;
	}
	fprintf(file,",%d",c);
	fclose(file);
	return 1;
}
