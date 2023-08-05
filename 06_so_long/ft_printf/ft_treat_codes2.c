/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_codes2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:51:04 by arbutnar          #+#    #+#             */
/*   Updated: 2022/02/16 16:51:08 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_int_s(char *str)
{
	if (str == NULL)
		str = "(null)";
	return (ft_putstr(str));
}

int	ft_int_d_i(int num, char *base)
{
	int	len;
	int	mod;

	len = 1;
	mod = 1;
	ft_putnbr_base(num, base);
	if (num == -2147483648)
		len = 11;
	else
	{
		if (num < 0)
		{
			num *= -1;
			len++;
		}
		while (num / mod > 9)
		{
			mod *= 10;
			len++;
		}
	}
	return (len);
}

int	ft_int_hex(unsigned int num, char *base)
{
	int	len;
	int	mod;

	len = 1;
	mod = 1;
	while (num / mod > 15)
	{
		mod *= 16;
		len++;
	}
	ft_putnbr_base3(num, base);
	return (len);
}

int	ft_int_u(unsigned int num, char *base)
{
	int	len;
	int	mod;

	len = 1;
	mod = 1;
	while (num / mod > 9)
	{
		mod *= 10;
		len++;
	}
	ft_putnbr_base3(num, base);
	return (len);
}
