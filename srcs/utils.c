#include "../includes/philosophers.h"

long	ft_current_time(void)
{
    long			result;
	struct timeval	tv;


	gettimeofday(&tv, NULL);
	result = 1000 * (size_t)tv.tv_sec + (size_t)tv.tv_usec / 1000;
	return (result);
}

void	ft_mysleep(int ms)
{
	long	time;

	time = ft_current_time();
	usleep(ms * 920);
	while (ft_current_time() < time + ms)
		usleep(ms * 3);
}

int	ft_time_passed(long t_start)
{
	return ((int)(ft_current_time() - t_start));
}

// int	ft_need_to_stop(t_philos philo, t_args options, int i)
// { 
// 	if (ft_time_passed(philo.t_last_eated) >= philo.args->t_die + 1)
// 	{
// 		options.f_is_dead = 1;
// 		pthread_mutex_lock(&philo.args->lock_print);
// 		printf(RED"%d: %d died\n", get_time_passed(philo.args->t_start), philo.id);
// 		pthread_mutex_unlock(&philo.args->lock_print);
// 		return (1);
// 	}
// 	if (philo.nbr_eated == philo.args->nbr_of_eating)
// 	{
// 		options.f_is_dead = 1;
		
// 	}
// }