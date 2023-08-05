/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:42:11 by arbutnar          #+#    #+#             */
/*   Updated: 2022/05/17 19:24:00 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(void)
{
	ft_printf("Error\n");
	exit(1);
	return (0);
}

void	*ft_memset(void *b, int c, size_t len)
{
	char	*str;

	str = b;
	while (len)
	{
		*str = (char)c;
		str++;
		len--;
	}
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(size * count);
	if (!ptr)
	{
		return (0);
	}
	ft_memset(ptr, 0, (count * size));
	return (ptr);
}

static int	ft_count(long int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	if (n == 0)
		i++;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			c;
	long int	n2;

	n2 = n;
	c = ft_count(n2);
	str = ft_calloc(c + 1, sizeof(char));
	if (!str)
		return (0);
	if (n2 == 0)
		str[0] = '0';
	if (n2 < 0)
	{
		str[0] = '-';
		n2 *= -1;
	}
	while (n2 > 0)
	{
		str[c - 1] = (n2 % 10) + '0';
		n2 = n2 / 10;
		c--;
	}
	return (str);
}
