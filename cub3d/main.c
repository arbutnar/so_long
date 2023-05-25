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

int	loop_hook(t_data *data)
{
	data->img.img = mlx_new_image(data->mlx, data->width * 64, data->height * 64);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp,
								&data->img.ll, &data->img.endian);
	create(data);
	player(data);
	find_radius(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	mlx_destroy_image(data->mlx, data->img.img);
	return 0;
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == ESC)
		exit (EXIT_SUCCESS);
	if (keycode == W)
		data->pc.y -= 1;
	if (keycode == A)
		data->pc.x -= 1;
	if (keycode == S)
		data->pc.y += 1;
	if (keycode == D)
		data->pc.x += 1;
	return 0;
}

int main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		error_msg("Arg");
	data_init(&data);
	read_fd(argv[1], &data);
	check_map(&data);
		// printf("%s", data.NO);
		// printf("%s", data.SO);
		// printf("%s", data.WE);
		// printf("%s", data.EA);
		// printf("%d\n", data.F);
		// printf("%d\n", data.C);
		// print_matrix(data.map);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.width * 64, data.height * 64, "cub3d");	
	mlx_key_hook(data.win, key_hook, &data);
	mlx_loop_hook(data.mlx, loop_hook, &data);
	mlx_hook(data.win, 17, 0, destroy, &data);
	mlx_loop(data.mlx);
	return 0;
}