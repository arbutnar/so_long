/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:13:29 by arbutnar          #+#    #+#             */
/*   Updated: 2023/03/10 20:13:29 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_msg(t_philo *philo)
{
	pthread_mutex_lock(philo->right);
	ft_display_info(philo, "took a fork");
	if (philo->rules->nb_philo == 1)
		return (1);
	pthread_mutex_lock(philo->left);
	ft_display_info(philo, "took a fork");
	pthread_mutex_lock(&philo->meal_mtx);
	philo->start_meal = ft_time() - philo->rules->start;
	pthread_mutex_unlock(&philo->meal_mtx);
	ft_display_info(philo, "is eating");
	pthread_mutex_lock(&philo->eaten_mtx);
	philo->eaten += 1;
	pthread_mutex_unlock(&philo->eaten_mtx);
	ft_usleep(philo->rules->time_to_eat);
	pthread_mutex_unlock(philo->right);
	pthread_mutex_unlock(philo->left);
	ft_display_info(philo, "is sleeping");
	ft_usleep(philo->rules->time_to_sleep);
	ft_display_info(philo, "is thinking");
	return (0);
}

int	ft_death(t_philo *philo)
{
	int	check;

	pthread_mutex_lock(&philo->rules->death_mtx);
	check = philo->rules->death;
	pthread_mutex_unlock(&philo->rules->death_mtx);
	return (check);
}

int	ft_finish(t_philo *philo)
{
	int	i;

	pthread_mutex_lock(&philo->eaten_mtx);
	i = philo->eaten;
	pthread_mutex_unlock(&philo->eaten_mtx);
	if (i == philo->rules->must_eat)
		return (1);
	else
		return (0);
}

void	ft_exit(t_rules *rules)
{
	t_philo	*philo;
	int		i;

	philo = rules->philo;
	i = 0;
	while (i < rules->nb_philo)
	{
		pthread_mutex_destroy(&rules->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&rules->msg_mtx);
	pthread_mutex_destroy(&rules->death_mtx);
	pthread_mutex_destroy(&philo->meal_mtx);
	pthread_mutex_destroy(&philo->eaten_mtx);
	free(philo);
	free(rules->forks);
}
