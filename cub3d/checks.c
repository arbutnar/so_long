/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:39:43 by arbutnar          #+#    #+#             */
/*   Updated: 2023/05/19 18:01:21 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_surroundings(char **map, int row, int col)
{
	if (map[row - 1][col] == ' ' || map[row - 1][col] == '\0')
		error_msg("Invalid map");
	if (map[row + 1][col] == ' ' || map[row + 1][col] == '\0')
		error_msg("Invalid map");
	if (map[row][col - 1] == ' ' || map[row][col - 1] == '\0')
		error_msg("Invalid map");
	if (map[row][col - 1] == ' ' || map[row][col + 1] == '\0')
		error_msg("Invalid map");
	if (map[row - 1][col - 1] == ' ' || map[row - 1][col - 1] == '\0')
		error_msg("Invalid map");
	if (map[row + 1][col + 1] == ' ' || map[row + 1][col + 1] == '\0')
		error_msg("Invalid map");
	if (map[row - 1][col + 1] == ' ' || map[row - 1][col + 1] == '\0')
		error_msg("Invalid map");
	if (map[row + 1][col - 1] == ' ' || map[row + 1][col - 1] == '\0')
		error_msg("Invalid map");
}

void    check_map(t_data *data)
{
	int		row;
	int		col;
	char	c;
	int		p;

	data->p_coords = (float *)malloc(sizeof(float) * 2);
	p = 0;
	row = 0;
	while (data->map[row] != NULL)
	{
		col = 0;
		while (data->map[row][col] != '\n')
		{
			c = data->map[row][col];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				data->p_coords[0] = row + 0.5;
				data->p_coords[1] = col + 0.5;
				p++;
			}
			if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
				check_surroundings(data->map, row, col);
			else if (c != '1' && c != ' ')
				error_msg("Invalid map");
			col++;
		}
		row++;
	}
	if (p != 1)
		error_msg("Invalid map");
}
