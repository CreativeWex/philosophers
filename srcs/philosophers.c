
#include "../includes/philosophers.h"

void    *ft_philo_lifecycle(void *philosopher)
{
    t_philos    *philo;

    philo = philosopher;
    if (philo->id % 2 == 0)
        ft_mysleep((int)philo->args->t_eat);
    while(philo->args->f_is_dead != 1 && philo->nbr_eated != philo->args->nbr_of_eating)
    {
        // pthread_mutex_lock(&philo->args->lock_print);
        // pthread_mutex_unlock(&philo->args->lock_print);

        // левая вилка
        pthread_mutex_lock(philo->left_fork);
        pthread_mutex_lock(&philo->args->lock_print);
        printf(MAG "%ld: %d has taken a left fork\n", (philo->args->t_start), philo->id);
        pthread_mutex_unlock(&philo->args->lock_print);

        // правая вилка
        pthread_mutex_lock(philo->right_fork);
        pthread_mutex_lock(&philo->args->lock_print);
        printf(MAG "%ld: %d has taken a right fork\n", (philo->args->t_start), philo->id);
        pthread_mutex_unlock(&philo->args->lock_print);
        ft_philo_eating(philo);
        pthread_mutex_unlock(philo->left_fork);
        pthread_mutex_unlock(philo->right_fork);
        ft_philo_sleeping(philo);
        ft_philos_thinking(philo);
    }
    return (NULL);
}

int stop(t_philos *philo, t_args *data, int i)
{
    if (data->t_die + 1 <= ft_time_passed(data->t_start) - philo[i].t_last_eated)
	{
		data->f_is_dead = 1;
        pthread_mutex_lock(&philo->args->lock_print);
		printf(RED"%d: %d died\n", ft_time_passed(philo->args->t_start), philo->id);
        pthread_mutex_unlock(&philo->args->lock_print);
		return (1);
	}
	if (philo[i].nbr_eated == data->nbr_of_eating)
	{
		data->total_eat++;
		if (data->total_eat == data->philo_number)
		{
            pthread_mutex_lock(&philo->args->lock_print);
			printf(GRN"%d: all the philosophers ate\n",
				ft_time_passed(data->t_start));
            pthread_mutex_unlock(&philo->args->lock_print);
			return (1);
		}
	}
	return (0);
}

void    *ft_should_philo_die(void *tmp)
{
    int         i;
    t_philos    *philo;
    t_args      *data;

    philo = tmp;
    data = philo[0].args;
    while(1)
    {
        data->total_eat = 0;
        i = 0;
        while (i < data->philo_number)
        {
            if (stop(philo, data, i))
                return (NULL);
            i++;
            ft_mysleep(1);
        }
    }
}

int main(int argc, char **argv)
{
    t_args      s_options;
    t_philos    *philos;
    pthread_t   *threads;
    int         i;

    if(ft_validation(argc, argv) == 0)
        return (0);
    if(ft_structure_init(&s_options, argc, argv) == 0)
        return (0);
    philos = malloc(s_options.philo_number * sizeof(t_philos));
    threads = malloc((s_options.philo_number + 1) * sizeof(pthread_t));
    ft_init_philos(&s_options, philos, threads);
    ft_init_threads(&s_options, philos);

    return (0);
}