#include "../includes/philosophers.h"

void ft_philo(int philo_id)
{
    printf("Я родился");
}

int main(int argc, char **argv)
{
    t_args  s_options;
    pthread_t id;
    void*    data;
    int i;

    if(ft_validation(argc, argv) == 0)
        return (0);
    if(ft_structure_init(&s_options, argc, argv) == 0)
        return (0);
    
    // инит мьютекса
    ft_init_philos(&s_options);
    printf("\nCтруктура инициализирована");
    // pthread_create(&id, 0, ft_philo, arr_philos[0].philo_id);
    
    return (0);
}