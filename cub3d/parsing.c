/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:23:06 by arbutnar          #+#    #+#             */
/*   Updated: 2023/05/25 13:39:33 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	data_init(t_data *data)
{
	data->NO = NULL;
	data->SO = NULL;
	data->WE = NULL;
	data->EA = NULL;
	data->F = 0;
	data->C = 0;
}

char	*fill_paths(char *str, char *path)
{
	char	**mtx;

	if (path != NULL)
		error_msg("Invalid path");
	mtx = ft_split(str , ' ');
	if (mtx[2])
		error_msg("Invalid path");
	path = ft_strdup(mtx[1]);
	ft_free_matrix(mtx);
	return (path);
}

void	fill_rgb(char *str, int *rgb)
{
	char	**space;
	char	**comma;
	int		r;
	int		g;
	int		b;

	if (*rgb != 0)
		error_msg("Invalid rgb");
	space = ft_split(str, ' ');
	if (space[2])
		error_msg("Invalid rgb");
	comma = ft_split(space[1], ',');
	if (comma[3])
		error_msg("Invalid rgb");
	r = ft_atoi(comma[0]);
	g = ft_atoi(comma[1]);
	b = ft_atoi(comma[2]);
	*rgb = 65536 * r + 256 * g + b;
	ft_free_matrix(space);
	ft_free_matrix(comma);
}

void	read_fd(char *filename, t_data *data)
{
	char	*str;
	int		fd;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_msg("File");
	str = get_next_line(fd);
	i = fd_len(filename);
	data->map = (char **)malloc(sizeof(char *) * i + 1);
	i = 0;
	while (str != NULL)
	{
		if (!ft_strncmp(str, "NO", 2))
			data->NO = fill_paths(str, data->NO);
		else if (!ft_strncmp(str, "SO", 2))
			data->SO = fill_paths(str, data->SO);
		else if (!ft_strncmp(str, "WE", 2))
			data->WE = fill_paths(str, data->WE);
		else if (!ft_strncmp(str, "EA", 2))
			data->EA = fill_paths(str, data->EA);
		else if (!ft_strncmp(str, "F", 1))
			fill_rgb(str, &data->F);
		else if (!ft_strncmp(str, "C", 1))
			fill_rgb(str, &data->C);
		else if (str[0] != '\n')
		{
			data->map[i] = ft_strdup(str);
			i++;
		}
		free(str);
		str = get_next_line(fd);
	}
	data->map[i] = NULL;
	map_size_init(data);
	close(fd);
}
