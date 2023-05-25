/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:17:47 by arbutnar          #+#    #+#             */
/*   Updated: 2023/05/05 15:23:06 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_matrix(char **mtx)
{
	int	i;

	i = 0;
	while (mtx[i] != NULL)
	{
		if (mtx[i])
			free(mtx[i]);
		i++;
	}
	free(mtx);
}