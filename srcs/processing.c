#include "../includes/philosophers.h"

void    *ft_philo_lifecycle(void* options)
{
    t_philos    *compare;

    compare = (t_philos *)options;
    compare->t_last_eated = ft_current_time();
    printf("Я родился"); //
    return (NULL);
}