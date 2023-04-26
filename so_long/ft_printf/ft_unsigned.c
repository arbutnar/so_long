/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:44:53 by arbutnar          #+#    #+#             */
/*   Updated: 2022/02/16 16:54:16 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_hex_long_itoa(size_t n, const char *base)
{
	int			len;
	char		*str;

	len = ft_itoa_len2(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	str[len] = 0;
	len -= 1;
	if (n == 0)
	{
		str[0] = 48;
		return (str);
	}
	while (n)
	{
		str[len] = base[n % 16];
		n /= 16;
		len--;
	}
	return (str);
}

int	ft_itoa_len2(size_t n)
{
	int		len;
	size_t	tmp;

	len = 0;
	tmp = n;
	if (n == 0)
		len = 1;
	else
	{
		while (tmp)
		{
			tmp /= 16;
			len++;
		}
	}
	return (len);
}

int	ft_int_p(size_t num, char *base)
{
	int		len;
	char	*s;

	s = ft_hex_long_itoa(num, base);
	write(1, "0x", 2);
	len = ft_putstr(s);
	free(s);
	return (len + 2);
}
