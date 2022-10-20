#include <pthread.h>
#include <stdio.h>
#define NUM_THREADS 10

typedef struct thread_data{
    int threadId;
    char name[20];
    //..
}ThreadData;

void *holaMundo(void *arg){
    ThreadData *myData = (ThreadData *)arg;
    printf("Hola desde el hilo y mi id es %d\n", myData->threadId);
    pthread_exit(NULL);
}

int main(){
    ThreadData threadData[NUM_THREADS];
    for(int i = 0; i < NUM_THREADS; i++){
        pthread_t threadId;
        threadData[i].threadId = i;
        pthread_create(&threadId, NULL, holaMundo,(void *) &threadData[i]);
    }
    pthread_exit(NULL);
    printf("NUNCA LLEGA");
    return 0;
}