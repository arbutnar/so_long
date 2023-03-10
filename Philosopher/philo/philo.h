/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:13:19 by arbutnar          #+#    #+#             */
/*   Updated: 2023/03/10 20:13:19 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	int				id;
	int				eaten;
	long long		start_meal;
	pthread_t		thread;
	pthread_mutex_t	*right;
	pthread_mutex_t	*left;
	pthread_mutex_t	meal_mtx;
	pthread_mutex_t	eaten_mtx;
	struct s_rules	*rules;
}	t_philo;

typedef struct s_rules
{
	int				nb_philo;
	int				must_eat;
	int				death;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	long long		start;
	pthread_mutex_t	*forks;
	pthread_mutex_t	msg_mtx;
	pthread_mutex_t	death_mtx;
	t_philo			*philo;
}	t_rules;

//utility
long long	ft_time(void);
int			ft_check_argv(int argc, char *argv[]);
int			ft_check_must_eat(int argc, char *argv[], t_rules *rules);
int			ft_error(char *str);
long long	ft_atoi(const char *str);

//thraed
void		ft_monitor(t_philo *philo);
void		*ft_routine(void *philo);
void		ft_thread(t_rules *rules, t_philo *philo);

//info
void		ft_usleep(long long wait);
void		ft_display_info(t_philo *philo, char *str);

//activities
int			ft_msg(t_philo *philo);
int			ft_death(t_philo *philo);
int			ft_finish(t_philo *philo);
void		ft_exit(t_rules *rules);

#endif