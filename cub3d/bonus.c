/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:50:39 by arbutnar          #+#    #+#             */
/*   Updated: 2023/06/05 13:58:33 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	door_north_star(t_data *data, float angle, float distance, int i)
{
	float	c;
	float	s;
	float	p_x;
	float	p_y;

	distance -= 0.01;
	c = cos(angle * RAD);
	s = sin(angle * RAD);
	p_y = data->pc.y + s * distance;
	p_x = data->pc.x + c * distance;
	if (data->map[(int)(p_y - 0.01)][(int)p_x] == 'D')
		data->orien[i] = 4;
	else if (data->map[(int)(p_y + 0.01)][(int)p_x] == 'D')
		data->orien[i] = 5;
	else if (data->map[(int)p_y][(int)(p_x - 0.01)] == 'D')
		data->orien[i] = 6;
	else
		data->orien[i] = 7;
}

// void	remove_d(t_data *data)
// {
// 	int	row;
// 	int	col;

// 	row = 0;
// 	while (row < data->map_h)
// 	{
// 		col = 0;
// 		while ()
// 		row++
// 	}
// }