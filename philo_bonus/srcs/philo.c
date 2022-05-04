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

#include "../includes/philo.h"

 void	ft_philo_lifecycle(t_philos *philosopher, t_args *options)
 {

	 // TODO: открыть поток для проверки на смерть
	if (philosopher->id % 2)
		usleep(42);
	while (!options->f_is_dead)
	{
		// TODO: функция питания для философа
	}
 	return (NULL);
 }

// int	stop(t_philos *philo, t_args *data, int i)
// {
// 	if (data->t_die + 1 <= ft_time_passed(data->t_start)
// 		- philo[i].t_last_eated)
// 	{
// 		data->f_is_dead = 1;
// 		pthread_mutex_lock(&philo->args->lock_print);
// 		printf(RED"%d: %d died\n",
// 			ft_time_passed(philo->args->t_start), philo->id);
// 		return (1);
// 	}
// 	if (philo[i].nbr_eated == data->nbr_of_eating)
// 	{
// 		data->total_eat++;
// 		if (data->total_eat == data->philo_number)
// 			return (1);
// 	}
// 	return (0);
// }

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
	// TODO: Очистка и закрытие семафоров




	// if (s_options.total_eat == s_options.philo_number)
	// 	printf(GRN"[ All the philosophers ate ]\n");
	return (0);
}
