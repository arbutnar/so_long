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

int	key_on(int keycode, t_data *data)
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

int	key_off(int keycode, t_data *data)
{
	if (keycode == ESC)
		exit (EXIT_SUCCESS);
	if (keycode == W)
		data->pc.y = 0;
	if (keycode == A)
		data->pc.x = 0;
	if (keycode == S)
		data->pc.y = 0;
	if (keycode == D)
		data->pc.x = 0;
	return 0;
}

int	destroy(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	free_data(data);
	exit (EXIT_SUCCESS);
	return (0);
}

int	loop_hook(t_data *data)
{
	
	data->img.img = mlx_new_image(data->mlx, data->width * 64, data->height * 64);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp,
								&data->img.ll, &data->img.endian);
	
	create_twoD(data);
	player_pos(data);
	fan_radius(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	mlx_destroy_image(data->mlx, data->img.img);
	return 0;
}

// void	On_or_Off(t_data *data)
// {
// 	mlx_put_image_to_window
// }

int main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		error_msg("Arg");
	data_init(&data);
	read_fd(argv[1], &data);
	check_map(&data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.width * 64, data.height * 64, "cub3d");	
	mlx_hook(data->win, 2, 0, key_on, &data);
	mlx_hook(data->win, 3, 0, key_off, &data);
	mlx_loop_hook(data.mlx, loop_hook, &data);
	mlx_hook(data.win, 17, 0, destroy, &data);
	mlx_loop(data.mlx);
	return 0;
}