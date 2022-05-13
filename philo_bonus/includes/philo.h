/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnidorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:49:45 by jnidorin          #+#    #+#             */
/*   Updated: 2022/05/04 15:49:49 by jnidorin         ###   ########.fr       */
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
# define BLU	"\x1B[34m"
# define GRN	"\x1B[32m"
# define YEL	"\x1B[33m"
# define MAG	"\x1B[35m"
# define CYN	"\x1B[36m"
# define WHT	"\x1B[37m"
# define RESET  "\x1B[0m"

struct				s_args;

// философы
typedef struct s_philos
{
	int				id;
	int				*left_fork;
	int				*right_fork;
	int				nbr_eated;
	long			t_last_eated;
	struct s_args	*args;
	pid_t			proc_id;
	pthread_t		dead;
	//x ate
}					t_philos;

// параметры
typedef struct s_args
{
	int					philo_number;
	long				t_die;
	long				t_eat;
	long				t_sleep;
	int					nbr_of_eating;
	sem_t				*lock_print;
	sem_t				*forks;
	sem_t				*eating_check;
	int					total_eat;
	int					f_is_dead;
	long				t_start;
	struct s_philos		*philo_arr;
	// t_philos			philo[200];
}						t_args;

// philosophers.c
void	ft_philo_lifecycle(t_philos *philosopher, t_args *options);
void	*ft_should_philo_die(void *data);

// validation.c
int		ft_validation(int argc, char **argv);

// initialisation.c
int		ft_structure_init(t_args *options, int argc, char **argv);
int		ft_init_semaphore(t_args *options);
int		ft_init_philos(t_args *options, t_philos *philos);


// utils.c
long	ft_current_time(void);
int		ft_time_passed(long t_start);
void	ft_mysleep(int ms);
int		ft_atoi(char *str);

// actions.c
void	ft_philo_eating(t_philos *philo);


#endif
