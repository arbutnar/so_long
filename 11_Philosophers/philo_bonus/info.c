/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:43:26 by arbutnar          #+#    #+#             */
/*   Updated: 2023/03/09 16:30:12 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long long	ft_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_display_info(t_philo *philo, char *str)
{
	long long	time;

	time = ft_time() - philo->rules->start;
	sem_wait(philo->rules->msg);
	printf("%lld %d %s \n", time, philo->id, str);
	sem_post(philo->rules->msg);
}

void	ft_kill_all(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->rules->nb_philo)
	{
		kill(philo[i].pid, SIGKILL);
		i++;
	}
	sem_unlink("/fork");
	sem_close(philo->rules->fork);
	sem_unlink("/messages");
	sem_close(philo->rules->msg);
	sem_unlink("/death");
	sem_close(philo->rules->death);
	sem_unlink("/max_eat");
	sem_close(philo->rules->max_eat);
	sem_unlink("/meal");
	sem_close(philo->rules->meal);
	free(philo);
}
