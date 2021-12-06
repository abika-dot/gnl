#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd = open("txt", O_CREAT | O_RDWR, 0666);
    printf("%s",get_next_line(fd)); 

}