/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:22:25 by arbutnar          #+#    #+#             */
/*   Updated: 2023/03/09 16:27:44 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <time.h>
# include <fcntl.h>
# include <signal.h>

typedef struct s_philo
{
	int				id;
	int				pid;
	int				eaten;
	long long		start_meal;
	pthread_t		p_thread;
	struct s_rules	*rules;
}	t_philo;

typedef struct s_rules
{
	int			nb_philo;
	long long	time_to_die;
	long long	time_to_eat;
	long long	time_to_sleep;
	int			must_eat;
	long long	start;
	sem_t		*fork;
	sem_t		*msg;
	sem_t		*death;
	sem_t		*max_eat;
	sem_t		*meal;
	pthread_t	r_thread;
	t_philo		*philo;
}	t_rules;

long long	ft_time(void);
void		ft_usleep(long long wait);
int			ft_check_argv(int argc, char *argv[]);
int			ft_check_must_eat(int argc, char *argv[], t_rules *rules);
int			ft_error(char *str);
long long	ft_atoi(const char *str);

void		ft_processes(t_rules *rules);
void		ft_routine(t_philo *philo);

void		ft_display_info(t_philo *philo, char *str);
void		ft_kill_all(t_philo *philo);

#endif