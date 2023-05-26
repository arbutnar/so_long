/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:31:49 by arbutnar          #+#    #+#             */
/*   Updated: 2023/05/25 14:37:21 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->ll + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

void	twoD_print(t_data *data, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	
	while (i < 64)
	{
		j = 0;
		while (j < 64)
		{
			my_mlx_pixel_put(&data->img, j + x * 64, i + y * 64, 0x00FF0000);
			j++;
		}

		i++;
	}
}

void	create_twoD(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			if (data->map[y][x] == '1')
				twoD_print(data, x, y);
			x++;
		}
		y++;
	}
}

void	player_pos(t_data *data)
{
	int	y;
	int	x;

	y = data->pc.y * 64 - 5;
	while (y != data->pc.y * 64 + 5)
	{
		x = data->pc.x * 64 - 5;
		while (x != data->pc.x * 64 + 5)
		{
			my_mlx_pixel_put(&data->img, x, y, 0x0000ff);
			x++;
		}
		y++;
	}
}

void	fan_radius(t_data * data)
{
	float l_angle;
	float r_angle;

	l_angle = data->pc.pov - 30;
	r_angle = data->pc.pov + 30;
	while(l_angle <= r_angle)
	{
		find_radius(data, l_angle);
		l_angle += 0.5;
	}
}

void	find_radius(t_data *data, float angle)
{
	float	Px;
	float	Py;
	float	c;
	float	s;
	float	m;

	m = 0.01;
	c = cos(angle * RAD);
	s = sin(angle * RAD);
	while (1)
	{
		Py = data->pc.y + s * m;
		Px = data->pc.x + c * m;
		if (data->map[(int)Py][(int)Px] == '1')
			break ;
		my_mlx_pixel_put(&data->img, Px * 64, Py * 64, 0xfbc801);
		m += 0.01;
	}
	// exit(0);
	//printf("%d\n", m);
}
