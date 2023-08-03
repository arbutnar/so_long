/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_utility.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:31:49 by arbutnar          #+#    #+#             */
<<<<<<< HEAD:cub3d/loop_utility.c
/*   Updated: 2023/06/07 12:35:00 by marvin           ###   ########.fr       */
=======
/*   Updated: 2023/06/05 11:54:07 by arbutnar         ###   ########.fr       */
>>>>>>> ba82e7a5f7a928ba39c18ecf43c7797c76efe1aa:loop_utility.c
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->ll + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	player_pos(t_data *data)
{
	int	y;
	int	x;

	y = data->pc.y * UNIT_SIZE - 5;
	while (y < data->pc.y * UNIT_SIZE + 5)
	{
		x = data->pc.x * UNIT_SIZE - 5;
		while (x < data->pc.x * UNIT_SIZE + 5)
		{
			my_mlx_pixel_put(&data->img, x, y, WHITE);
			x++;
		}
		y++;
	}
}

void	print_minimap(t_data *data, int x, int y)
{
	int	i;
	int	j;
	int	color;

	if (data->map[y][x] == '1')
		color = RED;
<<<<<<< HEAD:cub3d/loop_utility.c
	else if (data->map[y][x] == 'D')
		color = GREEN;
	else if (data->map[y][x] == 'A')
		color = PURPLE;
=======
	else
		color = GREEN;
>>>>>>> ba82e7a5f7a928ba39c18ecf43c7797c76efe1aa:loop_utility.c
	i = 0;
	while (i < UNIT_SIZE)
	{
		j = 0;
		while (j < UNIT_SIZE)
		{
			my_mlx_pixel_put(&data->img, j + x * UNIT_SIZE, i
				+ y * UNIT_SIZE, color);
			j++;
		}
		i++;
	}
}

void	create_minimap(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
<<<<<<< HEAD:cub3d/loop_utility.c
			if (data->map[y][x] == '1' || data->map[y][x] == 'D'
				|| data->map[y][x] == 'A')
=======
			if (data->map[y][x] == '1' || data->map[y][x] == 'D')
>>>>>>> ba82e7a5f7a928ba39c18ecf43c7797c76efe1aa:loop_utility.c
				print_minimap(data, x, y);
			x++;
		}
		y++;
	}
}

void	fill_screen(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < SCR_HEIGHT)
	{
		x = 0;
		while (x < SCR_WIDTH)
		{
			my_mlx_pixel_put(&data->img, x, y, BLACK);
			x++;
		}
		y++;
	}
}
