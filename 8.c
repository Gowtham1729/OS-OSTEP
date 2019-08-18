#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
#define MSGSIZE 512

int main(){

//create the pipe buffer
char inbuf[MSGSIZE];
//pipe file descriptors fd[0] is for read, fd[1] is for write
int fd[2];

//a successful pipe system call return 1, -1 otherwise
if(pipe(fd)<0)
	exit(1);

int rc1 = fork();

if(rc1<0){
	printf("Fork has failed");
	exit(1);
}
else if(rc1==0){
	//to be executed by the child process
	printf("\nThis is the 1st Child Process");
	//this child wont read, it will only write. Hence read fd is closed
	close(fd[0]);
	//write file descriptor of pipe() replaced by STANDARD_OUTPUT
	dup2(fd[1],1);
	printf("\nThis standard output is sent to pipe write fd");
}

else{
	//now we fork again to create the second child
	waitpid(rc1,NULL,0); //looks like this does not work.
	int rc2 = fork();
	if(rc2<0){
		printf("\nSecond fork has failed");
		exit(1);
	}
	else if(rc2==0){
		printf("\nThis is the 2nd Child Process");
		close(fd[1]);
		//read file descriptor of pipe() replaced with STANDARD_INPUT
		dup2(fd[0],0);

		read(STDIN_FILENO, inbuf, MSGSIZE);
		printf("%s",inbuf);
	}
	else{
		waitpid(rc2,NULL,0);
		printf("\nGoodbye from parent");
	}
}

return 1;
}
