/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:26:37 by arbutnar          #+#    #+#             */
/*   Updated: 2023/04/26 19:26:52 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_fd(char *name)
{
	int		fd;
	
	fd = open(name, O_RDONLY);
	if (fd == -1)
		error_msg("Fd");
	return (fd);
}

void	data_init(char *name, t_data *data)
{
	char	*str;
	int		fd;
	
	fd = check_fd(name);
	str = get_next_line(fd);
	while (str != NULL)
	{
		if (str[0] != '\0')
		{
			if (ft_strncmp(str, "NO", 2))
				data->NO = str;
			if (ft_strncmp(str, "SO", 2))
				data->SO = str;
			if (ft_strncmp(str, "WE", 2))
				data->WE = str;
			if (ft_strncmp(str, "EA", 2))
				data->EA = str;
			if (ft_strncmp(str, "F", 1))
				data->F = str;
			if (ft_strncmp(str, "C", 1))
				data->C = str;
		}
		str = get_next_line(fd);
	}
}

int main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		error_msg("Arg");
	data_init(argv[1], &data);
	printf("%s\n", data.NO);
	printf("%s\n", data.SO);
	printf("%s\n", data.WE);
	printf("%s\n", data.EA);
	printf("%s\n", data.F);
	printf("%s\n", data.C);
	return 0;
}