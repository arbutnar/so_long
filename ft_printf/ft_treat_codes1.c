/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_codes1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:36:38 by arbutnar          #+#    #+#             */
/*   Updated: 2022/02/16 16:23:54 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_strprint(unsigned int n, char *base, unsigned int size)
{
	if (n > size - 1)
	{
		ft_strprint(n / size, base, size);
		n %= size;
	}
	ft_putchar(base[n]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	n;

	n = 0;
	while (base[n])
		n++;
	if (nbr < 0)
	{
		ft_putchar('-');
		ft_strprint(-nbr, base, n);
	}
	else
		ft_strprint(nbr, base, n);
}

void	ft_putnbr_base2(int nbr, char *base)
{
	int	n;

	n = 0;
	while (base[n])
		n++;
	if (nbr > n - 1)
	{
		ft_putnbr_base2(nbr / n, base);
		nbr %= n;
	}
	ft_putchar(base[nbr]);
}

void	ft_putnbr_base3(unsigned int nbr, char *base)
{
	int	n;

	n = 0;
	while (base[n])
		n++;
	if (nbr < 0)
	{
		ft_putchar('-');
		ft_strprint(-nbr, base, n);
	}
	else
		ft_strprint(nbr, base, n);
}
