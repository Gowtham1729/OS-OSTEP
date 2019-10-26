#include<stdio.h>
#include<pthread.h>


int count = 0;


void *increment()
{
    for(int i=0; i<10000; i++){
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


    printf("count =  %d\n", count);
    return 0;
}