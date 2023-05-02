#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "libft/get_next_line/get_next_line.h"

typedef struct s_data
{
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	int		F;			//int: fare trim della stringa. fare lo split per gli spazi. fare la conversione ad interi. sommare tutti i numeri.
	int		C;
	char	**map;
} t_data;

// init.c
void	data_init(t_data *data);

// utils.c
void	error_msg(char *str);
int		check_fd(char *name);
int		fd_len(char *filename);
int		rgb(char *str);
void	print_matrix(char **mtx);

#endif
