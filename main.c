
#include "structs.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int	main(int argc, char **argv)
{
	(void)argc;
	parse_cub_file(argv[1]);
	return (0);
}
