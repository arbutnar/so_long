/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:47:05 by arbutnar          #+#    #+#             */
/*   Updated: 2023/03/09 16:29:19 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ft_monitor(void *philo)
{
	t_philo		*ph;
	long long	now;

	ph = philo;
	while (1)
	{
		now = ft_time() - ph->rules->start;
		sem_wait(ph->rules->meal);
		now -= ph->start_meal;
		sem_post(ph->rules->meal);
		if (now > ph->rules->time_to_die)
		{
			sem_wait(ph->rules->msg);
			printf("%lld %d %s\n", ft_time() - ph->rules->start, ph->id, "died");
			sem_post(ph->rules->death);
		}
	}
	return (NULL);
}

void	ft_routine(t_philo *philo)
{
	pthread_create(&philo->p_thread, NULL, ft_monitor, philo);
	if ((philo->id % 2) == 0)
		ft_usleep(philo->rules->time_to_eat);
	while (1)
	{
		sem_wait(philo->rules->fork);
		ft_display_info(philo, "took a fork");
		sem_wait(philo->rules->fork);
		ft_display_info(philo, "took a fork");
		ft_display_info(philo, "is eating");
		philo->eaten += 1;
		if (philo->eaten == philo->rules->must_eat)
			sem_post(philo->rules->max_eat);
		sem_wait(philo->rules->meal);
		philo->start_meal = ft_time() - philo->rules->start;
		sem_post(philo->rules->meal);
		ft_usleep(philo->rules->time_to_eat);
		sem_post(philo->rules->fork);
		sem_post(philo->rules->fork);
		ft_display_info(philo, "is sleeping");
		ft_usleep(philo->rules->time_to_sleep);
		ft_display_info(philo, "is thinking");
	}
}

void	*ft_must_eat(void *ru)
{
	t_rules	*rules;
	int		i;

	rules = ru;
	i = 0;
	while (i < rules->nb_philo)
	{
		sem_wait(rules->max_eat);
		i++;
	}
	sem_post(rules->death);
	return (NULL);
}

void	ft_processes(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->nb_philo)
	{
		rules->philo[i].pid = fork();
		if (rules->philo[i].pid == 0)
			ft_routine(&rules->philo[i]);
		i++;
	}
	if (rules->must_eat != -1)
		pthread_create(&rules->r_thread, NULL, ft_must_eat, rules);
	sem_wait(rules->death);
	ft_kill_all(rules->philo);
}
