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