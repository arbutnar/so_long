/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:02:56 by arbutnar          #+#    #+#             */
/*   Updated: 2022/05/17 19:23:59 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_images2(t_so_long *struttura)
{
	int	width;
	int	height;

	struttura->img.exit2 = mlx_xpm_file_to_image \
			(struttura->mlx_ptr, "sprites/exit_2.xpm", &width, &height);
	struttura->img.enemy1 = mlx_xpm_file_to_image \
			(struttura->mlx_ptr, "sprites/dog_idle_1.xpm", &width, &height);
	struttura->img.enemy2 = mlx_xpm_file_to_image \
			(struttura->mlx_ptr, "sprites/dog_idle_2.xpm", &width, &height);
	struttura->img.wall1 = mlx_xpm_file_to_image \
			(struttura->mlx_ptr, "sprites/spiral_1.xpm", &width, &height);
	struttura->img.wall2 = mlx_xpm_file_to_image \
			(struttura->mlx_ptr, "sprites/spiral_2.xpm", &width, &height);
	struttura->img.wall3 = mlx_xpm_file_to_image \
			(struttura->mlx_ptr, "sprites/spiral_3.xpm", &width, &height);
	struttura->white = mlx_xpm_file_to_image \
			(struttura->mlx_ptr, "sprites/white.xpm", &width, &height);
}

void	open_images(t_so_long *struttura)
{
	int	width;
	int	height;

	struttura->img.personaggino1 = mlx_xpm_file_to_image \
			(struttura->mlx_ptr, "sprites/Matteo_0.xpm", &width, &height);
	struttura->img.personaggino2 = mlx_xpm_file_to_image \
			(struttura->mlx_ptr, "sprites/Matteo_1.xpm", &width, &height);
	struttura->img.object1 = mlx_xpm_file_to_image \
			(struttura->mlx_ptr, "sprites/cig_0.xpm", &width, &height);
	struttura->img.object2 = mlx_xpm_file_to_image \
			(struttura->mlx_ptr, "sprites/cig_1.xpm", &width, &height);
	struttura->img.object3 = mlx_xpm_file_to_image \
			(struttura->mlx_ptr, "sprites/cig_2.xpm", &width, &height);
	struttura->img.object4 = mlx_xpm_file_to_image \
			(struttura->mlx_ptr, "sprites/cig_3.xpm", &width, &height);
	struttura->pavimento = mlx_xpm_file_to_image \
			(struttura->mlx_ptr, "sprites/floor.xpm", &width, &height);
	struttura->img.exit1 = mlx_xpm_file_to_image \
			(struttura->mlx_ptr, "sprites/exit_1.xpm", &width, &height);
	open_images2(struttura);
}
