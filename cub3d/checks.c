/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:39:43 by arbutnar          #+#    #+#             */
/*   Updated: 2023/06/05 11:47:34 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	orien(t_data *data, char c)
{
	if (c == 'N')
		data->pc.pov = 270;
	else if (c == 'S')
		data->pc.pov = 90;
	else if (c == 'E')
		data->pc.pov = 0;
	else if (c == 'W')
		data->pc.pov = 180;
}

void	check_surroundings(char **map, int row, int col)
{
<<<<<<< HEAD:cub3d/checks.c
	if (row - 1 < 0 || col - 1 < 0
		|| map[row + 1] == NULL || map[row][col + 1] == '\n')
=======
	if (row - 1 < 0 || col - 1 < 0 || map[row + 1] == NULL || map[row][col + 1] == '\n')
>>>>>>> ba82e7a5f7a928ba39c18ecf43c7797c76efe1aa:checks.c
		error_msg("Invalid map");
	if (map[row - 1][col] == ' ' || map[row - 1][col] == '\0')
		error_msg("Invalid map");
	if (map[row + 1][col] == ' ' || map[row + 1][col] == '\0')
		error_msg("Invalid map");
	if (map[row][col - 1] == ' ' || map[row][col - 1] == '\0')
		error_msg("Invalid map");
	if (map[row][col + 1] == ' ' || map[row][col + 1] == '\0')
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

<<<<<<< HEAD:cub3d/checks.c
int	c_map(t_data *data, int player, int row)
=======
// more than 25
void	check_map(t_data *data)
>>>>>>> ba82e7a5f7a928ba39c18ecf43c7797c76efe1aa:checks.c
{
	int		col;
	char	c;

	col = 0;
	while (data->map[row][col] != '\n')
	{
		c = data->map[row][col];
		if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		{
			orien(data, c);
			data->pc.y = row + 0.5;
			data->pc.x = col + 0.5;
			player++;
		}
		if (c == '0' || c == 'N' || c == 'S'
			|| c == 'E' || c == 'W' || c == 'D')
			check_surroundings(data->map, row, col);
		else if (c != '1' && c != ' ')
			error_msg("Invalid map");
		col++;
	}
	return (player);
}

// more than 25
void	check_map(t_data *data)
{
	int		row;
	int		player;

	player = 0;
	row = 0;
	while (data->map[row] != NULL)
	{
<<<<<<< HEAD:cub3d/checks.c
		player = c_map(data, player, row);
=======
		col = 0;
		while (data->map[row][col] != '\n')
		{
			c = data->map[row][col];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				orien(data, c);
				data->pc.y = row + 0.5;
				data->pc.x = col + 0.5;
				player++;
			}
			if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == 'D')
				check_surroundings(data->map, row, col);
			else if (c != '1' && c != ' ')
				error_msg("Invalid map");
			col++;
		}
>>>>>>> ba82e7a5f7a928ba39c18ecf43c7797c76efe1aa:checks.c
		row++;
	}
	if (player != 1)
		error_msg("Invalid map");
}
