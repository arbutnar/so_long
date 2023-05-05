/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:23:29 by arbutnar          #+#    #+#             */
/*   Updated: 2023/05/03 15:23:29 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# include <mlx.h>

typedef struct s_data
{
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	int		F;
	int		C;
	char	**map;
} t_data;

// parsing.c
void	data_init(t_data *data);
char	*fill_paths(char *str, char *path);
void	fill_rgb(char *str, int *rgb);
void	read_fd(char *filename, t_data *data);

// utils.c
void	error_msg(char *str);
int		check_fd(char *name);
int		fd_len(char *filename);
void	print_matrix(char **mtx);
void	free_data(t_data *data);

#endif
