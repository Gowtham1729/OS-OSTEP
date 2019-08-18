#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<string.h>

int main(){

FILE *filepointer;
filepointer = fopen("sampleText.txt", "w");

int rc = fork();

if(rc==-1){
	printf("Fork Failed");
	return 0;
}
else if(rc==0){
	printf("This is child process\n");
	if(filepointer){
		printf("Child process can access the filepointer\n");	
	}
	fprintf(filepointer,"%s", "\nContent from child process\n");
}
else{
	//wait(NULL);
	printf("This is parent process\n");
	if(filepointer){
		printf("Parent process can access the filepointer\n");
	}
	fprintf(filepointer,"%s", "\nContent from parent process\n");
}



fclose(filepointer);


return 1;
}
