/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:30:10 by arbutnar          #+#    #+#             */
/*   Updated: 2023/03/09 16:31:39 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

sem_t	*ft_semaphores(char *name, int value)
{
	sem_t	*sem;

	sem = sem_open(name, O_CREAT | O_EXCL, 0777, value);
	if (sem == SEM_FAILED)
	{
		sem_unlink(name);
		sem = sem_open(name, O_CREAT, 0777, value);
	}
	return (sem);
}

int	ft_arg_limits(t_rules *rules)
{
	if (rules->nb_philo <= 0 || rules->time_to_die <= 0
		|| rules->time_to_eat <= 0 || rules->time_to_sleep <= 0)
		return (1);
	if (rules->nb_philo > 2147483647 || rules->time_to_die > 2147483647
		|| rules->time_to_eat > 2147483647 || rules->time_to_sleep > 2147483647)
		return (1);
	return (0);
}

int	ft_rules_init(t_rules *rules, char *argv[])
{
	rules->nb_philo = ft_atoi(argv[1]);
	rules->time_to_die = ft_atoi(argv[2]);
	rules->time_to_eat = ft_atoi(argv[3]);
	rules->time_to_sleep = ft_atoi(argv[4]);
	if (ft_arg_limits(rules) == 1)
		return (ft_error("Args"));
	rules->fork = ft_semaphores("/fork", rules->nb_philo);
	rules->msg = ft_semaphores("/messages", 1);
	rules->death = ft_semaphores("/death", 0);
	rules->max_eat = ft_semaphores("/max_eat", 0);
	rules->meal = ft_semaphores("/meal", 1);
	rules->start = ft_time();
	rules->philo = malloc(sizeof(t_philo) * rules->nb_philo);
	return (0);
}

void	ft_philo_init(t_rules *rules, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < rules->nb_philo)
	{
		philo[i].id = i + 1;
		philo[i].eaten = 0;
		philo[i].start_meal = 0;
		philo[i].rules = rules;
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_rules	rules;

	if ((argc != 5 && argc != 6) || (ft_check_argv(argc, argv) == 1))
		return (ft_error("Args"));
	if (ft_check_must_eat(argc, argv, &rules) == 1)
		return (1);
	if (ft_rules_init(&rules, argv) == 1)
		return (1);
	ft_philo_init(&rules, rules.philo);
	ft_processes(&rules);
	return (0);
}
