#include "../includes/philosophers.h"

void debug_display_struct(t_args *options)
{
    printf("\nphilo_number = %d", options->philo_number);
    printf("\nt_die = %d", options->t_die);
    printf("\nt_eat = %d", options->t_eat);
    printf("\nt_sleep = %d", options->t_sleep);
    printf("\nnum_eat = %d", options->nbr_of_eating);
}
// void debug_display_philos(t_args *options)
// {
//     int i;
    
//     i = -1;
//     while (++i < options->philo_number)
//     {
//         printf(RED "\n Philo nbr:" RESET "%d", options->philo_arr[i].philo_number);
//         printf(RED "\n Start time " RESET "%ld", options->philo_arr[i].t_start);
//         printf(RED "\n Current time " RESET "%ld", ft_current_time());
//         printf(RED "\n Passed time " RESET "%ld", ft_time_passed(options->philo_arr->t_start));
//     }
    
// }