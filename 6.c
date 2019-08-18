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
	
	printf("\nHello this is child process executing with pid = %d",getpid());
	
	
}
else{
	waitpid(-1,NULL,0);
	printf("\nThis is parent process executing with pid = %d", getpid());
	
}




return 1;
}
