/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 10:50:49 by arbutnar          #+#    #+#             */
/*   Updated: 2022/05/17 19:23:59 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_hooks(int key, t_so_long *struttura)
{
	ft_findplayer(struttura);
	if (key == 53)
		ft_destroy(struttura);
	else if (key == 13)
		ft_move_up(struttura);
	else if (key == 1)
		ft_move_down(struttura);
	else if (key == 0)
		ft_move_left(struttura);
	else if (key == 2)
		ft_move_right(struttura);
	return (0);
}

int	ft_check_cemp(t_so_long *struttura)
{
	int	row;
	int	col;

	row = 0;
	while (row < struttura->height)
	{
		col = 0;
		while (col < struttura->width)
		{
			if (struttura->matrice[row][col] != '0' &&
				struttura->matrice[row][col] != '1' &&
				struttura->matrice[row][col] != 'C' &&
				struttura->matrice[row][col] != 'E' &&
				struttura->matrice[row][col] != 'M' &&
				struttura->matrice[row][col] != 'P')
				return (0);
			col++;
		}
		row++;
	}
	return (1);
}

int	ft_check_better(t_so_long *struttura)
{
	int	row;
	int	col;

	struttura->c = 0;
	struttura->e = 0;
	struttura->p = 0;
	row = 0;
	while (row < struttura->height)
	{
		col = 0;
		while (col < struttura->width)
		{
			if (struttura->matrice[row][col] == 'C')
				struttura->c++;
			else if (struttura->matrice[row][col] == 'E')
				struttura->e++;
			else if (struttura->matrice[row][col] == 'P')
				struttura->p++;
			col++;
		}
		row++;
	}
	if (struttura->c == 0 || struttura->p != 1 || struttura->e < 1)
		return (0);
	return (1);
}

int	ft_check_spirals(t_so_long *struttura)
{
	int	row;
	int	col;

	row = 0;
	while (row < struttura->height)
	{
		col = 0;
		while (col < struttura->width)
		{
			if (struttura->matrice[row][col] != '1' &&
			((row == 0 || row == struttura->height - 1 ||
			col == 0 || col == struttura->width - 1)))
				return (0);
			col++;
		}
		row++;
	}
	return (1);
}

int	ft_check_map(t_so_long *struttura)
{
	if (ft_check_cemp(struttura) == 0)
		return (0);
	if (ft_check_better(struttura) == 0)
		return (0);
	if (ft_check_spirals(struttura) == 0)
		return (0);
	return (1);
}
