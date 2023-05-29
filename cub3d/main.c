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
	On_or_Off(data);
	create_twoD(data);
	player_pos(data);
	fan_radius(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	mlx_destroy_image(data->mlx, data->img.img);
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
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.width * 64, data.height * 64, "cub3d");
	mlx_do_key_autorepeaton(data.mlx);
	mlx_hook(data.win, 2, 0L, key_on, &data);
	mlx_hook(data.win, 3, 0L, key_off, &data);
	mlx_loop_hook(data.mlx, loop_hook, &data);
	mlx_hook(data.win, 17, 0, destroy, &data);
	mlx_loop(data.mlx);
	return 0;
}