#include "philo.h"

void	ft_philo_init(t_rules *rules, t_philo *philo)
{
	int i;

	i = 0;
	while (i < rules->nb_philo)
	{
		philo[i].id = i + 1;
		philo[i].right = &rules->forks[i];
		if (i != 0)
			philo[i].left = &rules->forks[i - 1];
		else
			philo[i].left = &rules->forks[rules->nb_philo - 1];
		i++;
	}
}

void	ft_rules_init(char *argv[], t_rules *rules)
{
	int i;

	rules->nb_philo = ft_atoi(argv[1]);
	//rules->eat_time = ft_atoi(argv[2]);
	//rules->sleep_time = ft_atoi(argv[3]);
	//rules->die_time = ft_atoi(argv[4]);
	//rules->must_eat = ft_atoi(argv[5]);
	rules->forks = malloc (sizeof(pthread_mutex_t) * rules->nb_philo);
	i = 0;
	while (i < rules->nb_philo)
	{
		pthread_mutex_init(&rules->forks[i], NULL);
		i++;
	}
	rules->start = ft_get_ms();
}

void	*ft_routine(void *philo)		//processo da far eseguire ad ogni thread/filosofo
{										//GLI ARRAY E I PUNTATORI SONO LA STESSA COSA
	t_philo *ptr;
	
	ptr = philo;
	if (ptr->id % 2 == 0)
		sleep(1);
	
	pthread_mutex_lock(ptr->right);
	printf("%d has taken his right fork\n", ptr->id);
	pthread_mutex_lock(ptr->left);
	printf("%d has taken his left fork\n", ptr->id);
	printf("Philosopher %d is eating\n", ptr->id);
	sleep(2);
	pthread_mutex_unlock(ptr->right);
	pthread_mutex_unlock(ptr->left);
}

int main(int argc, char *argv[])
{
	t_rules	rules;
	t_philo	*philo;
	int i;
	long long	time_stamp;
	long long	execusion;

	if (argc != 3)
		ft_error();
	ft_rules_init(argv, &rules);
	philo = malloc (sizeof(t_philo) * rules.nb_philo);
	ft_philo_init(&rules, philo);
	time_stamp = ft_get_ms();
	execusion = rules.start - time_stamp;
	i = 0;
	while (i < rules.nb_philo)
	{
		printf("%lld ", execusion);
		pthread_create(&philo[i].thread, NULL, &ft_routine, &philo[i]);
		i++;
	}
	pause();
	//i = 0;
	//while (i < rules.nb_philo)
	//{
	//	if (pthread_join(philo[i].thread, NULL) != 0)
	//		return 1;
	//	i++;
	//}
}
