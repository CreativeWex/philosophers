
#include "../includes/philosophers.h"

void    *ft_philo_lifecycle(void* philosopher)
{
    t_philos    *philo;

    philo = (t_philos *)philosopher;
    if (philo->id % 2 == 0)
        ft_mysleep((int)philo->args->t_eat);
    while(philo->args->f_is_dead && philo->nbr_eated != philo->args->nbr_of_eating)
    {
        pthread_mutex_lock(philo->left_fork);
        printf(MAG "%ld: %d has taken a left fork\n", (philo->args->t_start), philo->id);
        pthread_mutex_lock(philo->right_fork);
        printf(MAG "%ld: %d has taken a right fork\n", (philo->args->t_start), philo->id);
        ft_philo_eating(philo);
        pthread_mutex_unlock(philo->left_fork);
        pthread_mutex_unlock(philo->right_fork);
        ft_philo_sleeping(philo);
        ft_philo_sleeping(philo);
    }
    return (NULL);
}

// void    *ft_should_philo_die(void *data)
// {
//     int         i;
//     t_philos    *philo;
//     t_args      *options;

//     (t_philos*) data;
//     options = philo->args;
//     while (1)
// 	{
// 		options->nbr_of_eating = 0;
// 		i = 0;
// 		while (i < options->philo_number)
// 		{
// 			if (ft_need_to_stop(philo[i], options, i))
// 				return (NULL);
// 			i++;
// 			ft_mysleep(1);
// 		}
// 	}
// }

int main(int argc, char **argv)
{
    t_args      s_options;
    pthread_t   id;
    int         i;

    if(ft_validation(argc, argv) == 0)
        return (0);
    if(ft_structure_init(&s_options, argc, argv) == 0)
        return (0);
    ft_init_philos(&s_options);
    ft_init_threads(&s_options);

    // ft_init_mutex(&s_options);
    // printf("\n\tМьютексы инициализированы"); //
    // debug_display_philos(&s_options);
    // ft_init_threads(&s_options);
    // printf("\n\tПотоки открыты"); //

    return (0);
}