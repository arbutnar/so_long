/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 18:39:01 by arbutnar          #+#    #+#             */
/*   Updated: 2022/05/18 15:45:12 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_img
{
	void	*enemy1;
	void	*enemy2;
	void	*personaggino1;
	void	*personaggino2;
	void	*exit1;
	void	*exit2;
	void	*object1;
	void	*object2;
	void	*object3;
	void	*object4;
	void	*wall1;
	void	*wall2;
	void	*wall3;
}				t_img;

typedef struct s_vec
{
	int	x;
	int	y;
	int	moves;
}		t_vec;

typedef struct s_so_long
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**matrice;
	int		height;
	int		width;
	void	*enemy;
	void	*personaggino;
	void	*wall;
	void	*exit;
	void	*pavimento;
	void	*object;
	int		frame;
	int		frame_wall;
	int		moves;
	int		c;
	int		e;
	int		p;
	t_vec	player_pos;
	t_img	img;
	t_vec	*enemy_pos;
	int		count_enemy;
	void	*white;
}		t_so_long;

void		matrix(char *filename, t_so_long *struttura);
void		matrix2(t_so_long *struttura, char *filename,
				int height, int width);
void		ft_print_it(char **matrice);
int			ft_height(int fd);
int			ft_width(int fd);
void		ft_riempilamatrice(t_so_long *struttura, char *filename);
void		ft_print_it(char **matrice);
void		ft_print_matrix(t_so_long *struttura);
int			updates_img(t_so_long *struttura);
void		open_images(t_so_long *struttura);
int			main(int argc, char *argv[]);
int			ft_destroy(t_so_long *struttura);
int			ft_error(void);
void		ft_movenemy(t_so_long *struttura);
void		ft_move_up(t_so_long *struttura);
void		ft_move_down(t_so_long *struttura);
void		ft_move_left(t_so_long *struttura);
void		ft_move_right(t_so_long *struttura);
void		ft_move_up_enemy(t_so_long *struttura, int y, int x, int i);
void		ft_move_down_enemy(t_so_long *struttura,
				int y, int x, int i);
void		ft_findplayer(t_so_long *struttura);
char		*ft_itoa(int n);
int			ft_check_map(t_so_long *struttura);
int			ft_hooks(int key, t_so_long *struttura);
void		count_maps(char *str, int z, t_so_long *struttura);

#endif