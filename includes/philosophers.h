# include <stdio.h>
# include <pthread.h>
# include "../libft/libft.h"
# include <sys/time.h>

typedef struct s_time
{
    long    tv_sec;
    long    tv_usec;
}           t_time;

// философы
typedef struct s_philos
{
    int       id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
    int             nbr_eated;
    int             t_die;
    int             t_eat;
    int             t_sleep;
    int             t_last_eated;
    
    // struct t_time   eating_time;          

}       t_philos;

// параметры
typedef struct s_args
{
    int             philo_number;
    int             t_die;
    int             t_eat;
    int             t_sleep;
    int             nbr_of_eating;
    int             must_die;
    pthread_mutex_t	lock_print;
    pthread_mutex_t	*forks; // 

    t_philos        philo_arr;

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

// utils.c
long	ft_current_time(void);

//testing is 300 bucks
void    debug_display_struct(t_args *options);

