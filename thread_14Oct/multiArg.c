#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 30

struct thread_args {
   int first;
   int second;
};

void *
child_thread (void *_args)
{
    struct thread_args *args = (struct thread_args *) _args;
    printf ("Thread ID: %d \t Value:%d\n", args->first, args->second);
    return NULL;
}


int
main (int arc, char *argv[])
{
    printf("Started Main\n");

    pthread_t child[NUM_THREADS];
    int rc[NUM_THREADS];
    struct thread_args args[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++){
        args[i].first=i;
        args[i].second=i*10;
        rc[i] = pthread_create (&child[i], NULL, child_thread, (void*) &args[i]);
    }
   
    for(int i=0; i < NUM_THREADS; i++){
        pthread_join(child[i], NULL);
    }
   
    printf("Exiting Main\n");

    return 0;
}
