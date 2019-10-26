#include <stdio.h>  
#include <pthread.h>
#include <assert.h>

int count = 0;
int lock = 0;

char CompareAndSwap(int *ptr, int old, int new) {

unsigned char ret;
// Note that sete sets a ’byte’ not the word
__asm__ ("  lock\n"
"  cmpxchgl %2,%1\n"
"  sete %0\n"
: "=q" (ret), "=m" (ptr)
: "r" (new), "m" (*ptr), "a" (old)
: "memory");
return ret;
}


void *increment(){

    for(int i=0; i<10000; i++){
        while(CompareAndSwap(&lock,0,1)==0);
        count++;
        lock = 0;
    }

    return NULL;
}

int main(){
    pthread_t threads[10];

    for(int i=0; i<10; i++)
        pthread_create(&threads[i],NULL,increment,NULL);

    for(int i=0; i<10; i++)
        pthread_join(threads[i],NULL);

    printf("count =  %d\n", count);
    return 0;      
}