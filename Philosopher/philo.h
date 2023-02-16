#ifndef	PHILO_H
#define	PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/wait.h>
# include <sys/time.h>

typedef	struct		s_philo
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	*right;
	pthread_mutex_t	*left;
}					t_philo;

typedef	struct		s_rules
{
	int				nb_philo;
	long long		eat_time;
	long long		sleep_time;
	long long		die_time;
	long long		must_eat;
	pthread_mutex_t	*forks;
	long long		start;
}					t_rules;

//utility
void	ft_error();
int		ft_atoi(const char *str);

//time
long long	ft_get_ms();

#endif
