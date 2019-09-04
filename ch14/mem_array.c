#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    int *str;
    str = (int *)malloc(100*sizeof(int));
    str[100] = 0;
    //str1 = (int *)realloc(str, 105*sizeof(int));
    //printf("%p  %p  %ld", str, str1, str1-str);
    return(0);
}

