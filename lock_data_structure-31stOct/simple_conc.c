#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <pthread.h>

#define R_SIZE 100
#define T_SIZE 100 //Is this required?

typedef struct __counter_t {
    int value;
    pthread_mutex_t lock;
}counter_t;

counter_t *counter = (counter_t*)malloc(sizeof(counter_t));

void init (counter_t *c) {
    c->value = 0;
    pthread_mutex_init(&c->lock, NULL);
}

void increment (counter_t *c);
void decrement (counter_t *c);
int get(counter_t *c);

void 
*mythread(void *arg) 
{
    //int *ind = (int *) arg; 
    
    for (int i=0; i<R_SIZE; i++) {
        increment (counter);
    }
    
    //printf("%d ", *ind);
}   
 


int
main()
{
    int thread_num;
    struct timeval start, end;
    int rc;


    
    for (thread_num=1; thread_num <= R_SIZE; thread_num++) {
        init (counter);
        pthread_t p[thread_num];
        gettimeofday(&start, NULL);    
                
        for (int i=0; i<thread_num; i++)
            rc = pthread_create(&p[i], NULL, mythread, NULL);
        
        for (int i=0; i<thread_num; i++)
            rc = pthread_join(p[i], NULL);
        
        
        gettimeofday(&end, NULL);
        long elapsed = (end.tv_sec-start.tv_sec)*1000000 + end.tv_usec-start.tv_usec;
        printf("End of Thread Nums %d: %ld\tValue: %d\n", thread_num, elapsed, counter->value);
    }
    return (0);
}



// Function Declerations 

void increment (counter_t *c) {
    pthread_mutex_lock (&c->lock);
    c->value++;
    pthread_mutex_unlock(&c->lock);
}

void decrement (counter_t *c) {
    pthread_mutex_lock (&c->lock);
    c->value--;
    pthread_mutex_unlock(&c->lock);
}

int get(counter_t *c) {
    pthread_mutex_lock (&c->lock);
    int rc = c->value;
    pthread_mutex_unlock(&c->lock);
    return rc;
}
