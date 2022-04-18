#include "../includes/philosophers.h"

int ft_structure_init(t_args *options, int argc, char **argv)
{
    options->philo_number = ft_atoi(argv[1]);
    options->t_die = ft_atoi(argv[2]) * 1000;
    options->t_eat = ft_atoi(argv[3]) * 1000;
    options->t_sleep = ft_atoi(argv[3]) * 1000;
    if (options->philo_number < 1 || options->t_die <= 0
    || options->t_eat <= 0 ||options->philo_number <= 0
    || options->t_sleep <= 0)
    {
        printf("Error: wrong parameter(s)");
        return (0);
    }

    if (argc == 6)
        printf("5 args");
    if (argc == 7)
        printf("Допиливай код");
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
        philos[i].nbr_eated = 0;
        philos[i].t_eat = options->t_eat;
        philos[i].t_sleep = options->t_sleep;
        philos[i].t_die = options->t_die;
        philos[i].t_last_eated = ft_current_time();
        philos[i].args = options;
        philos[i].philo_number = options->philo_number;
    }
    options->philo_arr = philos;
}

void    ft_init_mutex(t_args *options)
{
    pthread_mutex_t *mutex;
    int             i;

    mutex = malloc(options->philo_number * sizeof(pthread_mutex_t));
    i = -1;
    while(++i < options->philo_number)
        pthread_mutex_init(&mutex[i], NULL);
    pthread_mutex_init(&options->lock_print, NULL);
    options->forks = mutex;
}

void    ft_init_threads(t_args *options)
{
    pthread_t *threads;
    pthread_t data;
    int       i;

    threads = malloc(options->philo_number * sizeof(pthread_t));
    i = -1;
    while(++i < options->philo_number)
    {
        pthread_create(&threads[i], NULL, ft_philo_lifecycle, (void *)&options->philo_arr);
    }
    pthread_create(&data, NULL, ft_should_philo_die, (void *)&options->philo_arr);
    pthread_join(data, NULL);
    options->thread_ids = threads;
}