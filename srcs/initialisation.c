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
        philos->id = i;
        philos->nbr_eated = 0;
        philos->t_eat = options->t_eat;
        philos->t_sleep = options->t_sleep;
        philos->t_die = options->t_die;
        // время последнего обеда

    }
}