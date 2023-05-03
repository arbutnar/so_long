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

void	read_fd(char *filename, t_data *data)
{
	char	*str;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_msg("File");
	str = get_next_line(fd);
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
			data->F = fill_rgb(str, "F ");
		else if (!ft_strncmp(str, "C", 1))
			data->C = fill_rgb(str, "C ");
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
}

int main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		error_msg("Arg");
	data_init(&data);
	read_fd(argv[1], &data);
	printf("%s", data.NO);
	printf("%s", data.SO);
	printf("%s", data.WE);
	printf("%s", data.EA);
	printf("%d\n", data.F);
	printf("%d\n", data.C);
	// print_matrix(data.map);
	return 0;
}