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
	data->img.img = mlx_new_image(data->mlx, SCR_WIDTH, SCR_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp,
			&data->img.ll, &data->img.endian);
	movements(data);
	fill_screen(data);
	create_minimap(data);
	player_pos(data);
	fan_radius(data);
	assign_orien(data);
<<<<<<< HEAD:cub3d/main.c
	update_hand(data);
=======
>>>>>>> ba82e7a5f7a928ba39c18ecf43c7797c76efe1aa:main.c
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	mlx_destroy_image(data->mlx, data->img.img);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		error_msg("Arg");
	data_init(&data);
	read_fd(argv[1], &data);
	data.mlx = mlx_init();
	open_textures(&data);
<<<<<<< HEAD:cub3d/main.c
	open_hand(&data);
	data.win = mlx_new_window(data.mlx, SCR_WIDTH, SCR_HEIGHT, "cub3d");
	mlx_mouse_hide(data.mlx, data.win);
=======
	data.win = mlx_new_window(data.mlx, SCR_WIDTH, SCR_HEIGHT, "cub3d");
>>>>>>> ba82e7a5f7a928ba39c18ecf43c7797c76efe1aa:main.c
	mlx_hook(data.win, 2, (1L << 0), key_on, &data);
	mlx_hook(data.win, 3, (1L << 1), key_off, &data);
	mlx_loop_hook(data.mlx, loop_hook, &data);
	mlx_hook(data.win, 17, 0, destroy, &data);
	mlx_loop(data.mlx);
	return (0);
}
