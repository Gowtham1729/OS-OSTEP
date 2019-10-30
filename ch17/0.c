#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc, char *argv[])
{
int  k;
//k = atoi(argv[1]);
printf("PID:%d\n", getpid());
//printf("Code:%p\n", main);

int *y = (int*)malloc(3500);


int x[100];
//printf("Stack:%p\n", x);
printf("Heap:%p\n", y);
for (int i =0; i<1000000; i++)
	{
	x[i%100] = i*i-i;
	for (int j =0; j<100000; j++)
		{
		x[j%100] = j*i+j%10;
		}
	}
}
