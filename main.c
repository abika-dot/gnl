#include "get_next_line.h"

int main ()
{
	int s = 0;
	int i = open("42_no_nl",O_RDONLY);
	while (s < 2)
	{
		printf("%s\n", get_next_line(i));
		s++;
	}
}
