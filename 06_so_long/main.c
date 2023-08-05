/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:57:50 by arbutnar          #+#    #+#             */
/*   Updated: 2022/05/18 15:44:22 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ber(char *fd)
{
	int	i;

	i = ft_strlen(fd);
	if (fd[i - 4] == '.' && fd[i - 3] == 'b'
		&& fd[i - 2] == 'e' && fd[i - 1] == 'r')
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_so_long	struttura;

	if (argc != 2)
		ft_printf("Arguments Error");
	else if (!check_ber(argv[1]))
		ft_printf ("Error\n");
	else
	{
		matrix(argv[1], &struttura);
		struttura.mlx_ptr = mlx_init();
		if (ft_check_map(&struttura) == 0)
			return (ft_error());
		struttura.win_ptr = mlx_new_window(struttura.mlx_ptr,
				struttura.width * 64, struttura.height * 64, "so_long");
		open_images(&struttura);
		struttura.frame = 0;
		struttura.frame_wall = 0;
		mlx_loop_hook(struttura.mlx_ptr, updates_img, &struttura);
		mlx_key_hook(struttura.win_ptr, ft_hooks, &struttura);
		mlx_hook(struttura.win_ptr, 17, 0, ft_destroy, 0);
		mlx_loop(struttura.mlx_ptr);
	}
	return (0);
}
