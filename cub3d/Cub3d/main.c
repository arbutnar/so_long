#include "cub3d.h"

void	read_file(char *name)
{
	int fd;

	read(fd)
}

void	check_file(char *name)
{
	int fd;

	fd = open(name, O_RDONLY);
	if (!fd)
		error_msg("File");
	close(fd);
}

int main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		error_msg("Arg");
	check_file(argv[1]);
	read_file(argv[1]);	
	return 0;
}