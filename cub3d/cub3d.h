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
# include "mlx/mlx.h"

# define RAD	0.0174533
# define NOME_CHE_INDICA_POI_LO_CERCO	64

//keypress
// # define W		119
// # define A		97
// # define S		115
// # define D		100
// # define ESC	65307
// # define LEFT	65361
// # define RIGHT	65363
# define W		13
# define A		0
# define S		1
# define D		2
# define LEFT	123
# define RIGHT	124
# define ESC	53

# define SPEED	0.05
# define SENSIBILITY 1

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
} t_img;


typedef struct s_pc
{
	int		pov;
	float	x;
	float	y;
} t_pc;

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
	t_pc	pc;
	int		w;
	int		a;
	int		s;
	int		d;
	int		lf;
	int		rg;
} t_data;



// parsing.c
void	data_init(t_data *data);
char	*fill_paths(char *str, char *path);
void	fill_rgb(char *str, int *rgb);
void	read_fd(char *filename, t_data *data);

// checks.c
void    check_map(t_data *data);
void	check_surroundings(char **map, int row, int col);

// loop_utility.c
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	twoD_print(t_data *data, int x, int y);
void	create_twoD(t_data *data);
void	player_pos(t_data *data);
void	fan_radius(t_data *data);
void	find_radius(t_data *data, float angle);

// movement.c
int		key_on(int keycode, t_data *data);
int		key_off(int keycode, t_data *data);
void	On_or_Off(t_data *data);

// utility.c
void	error_msg(char *str);
int		fd_len(char *filename);
void	map_size_init(t_data *data);
void	print_matrix(char **mtx);
void	free_data(t_data *data);

#endif
