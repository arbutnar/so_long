/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_t.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:25:40 by arbutnar          #+#    #+#             */
/*   Updated: 2023/03/22 23:25:42 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../ft_printf.h"

void	print_t(t_pflags *tf)
{	
	char	*code;

	code = INF;
	if (tf->length != 0)
		tf->dimension--;
	if (tf->length == 1)
		code = ERR;
	else if (tf->length == 2)
		code = SIG;
	else if (tf->length == 3)
		code = WAR;
	write(1, code, pf_strlen(code));
	tf->dimension += pf_strlen(code);
}
