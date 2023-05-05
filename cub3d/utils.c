/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:23:19 by arbutnar          #+#    #+#             */
/*   Updated: 2023/05/03 15:23:19 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_msg(char *str)
{
	printf("%s Error\n", str);
	exit(1);
}

int	fd_len(char *filename)
{
	int		len;
	char	*str;
	int		fd;

	fd = open(filename, O_RDONLY);
	str = get_next_line(fd);
	len = 0;
	while (str != NULL)
	{
		if (str[0] != '\n')
			len++;
		free(str);
		str = get_next_line(fd);
	}
	close (fd);
	return (len);
}

void	print_matrix(char **mtx)
{
	int	i;

	i = 0;
	while (mtx[i] != NULL)
	{
		printf("%s", mtx[i]);
		i++;
	}
}

void	free_data(t_data *data)
{
	free(data->NO);
	free(data->SO);
	free(data->WE);
	free(data->EA);
}
