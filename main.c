#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
    char *e;
    int i = 0;
    int fd = open("txt", O_CREAT | O_RDWR, 0666);
   while (i != 6)
   {
   e = get_next_line(fd); 
       i++;
   }

}