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
	printf("\nHello this is child process executing");
	
	char *const envp[]={NULL};	

	//different variations of exec
	//execl("/bin/ls","ls", NULL);
	//execlp("ls","ls", NULL);
	//execle("/bin/ls","ls", NULL, envp);
	
	char *const argv[]={"ls",NULL};
	//execv("/bin/ls",argv);
	//execvp("ls",argv);
	//execvpe("ls", argv, envp);
	
}
else{
	wait(NULL);
	printf("\nThis is parent process executing");
	
}




return 1;
}
