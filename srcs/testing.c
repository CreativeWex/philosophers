#include "../includes/philosophers.h"

void debug_display_struct(t_args *options)
{
    printf("\nphilo_number = %d", options->philo_number);
    printf("\nt_die = %d", options->t_die);
    printf("\nt_eat = %d", options->t_eat);
    printf("\nt_sleep = %d", options->t_sleep);
    printf("\nnum_eat = %d", options->nbr_of_eating);
}