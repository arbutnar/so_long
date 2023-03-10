/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:13:53 by arbutnar          #+#    #+#             */
/*   Updated: 2023/03/10 20:13:53 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_natural_death(t_philo *philo, int i)
{
	long long	now;

	pthread_mutex_lock(&philo[i].meal_mtx);
	now = ft_time() - philo->rules->start - philo[i].start_meal;
	pthread_mutex_unlock(&philo[i].meal_mtx);
	if (now > philo->rules->time_to_die)
	{
		ft_display_info(&philo[i], "is dead");
		pthread_mutex_lock(&philo->rules->death_mtx);
		philo->rules->death = 1;
		pthread_mutex_unlock(&philo->rules->death_mtx);
		return (1);
	}
	return (0);
}

void	ft_monitor(t_philo *philo)
{
	int	i;
	int	count;

	while (1)
	{
		count = 0;
		i = 0;
		while (i < philo->rules->nb_philo)
		{
			if (ft_finish(&philo[i]) == 1)
				count += 1;
			if (count == philo->rules->nb_philo)
			{
				pthread_mutex_lock(&philo->rules->death_mtx);
				philo->rules->death = 1;
				pthread_mutex_unlock(&philo->rules->death_mtx);
				return ;
			}
			if (ft_natural_death(philo, i) == 1)
				return ;
			i++;
		}
	}
}

void	*ft_routine(void *ptr)
{
	t_philo	*philo;

	philo = ptr;
	if ((philo->id % 2) == 0)
		ft_usleep(philo->rules->time_to_eat);
	while (1)
	{
		if (ft_death(philo) == 1)
			return (NULL);
		if (ft_msg(philo) == 1)
			return (NULL);
	}
}

void	ft_thread(t_rules *rules, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < rules->nb_philo)
	{
		pthread_create(&philo[i].thread, NULL, ft_routine, &philo[i]);
		i++;
	}
	ft_monitor(philo);
	i = 0;
	while (i < rules->nb_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
}
