#include "../includes/philosophers.h"

int ft_structure_init(t_args *options, int argc, char **argv)
{
    options->philo_number = ft_atoi(argv[1]);
    options->t_die = ft_atoi(argv[2]);
    options->t_eat = ft_atoi(argv[3]);
    options->t_sleep = ft_atoi(argv[3]);
    if (options->philo_number <= 0 || options->t_die <= 0
    || options->t_eat <= 0 ||options->philo_number <= 0
    || options->t_sleep <= 0)
    {
        printf("Error: wrong parameter(s)");
        return (0);
    }

    if (argc == 5)
        printf("5 args");
    if (argc == 6)
        printf("Допиливай код");

    return (1);
}