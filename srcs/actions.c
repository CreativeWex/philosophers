#include "../includes/philosophers.h"

void    ft_philo_eating(t_philos *philo)
{
    if (philo->args->f_is_dead == 1)
        return ;
    pthread_mutex_lock(&philo->args->lock_print);
    printf(YEL "%d: %d is eating\n", ft_time_passed(philo->args->t_start), philo->id);
    pthread_mutex_unlock(&philo->args->lock_print);
    philo->t_last_eated = ft_time_passed(philo->args->t_start);
    ft_mysleep((int)philo->args->t_eat);
    philo->nbr_eated++;
}

void    ft_philo_sleeping(t_philos *philo)
{
    if (philo->args->f_is_dead == 1)
        return ;
    pthread_mutex_lock(&philo->args->lock_print);
    printf(BLU "%d: %d is sleeping\n", ft_time_passed(philo->args->t_sleep), philo->id);
    pthread_mutex_unlock(&philo->args->lock_print);
    ft_mysleep((int)philo->args->t_sleep);
}

void    ft_philos_thinking(t_philos	*philo)
{
	if (philo->args->f_is_dead == 1)
		return ;
    pthread_mutex_lock(&philo->args->lock_print);
	printf(RESET "%d: %d is thinking\n", ft_time_passed(philo->args->t_start), philo->id);
    pthread_mutex_unlock(&philo->args->lock_print);
}