/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dirty.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:17:40 by arbutnar          #+#    #+#             */
/*   Updated: 2023/03/22 23:17:41 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./global.h"
#include "./glob.h"
#include "./executor.h"

void	do_dirty3(char *str, char new_str[], int *i, int *j)
{
	new_str[(*j)++] = ' ';
	new_str[*j] = str[*i];
	if (str[*i + 1] == str[*i])
	{
		new_str[++(*j)] = str[*i + 1];
		(*i)++;
	}
	new_str[++(*j)] = ' ';
}
