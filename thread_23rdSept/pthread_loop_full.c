#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

static int thread_count;

void 
*mythread() 
{
    thread_count++; 
    sleep(100);
}


int
main (int arc, char *argv[])
{
    printf("Started Main\n");

    pthread_t p[30];
    int rc[30];

    for(int i=0; i<30; i++){
        rc[i] = pthread_create(&p[i], NULL, mythread, NULL);
    }
    
    for(int i=0; i<30; i++){
        pthread_join(p[i], NULL);
    }
    
    printf("%d\n", thread_count);
    printf("Exiting Main\n");

    return 0;
}
