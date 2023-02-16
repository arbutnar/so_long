#include "philo.h"

long long	ft_get_ms()
{
	long long 		ms;
	struct timeval	time;

	gettimeofday(&time, NULL);
	ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ms);
}
