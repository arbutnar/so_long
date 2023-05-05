/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:23:13 by arbutnar          #+#    #+#             */
/*   Updated: 2023/05/03 15:23:13 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		error_msg("Arg");
	data_init(&data);
	read_fd(argv[1], &data);
	printf("%s", data.NO);
	printf("%s", data.SO);
	printf("%s", data.WE);
	printf("%s", data.EA);
	printf("%d\n", data.F);
	printf("%d\n", data.C);
	// print_matrix(data.map);
	free_data(&data);
	return 0;
}