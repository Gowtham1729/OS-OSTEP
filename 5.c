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
	//wait(NULL);  wait returns -1 here because there is no child of child process
	printf("\nHello this is child process executing with pid = %d",getpid());
	
	
}
else{
	int r;
	r = wait(NULL);
	printf("\nThis is parent process executing with pid = %d", getpid());
	//printf("\n%d",r); //wait return PID of the child
}




return 1;
}
