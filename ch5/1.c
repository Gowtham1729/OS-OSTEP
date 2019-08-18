#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
int x = 100;
int rc = fork();

if(rc == -1){
	printf("Fork Failed");
}
else if(rc == 0){ //child process will execute this
	x = 20;
	printf("This is child process and the value of variable x is %d\n",x);
}
else{ //parent process will execute this
	x = 50;
	printf("This is parent process and the value of the variable x is %d\n",x);

} 

return 1;
}
