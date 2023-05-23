/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:07:53 by arbutnar          #+#    #+#             */
/*   Updated: 2023/03/09 17:02:57 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(long long time)
{
	long long	tmp;

	tmp = ft_time();
	usleep(time * 1000 - 20000);
	while (ft_time() < tmp + time)
		continue ;
}

void	ft_display_info(t_philo *philo, char *str)
{
	long long	time;

	time = ft_time() - philo->rules->start;
	if (ft_death_check(philo) == 1)
		return ;
	pthread_mutex_lock(&philo->rules->msg_mtx);
	printf("%lld %d %s\n", time, philo->id, str);
	pthread_mutex_unlock(&philo->rules->msg_mtx);
}
