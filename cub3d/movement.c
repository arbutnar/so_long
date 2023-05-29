/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:32:51 by arbutnar          #+#    #+#             */
/*   Updated: 2023/05/26 17:13:45 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_on(int keycode, t_data *data)
{
	if (keycode == ESC)
		exit (EXIT_SUCCESS);
	if (keycode == W)
		data->w = 1;
	if (keycode == A)
		data->a = 1;
	if (keycode == S)
		data->s = 1;
	if (keycode == D)
		data->d = 1;
	if (keycode == LEFT)
		data->lf = 1;
	if (keycode == RIGHT)
		data->rg = 1;
	return 0;
}

int	key_off(int keycode, t_data *data)
{
	if (keycode == ESC)
		exit (EXIT_SUCCESS);
	if (keycode == W)
		data->w = 0;
	if (keycode == A)
		data->a = 0;
	if (keycode == S)
		data->s = 0;
	if (keycode == D)
		data->d = 0;
	if (keycode == LEFT)
		data->lf = 0;
	if (keycode == RIGHT)
		data->rg = 0;
	return 0;
}

void	assign_movement(t_data *data, float angle)
{
	float	new_x;
	float	new_y;

	new_x = data->pc.x + cos(angle) * SPEED;
	new_y = data->pc.y + sin(angle) * SPEED;
	if (data->map[(int)new_y][(int)new_x] != '1') 
	{
		data->pc.x = new_x;
		data->pc.y = new_y;
	}
}

void	On_or_Off(t_data *data)
{
	if (data->w == 1)
		assign_movement(data, data->pc.pov * RAD);
	if (data->a == 1)
		assign_movement(data, (data->pc.pov - 90) * RAD);
	if (data->s == 1)
		assign_movement(data, (data->pc.pov - 180) * RAD);
	if (data->d == 1)
		assign_movement(data, (data->pc.pov + 90) * RAD);
	if (data->lf == 1)
		data->pc.pov -= SENSIBILITY;
	if (data->rg == 1)
		data->pc.pov += SENSIBILITY;
	
}
