#include "philo.h"

void	ft_monitor(t_philo *philo)
{
	int 		i;
	int			count;
	long long	now;

	while (1)
	{
		count = 0;
		i = 0;
		while (i < philo->rules->nb_philo)
		{
			if (ft_finish(&philo[i]) == 1)
			{
				count += 1;
				if (count == philo->rules->nb_philo)
				{
					pthread_mutex_lock(&philo->rules->death_mtx);
					philo->rules->death = 1;
					pthread_mutex_unlock(&philo->rules->death_mtx);
					return ;
				}
			}
			now = ft_time() - philo->rules->start;
			pthread_mutex_lock(&philo[i].meal_mtx);
			now -= philo[i].start_meal;
			pthread_mutex_unlock(&philo[i].meal_mtx);
			if (now > philo->rules->time_to_die)
			{
				ft_philo_info(&philo[i], "is dead");
				pthread_mutex_lock(&philo->rules->death_mtx);
				philo->rules->death = 1;
				pthread_mutex_unlock(&philo->rules->death_mtx);
				return ;
			}
			i++;
		}
	}
}

void	*ft_routine(void *ptr)
{
	t_philo *philo;
	
	philo = ptr;
	if ((philo->id % 2) == 0)
		ft_usleep(philo->rules->time_to_eat);
	while (1)
	{
		if (ft_death_check(philo) == 1)
			return (NULL);
		if (ft_fork_msg(philo) == 1)
			return (NULL);
	}
}

void	ft_thread(t_rules *rules, t_philo *philo)
{
	int i;

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