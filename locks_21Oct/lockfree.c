#include<stdio.h>
#include<pthread.h>
#include<stdatomic.h> //For including atomic types

_Atomic int atomic_count = 0;
int count = 0;


void *increment()
{
    for(int i=0; i<10000; i++){
        atomic_count++;
        count++;
    }
}


int main()
{
    pthread_t threads[10];

    for(int i=0; i<10; i++)
        pthread_create(&threads[i],NULL,increment,NULL);

    for(int i=0; i<10; i++)
        pthread_join(threads[i],NULL);

    printf("atomic_count = %d\n", atomic_count);
    printf("count =  %d\n", count);
    return 0;
}