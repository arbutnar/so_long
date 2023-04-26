/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:48:54 by arbutnar          #+#    #+#             */
/*   Updated: 2022/05/18 15:41:54 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_riempilamatrice(t_so_long *struttura, char *filename)
{
	int		fd;
	char	*str;
	int		z;

	fd = open(filename, O_RDONLY);
	str = get_next_line(fd);
	z = 0;
	while (str != NULL)
	{
		count_maps(str, z, struttura);
		free(str);
		str = get_next_line(fd);
		z++;
	}
	free(str);
	close (fd);
}

void	ft_print_it(char **matrice)
{
	int	i;

	i = 0;
	while (matrice[i] != NULL)
	{
		ft_printf("%s\n", matrice[i]);
		i++;
	}
}

void	get_enemies(t_so_long *struttura, char **matrice)
{
	int	i;
	int	j;
	int	x;

	struttura->enemy_pos = (t_vec *)malloc
		(sizeof(t_vec) * struttura->count_enemy);
	x = 0;
	i = 0;
	while (i < struttura->height)
	{
		j = 0;
		while (j < struttura->width)
		{
			if (matrice[i][j] == 'M')
			{
				struttura->enemy_pos[x].x = j;
				struttura->enemy_pos[x].y = i;
				struttura->enemy_pos[x].moves = 0;
				x++;
			}
			j++;
		}
		i++;
	}
}

void	matrix2(t_so_long *struttura, char *filename, int height, int width)
{
	int	row;

	row = 0;
	while (row < height)
	{
		struttura->matrice[row] = (char *)malloc (sizeof(char) * width + 1);
		row++;
	}
	struttura->c = 0;
	struttura->count_enemy = 0;
	ft_riempilamatrice(struttura, filename);
	struttura->height = height;
	struttura->width = width;
	struttura->moves = 0;
	get_enemies(struttura, struttura->matrice);
}

void	matrix(char *filename, t_so_long *struttura)
{
	int		height;
	int		width;
	int		fd;
	int		row;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		exit (1);
	height = ft_height(fd);
	close(fd);
	fd = open(filename, O_RDONLY);
	width = ft_width(fd);
	close(fd);
	struttura->matrice = (char **)malloc (sizeof(char *) * height + 1);
	struttura->matrice[height] = NULL;
	matrix2(struttura, filename, height, width);
}
