#include "../includes/philosophers.h"

int ft_structure_init(t_args *options, int argc, char **argv)
{
    options->philo_number = ft_atoi(argv[1]);
    options->t_die = ft_atoi(argv[2]);
    options->t_eat = ft_atoi(argv[3]);
    options->t_sleep = ft_atoi(argv[3]);
    if (options->philo_number < 1 || options->t_die <= 0
    || options->t_eat <= 0 ||options->philo_number <= 0
    || options->t_sleep <= 0)
    {
        printf("Error: wrong parameter(s)");
        return (0);
    }
    options->f_is_dead = 0;
    options->total_eat = 0;
    options->t_start = ft_current_time();
    if (argc == 5)
        options->nbr_of_eating = -1;
    if (argc == 6)
        options->nbr_of_eating = ft_atoi(argv[5]);
    return (1);
}

void ft_init_philos(t_args *options)
{
    int         i;
    t_philos    *philos;

    philos = malloc(options->philo_number * sizeof(t_philos));
    i = -1;
    while (++i < options->philo_number)
    {
        philos[i].id = i;
        philos[i].right_fork = &options->forks[i];
        philos[i].nbr_eated = 0;
        philos[i].args = options;
        if (i != options->philo_number - 1)
			philos[i].left_fork = &options->forks[i + 1];
		else
			philos[i].left_fork = &options->forks[0];
        philos[i].left_fork = &options->forks[i + 1];
    }
    options->philo_arr = philos;
    // free(philos);
}

void    ft_init_threads(t_args *options)
{
    pthread_t *threads;
    pthread_t data;
    int       i;

    threads = malloc((options->philo_number + 1) * sizeof(pthread_t));
    options->forks = malloc((options->philo_number + 1) * sizeof(pthread_mutex_t));
    pthread_mutex_init(&options->lock_print, NULL);
    i = -1;
    while(++i < options->philo_number)
    {
        pthread_mutex_init(&options->forks[i], NULL);
        pthread_create(&threads[i], NULL, ft_philo_lifecycle, (void *)&options->philo_arr[i]); // для каждого философа открываем поток
    }
    usleep(100);
    pthread_create(&data, NULL, ft_should_philo_die, (void *)&options->philo_arr); // Поток для отслеживания философов
    i = -1;
    while(++i < options->philo_number)
    {
        pthread_mutex_destroy(&options->forks[i]);
        pthread_join(threads[i], NULL);
    }
    pthread_mutex_destroy(&options->lock_print);
    free(threads);
    free(options->forks);
}