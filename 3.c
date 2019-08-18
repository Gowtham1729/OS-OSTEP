#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>


int main(){

int rc = fork();

if(rc==-1){
	printf("Fork Failed");
	return 0;
}
else if(rc==0){
	printf("\nHello");
	
}
else{
	//wait(NULL);
	usleep(10*1000);
	printf("\nGoodbye");
	
}




return 1;
}
