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

# include "libft/libft.h"
# include "minilibx/mlx.h"

# define ESC	53

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
} t_img;

typedef struct s_data
{
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	int		F;
	int		C;
	char	**map;
	int		height;
	int		width;
	void	*mlx;
	void	*win;
	t_img	img;
	float*	p_coords;
} t_data;



// parsing.c
void	data_init(t_data *data);
char	*fill_paths(char *str, char *path);
void	fill_rgb(char *str, int *rgb);
void	read_fd(char *filename, t_data *data);

// checks.c
void    check_map(t_data *data);
void	check_surroundings(char **map, int row, int col);

// utils.c
void	error_msg(char *str);
int		fd_len(char *filename);
void	map_size_init(t_data *data);
void	print_matrix(char **mtx);
void	free_data(t_data *data);

#endif
