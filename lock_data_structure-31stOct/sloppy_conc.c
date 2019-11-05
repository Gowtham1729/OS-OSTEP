#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <pthread.h>

#define R_SIZE 100
#define T_SIZE 100
#define NUMCPUS 4

typedef struct __counter_t {
    int global; 
    pthread_mutex_t glock; 
    int local[NUMCPUS]; 
    pthread_mutex_t llock[NUMCPUS]; 
    int threshold;
} counter_t;

void init(counter_t *c, int threshold) {
    c->threshold = threshold;

    c->global = 0;
    pthread_mutex_init(&c->glock, NULL);

    int i;
    for (i = 0; i < NUMCPUS; i++) {
        c->local[i] = 0;
        pthread_mutex_init(&c->llock[i], NULL);
    }
}
counter_t *counter = (counter_t *) malloc(sizeof(counter_t));



void increment (counter_t *c, int threadID);
int get(counter_t *c);

void 
*mythread(void *arg) {
    long ind = (long) arg; 
    
    //printf("%d ", *ind);
    
    for (int i=0; i<R_SIZE; i++) {
        increment (counter, ind%NUMCPUS);
    }
    
    //printf("%d ", *ind);
}    


int
main() {
    int thread_num;
    struct timeval start, end;
    int rc;
    
    for (thread_num=1; thread_num <= R_SIZE; thread_num++) {
        init(counter, 100);
        pthread_t p[thread_num];
        gettimeofday(&start, NULL);    
                
        for (int i=0; i<thread_num; i++)
            rc = pthread_create(&p[i], NULL, mythread, (void *) (long) i);
        
        for (int i=0; i<thread_num; i++)
            rc = pthread_join(p[i], NULL);
        
        
        gettimeofday(&end, NULL);
        long elapsed = (end.tv_sec-start.tv_sec)*1000000 + end.tv_usec-start.tv_usec;
        printf("End of Thread %d: %ld\tValue: %d\n", thread_num, elapsed, get(counter));
    }
    return (0);
}

// Function Declerations 
void increment(counter_t *c, int threadID) {
    pthread_mutex_lock(&c->llock[threadID]);
    c->local[threadID] ++;
    if (c->local[threadID] >= c->threshold) {
        pthread_mutex_lock(&c->glock);
        c->global += c->local[threadID];
        pthread_mutex_unlock(&c->glock);
        c->local[threadID] = 0;
    }
    pthread_mutex_unlock(&c->llock[threadID]);
}

int get(counter_t *c) {
    pthread_mutex_lock(&c->glock);
    int val = c->global;
    pthread_mutex_unlock(&c->glock);
    return val; 
}
