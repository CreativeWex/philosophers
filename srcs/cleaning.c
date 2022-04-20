#include "../includes/philosophers.h"

// void ft_close_threads(t_args *options)
// {
// 	int	nbr_ph;

// 	nbr_ph = options->philo_number;
// 	if (nbr_ph == 1)
// 		pthread_mutex_unlock(&options->forks[0]);
// 	while (nbr_ph)
// 	{
// 		nbr_ph--;
// 		pthread_join(options->thread_ids[nbr_ph], NULL);
// 	}
// }