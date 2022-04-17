# include <stdio.h>
# include <pthread.h>
# include "../libft/libft.h"

typedef struct s_args
{
    int philo_number;
    int t_die;
    int t_eat;
    int t_sleep;
    int num_eat;
}       t_args;

int ft_validation(int argc, char **argv);
int ft_structure_init(t_args *options, int argc, char **argv);

//testing is 300 bucks
void debug_display_struct(t_args *options);

