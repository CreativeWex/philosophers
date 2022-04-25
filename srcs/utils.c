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