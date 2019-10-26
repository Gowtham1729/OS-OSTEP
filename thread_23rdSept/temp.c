#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getPPID(int PID){
    char path[40], line[100], temp[10];
    int PPID;
    FILE* fin;
    
    snprintf(path, 40, "/proc/%d/status", PID);
    fin = fopen(path, "r");
    if(!fin) return -1;
    
    while(fgets(line, 100, fin)){
        if(strncmp(line, "PPid:", 5) != 0)  continue;
        sscanf(line, "%s %d", temp, &PPID);
        //printf("%d\n", PPID);
    }
    
    fclose(fin);
    
    return PPID;
};

int main(int argc, char *argv[]){
    if(argc == 1){
        printf("Enter a PID\n");
        return 1;
    }
    
    int PPID=atoi(argv[1]);
    
    do {
        PPID = getPPID(PPID);
        printf("PPID: %d\n", PPID);
    } while (PPID != 0);
    
    return 0;
}
