/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:10:18 by arbutnar          #+#    #+#             */
/*   Updated: 2023/05/25 13:12:13 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d"

void	twodimensional_print(t_data *data, int x, int y)
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

void	create_twodimension(t_data *data)
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
				flatlandia(data, x, y);
			x++;
		}
		y++;
	}
}

void	player(t_data *data)
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

void	find_radius(t_data *data)
{
	float	Px;
	float	Py;
	float	c;
	float	s;
	float	m;

	m = 0.1;
	c = cos(data->pc.pov * RAD);
	s = sin(data->pc.pov * RAD);
	while (m < 200)
	{
		Py = data->pc.y * 64 + s * m;
		Px = data->pc.x * 64 + c * m;
		my_mlx_pixel_put(&data->img, Px, Py, 0xfbc801);
		m += 0.5;
	}
}