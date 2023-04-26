/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:13:56 by arbutnar          #+#    #+#             */
/*   Updated: 2022/02/16 16:51:30 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_conversions(char c, va_list args)
{
	int	len;

	len = 0;
	if (c == '%')
		len += ft_putchar('%');
	else if (c == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (c == 's')
		len += ft_int_s(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		len += ft_int_d_i(va_arg(args, int), "0123456789");
	else if (c == 'x')
		len += ft_int_hex(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		len += ft_int_hex(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (c == 'p')
		len += ft_int_p(va_arg(args, size_t), "0123456789abcdef");
	else if (c == 'u')
		len += ft_int_u(va_arg(args, unsigned int), "0123456789");
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	int		i;

	va_start(args, str);
	len = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			len += ft_conversions(str[i + 1], args);
			i++;
		}
		else
			len += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}

/*int	main(void)
{
	int		len;
	int		len2;

	len = ft_printf("%d", 00);
	printf("\n%d\n", len);
	len2 = printf("%d", 30544);
	printf("\n%d\n", len2);
}*/

// int	main(void)
// {	
// 	ft_printf(" %p %p \n", LONG_MIN, 2147483647);
// 	printf(" %p %p \n", LONG_MIN, 2147483647);
// }
