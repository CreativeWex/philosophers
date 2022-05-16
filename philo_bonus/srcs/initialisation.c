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
	options->t_start = ft_current_time(); //TODO: В случае непредусмотренной смерти перенести строку в pid_init
	if (argc == 5)
		options->nbr_of_eating = -1;
	if (argc == 6)
		options->nbr_of_eating = ft_atoi(argv[5]);
	return (1);
}

int	ft_init_semaphore(t_args *options)
{
	sem_unlink("forks");
	sem_unlink("lock_print");
	sem_unlink("eating_check");
	options->forks = sem_open("forks", O_CREAT, S_IRWXU, options->philo_number);
	options->lock_print = sem_open("lock_print", O_CREAT, S_IRWXU, 1);
	options->eating_check = sem_open("eating_check", O_CREAT, S_IRWXU, 1);
	if (options->forks <= 0 || options->lock_print <= 0 || options->eating_check <= 0)
		return (1);
	return (0);
}

void	ft_init_philos(t_args *options, t_philos *philos)
{
	int	i;

	i = -1;
	while (++i < options->philo_number)
	{
		philos[i].id = i;
		philos[i].t_last_eated = 0;
		philos[i].nbr_eated = 0;
		philos[i].args = options;
	}
	options->philo_arr = philos;
}

int	ft_init_pids(t_args *options)
{
	int	i;

	i = -1;
	while (++i < options->philo_number)
	{
		options->philo_arr[i].proc_id = fork();
		if (options->philo_arr[i].proc_id < 0)
			return (1);
		if (options->philo_arr[i].proc_id == 0)
			ft_philo_lifecycle(&options->philo_arr[i], options);
		usleep(100); // TODO: попробовать убрать
	}
	return(0);
}

//TODO: leaks

//TODO: некорректный вывод когда философы поели достаточное количество раз
//TODO: философ не умирает хотя должен при тесте 4 310 200 100