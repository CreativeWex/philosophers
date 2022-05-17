/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnidorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:31:14 by jnidorin          #+#    #+#             */
/*   Updated: 2022/05/17 19:31:22 by jnidorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_philos_eating(t_philos *philo)
{
	t_args	*args;

	args = philo->args;
	sem_wait(args->forks);
	sem_wait(args->lock_print);
	printf(MAG "%lli: %d took a left fork\n",
		ft_time_passed(philo->args->t_start), philo->id);
	sem_post(args->lock_print);
	sem_wait(args->forks);
	sem_wait(args->lock_print);
	printf(MAG "%lli: %d took a right fork\n",
		ft_time_passed(philo->args->t_start), philo->id);
	sem_post(args->lock_print);
	sem_wait(args->eating_check);
	sem_wait(args->lock_print);
	printf(YEL "%lli: %d is eating\n",
		ft_time_passed(philo->args->t_start), philo->id);
	sem_post(args->lock_print);
	philo->t_last_eated = ft_current_time();
	sem_post(args->eating_check);
	ft_mysleep(args->t_eat);
	(philo->nbr_eated)++;
	sem_post(args->forks);
	sem_post(args->forks);
}

void	*ft_death_checker(void *void_philo)
{
	t_philos	*philo;

	philo = (t_philos *)void_philo;
	while (42)
	{
		sem_wait(philo->args->eating_check);
		if (ft_time_passed(philo->t_last_eated) > philo->args->t_die)
		{
			sem_wait(philo->args->lock_print);
			printf(RED"%lli: %d died\n",
				ft_time_passed(philo->args->t_start), philo->id);
			sem_post(philo->args->lock_print);
			philo->args->f_is_dead = 1;
			sem_wait(philo->args->lock_print);
			exit(1);
		}
		sem_post(philo->args->eating_check);
		if (philo->args->f_is_dead)
			break ;
		usleep(1000);
		if (philo->nbr_eated >= philo->args->nbr_of_eating
			&& philo->args->nbr_of_eating != -1)
			break ;
	}
	return (NULL);
}

void	ft_philo_lifecycle(void *void_philo)
{
	t_philos	*philo;

	philo = (t_philos *)void_philo;
	philo->t_last_eated = ft_current_time();
	pthread_create(&(philo->death_check), NULL, ft_death_checker, void_philo);
	if (philo->id % 2)
		usleep(42);
	while (!(philo->args->f_is_dead))
	{
		ft_philos_eating(philo);
		if (philo->nbr_eated >= philo->args->nbr_of_eating
			&& philo->args->nbr_of_eating != -1)
			break ;
		ft_philo_sleeping(philo);
		sem_wait(philo->args->lock_print);
		printf(RESET "%lli: %d is thinking\n",
			ft_time_passed(philo->args->t_start), philo->id);
		sem_post(philo->args->lock_print);
	}
	pthread_join(philo->death_check, NULL);
	if (philo->args->f_is_dead)
		exit(1);
	exit(0);
}

void	ft_cleaning_up(t_args *options)
{
	int	i;
	int	ret;

	i = 0;
	while (i < options->philo_number)
	{
		waitpid(-1, &ret, 0);
		if (ret != 0)
		{
			i = -1;
			while (++i < options->philo_number)
				kill(options->philo[i].proc_id, 15);
			break ;
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
	t_args	s_options;

	if (ft_validation(argc, argv) == 0)
		return (0);
	ft_init_structure(&s_options, argv);
	if (ft_init_semaphore(&s_options))
	{
		printf(RED "Semaphore initialisation error\n" RESET);
		return (0);
	}
	ft_init_philo(&s_options);
	if (ft_init_pids(&s_options))
	{
		printf(RED "Pid initialisation error\n" RESET);
		return (0);
	}
	ft_cleaning_up(&s_options);
	return (0);
}
