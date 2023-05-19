/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:23:13 by arbutnar          #+#    #+#             */
/*   Updated: 2023/05/03 15:23:13 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int	destroy(t_data *data)
{
	// keycode == ESC
	mlx_destroy_window(data->mlx, data->win);
	free_data(data);
	exit (EXIT_SUCCESS);
	return (0);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->ll + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

void	flatlandia(t_data *data, int x, int y)
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

void	create(t_data *data)
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

	y = data.p_coords[0] * 64
	x = data.p_coords[1] * 64;
	while ()
		my_mlx_pixel_put(&data.img, x, y, 0x0000ff);
	
}

int main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		error_msg("Arg");
	data_init(&data);
	read_fd(argv[1], &data);
	check_map(&data);
	printf("%f\n", data.p_coords[0]);
	printf("%f\n", data.p_coords[1]);
		// printf("%s", data.NO);
		// printf("%s", data.SO);
		// printf("%s", data.WE);
		// printf("%s", data.EA);
		// printf("%d\n", data.F);
		// printf("%d\n", data.C);
		// print_matrix(data.map);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.width * 64, data.height * 64, "cub3d");
	data.img.img = mlx_new_image(data.mlx, data.width * 64, data.height * 64);
	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bpp,
								&data.img.ll, &data.img.endian);
	create(&data);
	player(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img.img, 0, 0);
	mlx_hook(data.win, 17, 0, destroy, &data);
	mlx_loop(data.mlx);
	return 0;
}