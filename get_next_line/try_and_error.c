#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	fd;
    size_t len;
    const char *i;

	fd = open(argv[1], O_RDONLY);
    i = (const char) fd;
    len = strlen(i);
    printf("%zu", len );
}