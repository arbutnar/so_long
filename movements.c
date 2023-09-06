/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 00:40:33 by arbutnar          #+#    #+#             */
/*   Updated: 2022/05/18 15:46:59 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_destroy(t_so_long *struttura)
{
	exit(1);
	return (0);
}

void	ft_move_up(t_so_long *struttura)
{
	int	x;
	int	y;

	x = struttura->player_pos.x;
	y = struttura->player_pos.y;
	if (struttura->matrice[y - 1][x] != '1' &&
		(struttura->matrice[y - 1][x] != 'E' || struttura->c == 0))
	{
		ft_movenemy(struttura);
		if (struttura->matrice[y - 1][x] == 'M' ||
			struttura->matrice[y - 1][x] == 'E')
			ft_destroy(struttura);
		if (struttura->matrice[y - 1][x] == 'C')
			struttura->c--;
		struttura->matrice[y - 1][x] = 'P';
		struttura->matrice[y][x] = '0';
		struttura->moves++;
		ft_printf ("Mosse: %d\n", struttura->moves);
	}
}

void	ft_move_down(t_so_long *struttura)
{
	int	x;
	int	y;

	x = struttura->player_pos.x;
	y = struttura->player_pos.y;
	if (struttura->matrice[y + 1][x] != '1' &&
		(struttura->matrice[y + 1][x] != 'E' || struttura->c == 0))
	{
		ft_movenemy(struttura);
		if (struttura->matrice[y + 1][x] == 'M' ||
			struttura->matrice[y + 1][x] == 'E')
			ft_destroy(struttura);
		if (struttura->matrice[y + 1][x] == 'C')
			struttura->c--;
		struttura->matrice[y + 1][x] = 'P';
		struttura->matrice[y][x] = '0';
		struttura->moves++;
		ft_printf ("Mosse: %d\n", struttura->moves);
	}
}

void	ft_move_left(t_so_long *struttura)
{
	int	x;
	int	y;

	x = struttura->player_pos.x;
	y = struttura->player_pos.y;
	if (struttura->matrice[y][x - 1] != '1' &&
		(struttura->matrice[y][x - 1] != 'E' || struttura->c == 0))
	{
		ft_movenemy(struttura);
		if (struttura->matrice[y][x - 1] == 'M' ||
			struttura->matrice[y][x - 1] == 'E')
			ft_destroy(struttura);
		if (struttura->matrice[y][x - 1] == 'C')
			struttura->c--;
		struttura->matrice[y][x - 1] = 'P';
		struttura->matrice[y][x] = '0';
		struttura->moves++;
		ft_printf ("Mosse: %d\n", struttura->moves);
	}
}

void	ft_move_right(t_so_long *struttura)
{
	int	x;
	int	y;

	x = struttura->player_pos.x;
	y = struttura->player_pos.y;
	if (struttura->matrice[y][x + 1] != '1' &&
		(struttura->matrice[y][x + 1] != 'E' || struttura->c == 0))
	{
		ft_movenemy(struttura);
		if (struttura->matrice[y][x + 1] == 'M' ||
			struttura->matrice[y][x + 1] == 'E')
			ft_destroy(struttura);
		if (struttura->matrice[y][x + 1] == 'C')
			struttura->c--;
		struttura->matrice[y][x + 1] = 'P';
		struttura->matrice[y][x] = '0';
		struttura->moves++;
		ft_printf ("Mosse: %d\n", struttura->moves);
	}
}
