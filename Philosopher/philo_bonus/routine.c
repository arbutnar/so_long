#include "philo_bonus.h"

void	*ft_monitor(void *ph)
{
	t_philo		*philo;
	long long	now;

	philo = ph;
	while (1)
	{
		now = ft_time() - philo->rules->start;
		sem_wait(philo->meal);
		now -= philo->start_meal;
		sem_post(philo->meal);
		if (now > philo->rules->time_to_die)
		{
			sem_wait(philo->rules->msg);
			printf("%lld %d %s\n", ft_time() - philo->rules->start, philo->id, "died");
			sem_post(philo->rules->death);
		}
	}
	return (NULL);
}

void	ft_routine(t_philo *philo)
{
	philo->meal = malloc(sizeof(sem_t));
	sem_init(philo->meal, 0, 1);
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
		sem_wait(philo->meal);
		philo->start_meal = ft_time() - philo->rules->start;
		sem_post(philo->meal);
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
	t_rules *rules;
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
	int i;

	i = 0;
	while (i < rules->nb_philo)
	{
		rules->philo[i].pid = fork();
		if (rules->philo[i].pid == 0) {
			ft_routine(&rules->philo[i]);
		}
		i++;
	}
	if (rules->must_eat != -1)
		pthread_create(&rules->r_thread, NULL, ft_must_eat, rules);
	sem_wait(rules->death);
	ft_kill_all(rules->philo);
}