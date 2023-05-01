#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_map
{
	char	wall;
	char	player;
	char	empty_space;
} t_map;

// utils.c
void	error_msg(char *str);

#endif
