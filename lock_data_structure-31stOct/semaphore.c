#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>


int count = 0;

sem_t s;


void *increment()
{
    for(int i=0; i<10000; i++){
        sem_wait(&s);
        count++;
        sem_post(&s);
    }
}


int main()
{
    pthread_t threads[10];
    sem_init(&s, 0, 1);

    for(int i=0; i<10; i++)
        pthread_create(&threads[i],NULL,increment,NULL);

    for(int i=0; i<10; i++)
        pthread_join(threads[i],NULL);


    printf("count =  %d\n", count);
    return 0;
}
