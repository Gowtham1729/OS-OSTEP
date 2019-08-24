#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

int main(int argc, char* argv[]){
	printf("\nCurrent Process ID = %d",getpid());
	int size = atoi(argv[1])*1024*1024; //in bytes

	int* buffer = (int*)malloc(size);


	//run the while loop for given amount of time.
	time_t endwait,seconds=atoi(argv[2]),start=time(NULL);
	endwait = start + seconds;

	while(start<endwait){
		start = time(NULL);
		printf(".");
		for(int i=0; i<size/sizeof(int); i++){
			buffer[i] =i; 
		}
	}
	return 0;
}
