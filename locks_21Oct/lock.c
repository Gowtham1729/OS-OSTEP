#include<stdio.h>
#include<pthread.h>
#include<assert.h>

int count = 0;
// pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock;

void *increment()
{
    for(int i=0; i<10000; i++){
        pthread_mutex_lock(&lock);
        count++;
        pthread_mutex_unlock(&lock);
    }
}


int main()
{
    pthread_t threads[10];

    int rc = pthread_mutex_init(&lock, NULL);
    assert(rc == 0); // always check success!
    //Can find the use of second argument in pthread_mutex_init() here : https://stackoverflow.com/questions/4252005/what-is-the-attribute-of-a-pthread-mutex

    for(int i=0; i<10; i++)
        pthread_create(&threads[i],NULL,increment,NULL);

    for(int i=0; i<10; i++)
        pthread_join(threads[i],NULL);

    pthread_mutex_destroy(&lock);
    printf("count =  %d\n", count);
    return 0;
}