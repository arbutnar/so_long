/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:45:28 by arbutnar          #+#    #+#             */
/*   Updated: 2023/03/09 14:11:33 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	ft_check_argv(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_must_eat(int argc, char *argv[], t_rules *rules)
{
	if (argc == 6)
	{
		rules->must_eat = ft_atoi(argv[5]);
		if (rules->must_eat <= 0)
			return (ft_error("Args"));
	}
	else
		rules->must_eat = -1;
	return (0);
}

int	ft_error(char *str)
{
	printf("Error %s\n", str);
	return (1);
}

long long	ft_atoi(const char *str)
{
	long long int	nb;
	int				i;
	int				sign;

	i = 0;
	nb = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb *= 10;
		nb += str[i] - '0';
		if (nb > 2147483647)
			return (-1);
		i++;
	}
	nb *= sign;
	return (nb);
}
