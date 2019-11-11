#include <stdio.h>     
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>    
#include <stdlib.h>   
#include <fcntl.h>     
#include <string.h>

#define handle_error(msg) \
    do { perror(msg); exit(EXIT_FAILURE); } while (0)

int main(int argc, char *argv[]) {
    struct stat sb;
    int fd, offset, lines;
    char * pathname = "";
    

    if (argc != 3 || strlen(argv[1]) <= 1 || argv[1][0] != '-') {
        fprintf(stderr, "Usage: %s -<offset> <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    lines = atoi(argv[1]);
    lines *= -1;
    lines++;
    pathname = argv[2];
    //printf("%d",lines);

    if (stat(pathname, &sb) == -1)
        handle_error("stat");

    if ((fd = open(pathname, O_RDONLY)) == -1)
        handle_error("open");

    if( (lseek(fd, -1, SEEK_END) == -1) ){
        printf("ERROR");
        exit(EXIT_FAILURE);
    }

    char buff[sb.st_size];

    read(fd, buff, 1);

    printf("\n%s",buff);

    offset = lseek(fd, -2, SEEK_CUR);

    read(fd, buff, 1);

    printf("\n%s",buff);


    /*
    while (lines > 0) {
        if (read(fd, buff, 1) == -1) //read up 1 byte  from fd and store in buffer
            handle_error("read");
        if (buff[0] == '\n')
            lines--;
        offset = lseek(fd, -2, SEEK_CUR);
        if (offset == -1) //offset is -1 on error
            break;
    }
    */
}