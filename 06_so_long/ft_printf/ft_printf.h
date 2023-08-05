/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 02:23:45 by arbutnar          #+#    #+#             */
/*   Updated: 2022/02/16 16:51:38 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

int		ft_printf(const char *str, ...);
int		ft_conversions(char c, va_list args);
int		ft_putchar(char c);
int		ft_putstr(char *str);
void	ft_strprint(unsigned int n, char *base, unsigned int size);
void	ft_putnbr_base(int nbr, char *base);
void	ft_putnbr_base2(int nbr, char *base);
void	ft_putnbr_base3(unsigned int nbr, char *base);
int		ft_int_s(char *str);
int		ft_int_d_i(int num, char *base);
int		ft_int_hex(unsigned int num, char *base);
int		ft_int_u(unsigned int num, char *base);
int		ft_int_p(size_t num, char *base);
int		ft_itoa_len2(size_t n);
char	*ft_hex_long_itoa(size_t n, const char *base);

#endif