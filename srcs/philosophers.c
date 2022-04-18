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
    debug_display_struct(&s_options); //
    ft_init_philos(&s_options);
    printf("\n\tCтруктура философов инициализирована"); //
    ft_init_mutex(&s_options);
    printf("\n\tМьютексы инициализированы"); //
    ft_init_threads(&s_options);
    printf("\n\tПотоки открыты"); //

    return (0);
}