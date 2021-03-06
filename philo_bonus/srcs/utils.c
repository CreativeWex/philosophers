/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnidorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:30:24 by jnidorin          #+#    #+#             */
/*   Updated: 2022/05/17 19:30:29 by jnidorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_philo_sleeping(t_philos *philo)
{
	sem_wait(philo->args->lock_print);
	printf(BLU "%lli: %d is sleeping\n",
		ft_time_passed(philo->args->t_start), philo->id);
	sem_post(philo->args->lock_print);
	ft_mysleep(philo->args->t_sleep);
}

int	ft_atoi(const char *str)
{
	unsigned int	i;
	int				sign;
	unsigned long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (((str[i] > 8) && (str[i] < 14)) || (str[i] == 32))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ((str[i] && str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if ((sign == -1) && (res > 9223372036854775808u))
		return (0);
	if ((sign == 1) && (res >= 9223372036854775808u))
		return (-1);
	return (sign * res);
}

long long	ft_time_passed(long t_start)
{
	return ((int)(ft_current_time() - t_start));
}

long long	ft_current_time(void)
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
