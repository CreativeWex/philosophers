/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnidorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:07:54 by jnidorin          #+#    #+#             */
/*   Updated: 2022/05/04 16:08:00 by jnidorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_structure_init(t_args *options, int argc, char **argv)
{
	options->philo_number = ft_atoi(argv[1]);
	options->t_die = ft_atoi(argv[2]);
	options->t_eat = ft_atoi(argv[3]);
	options->t_sleep = ft_atoi(argv[3]);
	options->f_is_dead = 0;
	options->total_eat = 0;
	options->t_start = ft_current_time();
	if (argc == 5)
		options->nbr_of_eating = -1;
	if (argc == 6)
		options->nbr_of_eating = ft_atoi(argv[5]);
	options->forks = malloc((options->philo_number + 1)
			* sizeof(pthread_mutex_t));
	pthread_mutex_init(&options->lock_print, NULL);
	return (1);
}

// Правая вилка по порядковому номеру
// Последний филосов берет левую вилку у первого,
// остальные философы берут свою правую
void	ft_init_philos(t_args *options, t_philos *philos, pthread_t *threads)
{
	int	i;

	i = -1;
	while (++i < options->philo_number)
	{
		pthread_mutex_init(&options->forks[i], NULL);
		philos[i].id = i + 1;
		philos[i].right_fork = &options->forks[i];
		philos[i].t_last_eated = 0;
		philos[i].nbr_eated = 0;
		philos[i].args = options;
		if (i != options->philo_number - 1)
			philos[i].left_fork = &options->forks[i + 1];
		else
			philos[i].left_fork = &options->forks[0];
		pthread_create(&threads[i], NULL, ft_philo_lifecycle,
			(void *)(&philos[i]));
	}
	options->philo_arr = philos;
}
