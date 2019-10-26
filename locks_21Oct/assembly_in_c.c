#include<stdio.h>
#include<pthread.h>
#include<assert.h>

int count = 0;
int mutex = 0;

void *increment()
{
    for(int i=0; i<1000; i++){
        __asm__("add $1, %0":"+r"(count));
    }
    // __asm__("addl $1000, %0":"+m"(count));
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
