#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 30

void *
child_thread (void *_args)
{
    /* why typecast to long? */
    long arg = (long) _args;

    printf ("Thread ID: %ld \t VarLoc:%p\n", arg, &arg);
    return (void *) (arg+10);
}


int
main (int arc, char *argv[])
{
    printf("Started Main\n");

    pthread_t child[NUM_THREADS];
    int rc[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++)
        rc[i] = pthread_create (&child[i], NULL, child_thread, (void*) (long) i);
   
    for(int i=0; i < NUM_THREADS; i++){
        void *temp;
        pthread_join(child[i], &temp);
        printf("ID: %d \tReturn Value: %ld\n", i, (long) temp);
    }
   
    printf("Exiting Main\n");

    return 0;
}
