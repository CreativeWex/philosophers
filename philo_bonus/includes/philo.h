/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnidorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:31:45 by jnidorin          #+#    #+#             */
/*   Updated: 2022/05/17 19:31:49 by jnidorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <sys/wait.h>
# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h>

# define RED	"\x1b[31m"
# define BLU   "\x1B[34m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[36m"
# define WHT   "\x1B[37m"
# define RESET "\x1B[0m"

typedef struct s_philos
{
	int				id;
	int				nbr_eated;
	int				left_fork;
	int				right_fork;
	long long		t_last_eated;
	struct s_args	*args;
	pthread_t		death_check;
	pid_t			proc_id;
}					t_philos;

typedef struct s_args
{
	int				philo_number;
	long			t_eat;
	long			t_die;
	long			t_sleep;
	int				nbr_of_eating;
	int				f_is_dead;
	long long		t_start;
	sem_t			*eating_check;
	sem_t			*forks;
	sem_t			*lock_print;
	t_philos		philo[200];
	int				total_eat;
}					t_args;

// validation.c
int					ft_validation(int argc, char **argv);

//init.c
int					ft_init_structure(t_args *options, char **argv);
int					ft_init_semaphore(t_args *options);
void				ft_init_philo(t_args *options);
int					ft_init_pids(t_args *options);

// philo.c
void				ft_philo_lifecycle(void *void_philo);
void				ft_cleaning_up(t_args *options);

//utils.c
int					ft_atoi(const char *str);
long long			ft_current_time(void);
long long			ft_time_passed(long t_start);
void				ft_mysleep(int ms);
void				ft_philo_sleeping(t_philos *philo);

#endif
