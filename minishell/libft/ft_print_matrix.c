/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:13:45 by arbutnar          #+#    #+#             */
/*   Updated: 2023/03/22 23:13:48 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_matrix(char **mtx)
{
	int	i;

	i = 0;
	if (mtx)
	{
		while (mtx[i])
		{
			ft_printf("element[%d]: %s\n", i, mtx[i]);
			i++;
		}
	}
}
