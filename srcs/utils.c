#include "../includes/philosophers.h"

long	ft_current_time(void)
{
	struct timeval	t_start;

	gettimeofday(&t_start, NULL);
	return (t_start.tv_sec * 1000 + t_start.tv_usec / 1000);
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

void ft_join_clean(t_args *s_options, t_philos *philos, pthread_t *threads)
{
	int	i;

	i = -1;

	while(++i < s_options->philo_number)
	    pthread_join(threads[i], NULL);
	i = -1;
	while(++i < s_options->philo_number)
	{
		// pthread_mutex_unlock(&philos->args->lock_print); // если закомментить, то смерть выводит адекватно
		pthread_mutex_unlock(&s_options->forks[i]);
		pthread_mutex_destroy(&s_options->forks[i]);
	}
	free(threads);
	free(s_options->forks);
	free(philos);
}