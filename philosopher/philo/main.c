/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:04:17 by arbutnar          #+#    #+#             */
/*   Updated: 2023/03/09 17:10:28 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_rules_init(t_rules *rules, char *argv[])
{
	rules->nb_philo = ft_atoi(argv[1]);
	rules->time_to_die = ft_atoi(argv[2]);
	rules->time_to_eat = ft_atoi(argv[3]);
	rules->time_to_sleep = ft_atoi(argv[4]);
	if (rules->nb_philo <= 0 || rules->time_to_die <= 0
		|| rules->time_to_eat <= 0 || rules->time_to_sleep <= 0)
		return (ft_error("Args"));
	rules->death = 0;
	rules->start = ft_time();
	rules->philo = malloc(sizeof(t_philo) * rules->nb_philo);
	ft_mutex_init(rules);
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
		philo[i].right = &rules->forks[i];
		if (i != 0)
			philo[i].left = &rules->forks[i - 1];
		else
			philo[i].left = &rules->forks[rules->nb_philo - 1];
		pthread_mutex_init(&philo[i].eaten_mtx, NULL);
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
	ft_thread(&rules, rules.philo);
	ft_exit(&rules);
	return (0);
}
