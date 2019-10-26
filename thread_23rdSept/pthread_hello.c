#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void 
*mythread() 
{
    printf("Hello World !!! \n");
    //sleep(100);
}


int
main (int arc, char *argv[])
{
    printf("Started Main\n");

    pthread_t p[5];

    pthread_create(&p[0], NULL, mythread, NULL);
    pthread_create(&p[1], NULL, mythread, NULL);
    pthread_create(&p[2], NULL, mythread, NULL);
    pthread_create(&p[3], NULL, mythread, NULL);
    pthread_create(&p[4], NULL, mythread, NULL);
    
    printf("Exiting Main\n");

    sleep(3);

    return 0;
}
