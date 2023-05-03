/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:23:06 by arbutnar          #+#    #+#             */
/*   Updated: 2023/05/03 16:51:32 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	data_init(t_data *data)
{
	data->NO = NULL;
	data->SO = NULL;
	data->WE = NULL;
	data->EA = NULL;
	data->F = 0;
	data->C = 0;
}

char	*fill_paths(char *str, char *attribute)
{
	char	**mtx;

	mtx = ft_split(str , ' ');
	if (mtx[2])
		error_msg("Invalid path");
	if (attribute == NULL)
		attribute = mtx[1];
	else
		error_msg("Invalid path");
	return (attribute);
}

int	fill_rgb(char *str, char *attribute)
{
	char	**mtx;
	int		rgb;
	int		r;
	int		g;
	int		b;

	str = ft_strtrim(str, attribute);
	mtx = ft_split(str, ',');
	if (mtx[3])
		error_msg("Invalid rgb");
	r = ft_atoi(mtx[0]);
	g = ft_atoi(mtx[1]);
	b = ft_atoi(mtx[2]);
	rgb = 65536 * r + 256 * g + b;
	return (rgb);
}

/* potrei fare un array formato da spazi, trattini, punti, 
virgole: deferenziando e scorrendo quetso array mi trovo i caratteri validi per lo split 
A quel punto lo spazio dopo l'attributo (per quanto riguarda i colori) non sarebbe
piú d'ostacolo per creare una matrice e sfruttarla come faccio in fill path.
Da lí continuo come ora convertendo e ritornando un intero */

/* scrivere split */