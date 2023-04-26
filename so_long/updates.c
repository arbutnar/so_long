/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 21:07:52 by arbutnar          #+#    #+#             */
/*   Updated: 2022/05/17 19:23:56 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_findplayer(t_so_long *struttura)
{
	int	row;
	int	col;

	row = 0;
	while (row < struttura->height)
	{
		col = 0;
		while (col < struttura->width)
		{
			if (struttura->matrice[row][col] == 'P')
			{
				struttura->player_pos.x = col;
				struttura->player_pos.y = row;
			}
			col++;
		}
		row++;
	}
}

void	ft_print_matrix2(t_so_long *struttura, int row, int col)
{			
	if (struttura->matrice[row][col] == '1')
		mlx_put_image_to_window(struttura->mlx_ptr, struttura->win_ptr, \
		struttura->wall, col * 64, row * 64);
	if (struttura->matrice[row][col] == 'P')
		mlx_put_image_to_window(struttura->mlx_ptr, struttura->win_ptr, \
		struttura->personaggino, col * 64, row * 64);
	if (struttura->matrice[row][col] == 'M')
		mlx_put_image_to_window(struttura->mlx_ptr, struttura->win_ptr, \
		struttura->enemy, col * 64, row * 64);
	if (struttura->matrice[row][col] == 'E')
		mlx_put_image_to_window(struttura->mlx_ptr, struttura->win_ptr, \
		struttura->exit, col * 64, row * 64);
	if (struttura->matrice[row][col] == 'C')
		mlx_put_image_to_window(struttura->mlx_ptr, struttura->win_ptr, \
		struttura->object, col * 64, row * 64);
}

void	ft_print_matrix(t_so_long *struttura)
{
	int		row;
	int		col;
	char	*str;

	row = 0;
	while (row < struttura->height)
	{
		col = 0;
		while (col < struttura->width)
		{
			mlx_put_image_to_window(struttura->mlx_ptr, struttura->win_ptr, \
			struttura->pavimento, col * 64, row * 64);
			ft_print_matrix2(struttura, row, col);
			col++;
		}
		row++;
	}
	mlx_put_image_to_window(struttura->mlx_ptr, \
		struttura->win_ptr, struttura->white, 0, 0);
	mlx_string_put(struttura->mlx_ptr, \
		struttura->win_ptr, 5, 5, 250, "MOSSE: ");
	str = ft_itoa(struttura->moves);
	mlx_string_put(struttura->mlx_ptr, struttura->win_ptr, 67, 5, 250, str);
	free(str);
}

int	updates_img2(t_so_long *struttura)
{
	if (struttura->frame < 15)
		struttura->object = struttura->img.object1;
	else if (struttura->frame < 35)
		struttura->object = struttura->img.object2;
	else if (struttura->frame < 45)
		struttura->object = struttura->img.object3;
	else
		struttura->object = struttura->img.object4;
	if (struttura->frame_wall < 10)
		struttura->wall = struttura->img.wall1;
	else if (struttura->frame_wall < 20)
		struttura->wall = struttura->img.wall2;
	else
		struttura->wall = struttura->img.wall3;
	if (struttura->frame == 200)
		struttura->frame = 0;
	if (struttura->frame_wall == 30)
		struttura->frame_wall = 0;
	return (1);
}

int	updates_img(t_so_long *struttura)
{
	struttura->frame += 1;
	struttura->frame_wall += 1;
	if (!struttura->c)
		struttura->exit = struttura->img.exit2;
	else
		struttura->exit = struttura->img.exit1;
	if (struttura->frame % 20 < 10)
		struttura->enemy = struttura->img.enemy1;
	else
		struttura->enemy = struttura->img.enemy2;
	if (struttura->frame < 100)
		struttura->personaggino = struttura->img.personaggino1;
	else
		struttura->personaggino = struttura->img.personaggino2;
	updates_img2(struttura);
	ft_print_matrix(struttura);
	return (1);
}
