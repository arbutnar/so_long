/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:23:06 by arbutnar          #+#    #+#             */
<<<<<<< HEAD:cub3d/parsing.c
/*   Updated: 2023/06/08 16:53:12 by arbutnar         ###   ########.fr       */
=======
/*   Updated: 2023/06/05 13:53:17 by arbutnar         ###   ########.fr       */
>>>>>>> ba82e7a5f7a928ba39c18ecf43c7797c76efe1aa:parsing.c
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

<<<<<<< HEAD:cub3d/parsing.c
=======
void	map_size_init(t_data *data)
{
	int	tmp_h;
	int	tmp_w;
	int	y;
	int	x;

	tmp_h = 0;
	while (data->map[tmp_h] != NULL)
	{
		tmp_w = 0;
		while (data->map[y][tmp_w] != '\0')
		{
			if (x < tmp_w)
				x = tmp_w;
			tmp_w++;
		}
		if (y < tmp_h)
			y = tmp_h;
		tmp_h++;
	}
	data->map_h = y + 1;
	data->map_w = x;
}

>>>>>>> ba82e7a5f7a928ba39c18ecf43c7797c76efe1aa:parsing.c
char	*fill_paths(char *str, char *path)
{
	char	**mtx;

	if (path != NULL)
		error_msg("Invalid path");
	mtx = ft_split(str, ' ');
	if (mtx[2])
		error_msg("Invalid path");
	path = ft_strdup(mtx[1]);
	path[ft_strlen(path) - 1] = '\0';
	ft_free_matrix(mtx);
	if (open(path, O_RDONLY) == -1)
		error_msg("Invalid path");
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

<<<<<<< HEAD:cub3d/parsing.c
int	r_fd(t_data *data, char *str, int fd, int i)
=======
// more than 25
void	read_fd(char *filename, t_data *data)
>>>>>>> ba82e7a5f7a928ba39c18ecf43c7797c76efe1aa:parsing.c
{
	while (str != NULL)
	{
		if (!ft_strncmp(str, "NO", 2))
			data->no = fill_paths(str, data->no);
		else if (!ft_strncmp(str, "SO", 2))
			data->so = fill_paths(str, data->so);
		else if (!ft_strncmp(str, "WE", 2))
			data->we = fill_paths(str, data->we);
		else if (!ft_strncmp(str, "EA", 2))
			data->ea = fill_paths(str, data->ea);
		else if (!ft_strncmp(str, "DO", 2))
			data->door = fill_paths(str, data->door);
		else if (!ft_strncmp(str, "F", 1))
			fill_rgb(str, &data->f);
		else if (!ft_strncmp(str, "C", 1))
			fill_rgb(str, &data->c);
		else if (str[0] != '\n')
		{
			data->map[i] = ft_strdup(str);
			i++;
		}
		free(str);
		str = get_next_line(fd);
	}
	return (i);
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
	// data->map = (char **)malloc(sizeof(char *) * i + 1); vecchio
	data->map = ft_calloc(i + 1, sizeof(char *)); // nuovo
	i = r_fd(data, str, fd, 0);
	data->map[i] = NULL;
<<<<<<< HEAD:cub3d/parsing.c
=======
	map_size_init(data);
>>>>>>> ba82e7a5f7a928ba39c18ecf43c7797c76efe1aa:parsing.c
	check_map(data);
	close(fd);
}
