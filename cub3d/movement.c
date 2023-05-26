/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:32:51 by arbutnar          #+#    #+#             */
/*   Updated: 2023/05/26 13:43:04 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_on(int keycode, t_data *data)
{
	printf("ciao\n");
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
	return 0;
}

void	On_or_Off(t_data *data)
{
	if (data->w == 1)
		data->pc.y -= 1;
	if (data->a == 1)
		data->pc.x -= 1;
	if (data->s == 1)
		data->pc.y += 1;
	if (data->d == 1)
		data->pc.x += 1;
}
