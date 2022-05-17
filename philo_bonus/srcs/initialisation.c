

#include "../includes/philo.h"

int	ft_init_semaphore(t_args *options)
{
	sem_unlink("forks");
	sem_unlink("lock_print");
	sem_unlink("mealcheck");
	options->forks = sem_open("forks", O_CREAT, S_IRWXU, options->philo_number);
	options->lock_print = sem_open("lock_print", O_CREAT, S_IRWXU, 1);
	options->eating_check = sem_open("mealcheck", O_CREAT, S_IRWXU, 1);
	if (options->forks <= 0 || options->lock_print <= 0 || options->eating_check <= 0)
		return (1);
	return (0);
}

void	ft_init_philo(t_args *options)
{
	int	i;

	i = options->philo_number;
	while (--i >= 0)
	{
		options->philo[i].id = i;
		options->philo[i].nbr_eated = 0;
		options->philo[i].t_last_eated = 0;
		options->philo[i].args = options;
	}
}

int	ft_init_structure(t_args *options, char **argv)
{
	options->philo_number = ft_atoi(argv[1]);
	options->t_die = ft_atoi(argv[2]);
	options->t_eat = ft_atoi(argv[3]);
	options->t_sleep = ft_atoi(argv[4]);
	options->f_is_dead = 0;
	options->total_eat = 0;
	if (options->philo_number < 1 || options->t_die < 60 || options->t_eat < 60
		|| options->t_sleep < 60 || options->philo_number > 200)
		return (1);
	if (argv[5])
	{
		options->nbr_of_eating = ft_atoi(argv[5]);
		if (options->nbr_of_eating <= 0)
			return (1);
	}
	else
		options->nbr_of_eating = -1;
	if (options->nbr_of_eating == 1)
		options->nbr_of_eating++;
	return (0);
}

int	ft_init_pids(t_args *options)
{
	int			i;
	t_philos	*phi;

	i = -1;
	phi = options->philo;
	options->t_start = ft_current_time();
	while (++i < options->philo_number)
	{
		phi[i].proc_id = fork();
		if (phi[i].proc_id < 0)
			return (1);
		if (phi[i].proc_id == 0)
			ft_philo_lifecycle(&(phi[i]));
		usleep(100);
	}
	return (0);
}
