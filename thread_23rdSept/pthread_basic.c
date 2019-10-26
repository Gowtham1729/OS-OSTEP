#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

static int thread_count;

void 
*mythread() 
{
    thread_count++;
    // sleep(100); 
}


int
main (int arc, char *argv[])
{
    printf("Started Main\n");

    pthread_t p[10];

    pthread_create(&p[0], NULL, mythread, NULL);
    pthread_create(&p[1], NULL, mythread, NULL);
    pthread_create(&p[2], NULL, mythread, NULL);
    pthread_create(&p[3], NULL, mythread, NULL);
    pthread_create(&p[4], NULL, mythread, NULL);
    pthread_create(&p[5], NULL, mythread, NULL);
    pthread_create(&p[6], NULL, mythread, NULL);
    pthread_create(&p[7], NULL, mythread, NULL);
    pthread_create(&p[8], NULL, mythread, NULL);
    pthread_create(&p[9], NULL, mythread, NULL);
    
    for(int i=0; i<10; i++){
        pthread_join(p[i], NULL);
    }
    
    printf("%d\n", thread_count);
    printf("Exiting Main\n");

    return 0;
}
