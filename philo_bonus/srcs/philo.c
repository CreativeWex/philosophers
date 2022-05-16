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

void	ft_philo_eating(t_philos *philo)
{
	t_args  *args;

    args = philo->args;
    sem_wait(args->forks);
    sem_wait(args->lock_print);
    printf(MAG "%d: %d took a left fork\n" RESET,
        ft_time_passed(philo->args->t_start), philo->id);
    sem_post(args->lock_print);
    sem_wait(args->forks);
    sem_wait(args->lock_print);
    printf(MAG "%d: %d took a right fork\n" RESET,
        ft_time_passed(philo->args->t_start), philo->id);
    sem_post(args->lock_print);
    sem_wait(args->eating_check);
    sem_wait(args->lock_print);
    printf(YEL "%d: %d is eating\n" RESET,
		ft_time_passed(philo->args->t_start), philo->id);
    philo->t_last_eated = ft_current_time();
    sem_post(args->lock_print);
    sem_post(args->eating_check);
    ft_mysleep(args->t_eat);
    philo->nbr_eated++;
    sem_post(args->forks);
    sem_post(args->forks);
}

void	*ft_death_checker(void *void_philo)
{
	t_philos	*philo;
	t_args		*options;

	philo = (t_philos *)void_philo;
	options = philo->args;
	while (42)
	{
		sem_wait(options->eating_check);
		if (ft_time_passed(philo->t_last_eated) > options->t_die)
		{
			sem_wait(options->lock_print);
			printf(RED"%d: %d died\n",
			ft_time_passed(philo->args->t_start), philo->id);
			sem_post(options->eating_check);
			options->f_is_dead = 1;
			sem_wait(options->eating_check);
			exit(1);
		}
		sem_post(options->eating_check);
		if (options->f_is_dead)
			break ;
		usleep(1000);
		if (philo->nbr_eated >= options->nbr_of_eating && options->nbr_of_eating != -1)
			break ;
	}
	return (NULL);
}

 void	ft_philo_lifecycle(t_philos *philosopher, t_args *options)
{
	philosopher->t_last_eated = ft_current_time();
	pthread_create(&(philosopher->dead), NULL, ft_death_checker, philosopher);
	if (philosopher->id % 2)
		usleep(100);
	while (!options->f_is_dead)
	{
		ft_philo_eating(philosopher);
		if (philosopher->nbr_eated >= options->nbr_of_eating && options->nbr_of_eating != -1)
			break;
		sem_wait(options->lock_print);
    	printf(BLU "%d: %d is sleeping\n" RESET,
        	ft_time_passed(philosopher->args->t_start), philosopher->id);
    	sem_post(options->lock_print);
		ft_mysleep(options->t_sleep);
		sem_wait(options->lock_print);
    	printf(RESET "%d: %d is thinking\n" RESET,
        	ft_time_passed(philosopher->args->t_start), philosopher->id);
    	sem_post(options->lock_print);
	}
	pthread_join(philosopher->dead, NULL);
	if (options->f_is_dead)
		exit(1);
	exit(0);
 }

// waitpid ожидает любой дочерний процесс
// возвращает 0 если ни один дочерний процесс недоступен
// TODO: kill(15) - 15?
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
	sem_unlink("forks");
	sem_unlink("lock_print");
	sem_unlink("eating_check");
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
	ft_init_philos(&s_options, philos);
	if (ft_init_pids(&s_options))
	{
		printf(RED "Pid initialisation error\n" RESET);
		return (0);

	}
	ft_cleaning(&s_options);
	// free(philos);
	if (!s_options.f_is_dead)
		printf(GRN"[ All the philosophers ate ]\n");
	return (0);
}