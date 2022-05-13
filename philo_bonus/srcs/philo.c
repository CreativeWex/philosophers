/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnidorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:04:21 by jnidorin          #+#    #+#             */
/*   Updated: 2022/05/04 16:05:04 by jnidorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO: пофиксить цвет вывода

#include "../includes/philo.h"

void	*ft_death_checker(void *void_philo)
{
	t_philos	*philo;

	philo = (t_philos *)void_philo;
	while(1)
	{
		sem_wait(philo->args->eating_check);
		if (ft_time_passed(philo->t_last_eated) > philo->args->t_die)
		{
			sem_wait(philo->args->lock_print);
    		printf(MAG "%d: %d is dead\n" RESET,
        		ft_time_passed(philo->args->t_start), philo->id);
    		sem_post(philo->args->lock_print);
			philo->args->f_is_dead = 1;
			sem_wait(philo->args->lock_print);
			exit(1);
		}
		sem_post(philo->args->eating_check);
		if (philo->args->eating_check)
			break;
		usleep(1000); // TODO: Попробовать удалить
		if (philo->nbr_eated >= philo->args->nbr_of_eating && philo->args->nbr_of_eating != -1)
			break;
	}
	return (NULL);
}

 void	ft_philo_lifecycle(t_philos *philosopher, t_args *options)
 {
	pthread_create(&(philosopher->dead), NULL, ft_death_checker, philosopher);
	if (philosopher->id % 2)
		usleep(42);
	while (!options->f_is_dead)
	{
		ft_philo_eating(philosopher);
		if (philosopher->nbr_eated >= options->nbr_of_eating && options->nbr_of_eating != -1)
			break;
		sem_wait(options->lock_print);
    	printf(MAG "%d: %d is sleeping\n" RESET,
        	ft_time_passed(philosopher->args->t_start), philosopher->id);
    	sem_post(options->lock_print);
		ft_mysleep(options->t_sleep);
		sem_wait(options->lock_print);
    	printf(MAG "%d: %d is thinking\n" RESET,
        	ft_time_passed(philosopher->args->t_start), philosopher->id);
    	sem_post(options->lock_print);
	}
	pthread_join(philosopher->dead, NULL);
	if (options->f_is_dead)
		exit(1);
	exit(0);
 }

// void	*ft_should_philo_die(void *tmp)
// {
// 	int			i;
// 	t_philos	*philo;
// 	t_args		*data;

// 	philo = tmp;
// 	data = philo[0].args;
// 	while (1)
// 	{
// 		data->total_eat = 0;
// 		i = 0;
// 		while (i < data->philo_number)
// 		{
// 			if (stop(philo, data, i))
// 				return (0);
// 			i++;
// 			ft_mysleep(1);
// 		}
// 	}
// }

// waitpid ожидает любой дочерний процесс
// возвращает 0 если ни один дочерний процесс недоступен
// TODO: kill(15)
void	ft_cleaning(t_args *options)
{
	int	i;
	int	ret;

	i = 0;
	while (++i < options->philo_number)
	{
		waitpid(-1, &ret, 0);
		if (ret != 0)
		{
			i = -1;
			while (++i < options->philo_number)
				kill(options->philo_arr[i].proc_id, 15);
			break;
		}
		i++;
	}
	sem_close(options->forks);
	sem_close(options->lock_print);
	sem_close(options->eating_check);
	sem_unlink(options->forks);
	sem_unlink(options->lock_print);
	sem_unlink(options->eating_check);
}

int	main(int argc, char **argv)
{
	t_args		s_options;
	t_philos	*philos;
	int			i;

	i = 0;
	if (ft_validation(argc, argv) == 0)
		return (0);
	if (ft_structure_init(&s_options, argc, argv) == 0)
		return (0);
	if (ft_init_semaphore(&s_options))
	{
		printf(RED "Semaphore initialisation error\n" RESET);
		return (0);
	}
	philos = malloc(s_options.philo_number * sizeof(t_philos));
	if (ft_init_philos(&s_options, philos))
		{
			printf(RED "Threads creating error\n" RESET);
			return (0);
		}
	ft_cleaning(&s_options);
	if (s_options.total_eat == s_options.philo_number)
		printf(GRN"[ All the philosophers ate ]\n");
	return (0);
}
