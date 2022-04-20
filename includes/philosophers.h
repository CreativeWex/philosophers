#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <pthread.h>
# include "../libft/libft.h"
# include <sys/time.h>

# define RED	"\x1b[31m"
# define RESET "\x1B[0m"

struct s_args;

// философы
typedef struct s_philos
{
    int             id;

	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
    int             nbr_eated;
    time_t          t_last_eated;

    struct s_args   *args;
    
    // struct t_time   eating_time;          

}                   t_philos;

// параметры
typedef struct s_args
{
    int                 philo_number;
    time_t              t_die;
    time_t              t_eat;
    time_t              t_sleep;
    int                 nbr_of_eating;
    pthread_mutex_t	    lock_print;
    pthread_mutex_t	    *forks; 
    int                 f_is_dead;
    time_t              t_start;
    t_philos            *philo_arr;

}                   t_args;

// validation.c
int     ft_validation(int argc, char **argv);

// initialisation.c
int     ft_structure_init(t_args *options, int argc, char **argv);
void    ft_init_philos(t_args *options);
void    ft_init_mutex(t_args *options);
void    ft_init_threads(t_args *options);

// processing.c 
void    *ft_philo_lifecycle(void* options);
void    *ft_should_philo_die(void *options);

// utils.c
long	ft_current_time(void);
long	ft_time_passed(time_t start);

// cleaning.c
void    ft_close_threads(t_args *options);


//testing is 300 bucks
void    debug_display_struct(t_args *options);
void    debug_display_philos(t_args *options);

#endif