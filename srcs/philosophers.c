#include "../includes/philosophers.h"



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
    ft_init_philos(&s_options);
    ft_init_threads(&s_options);

    // ft_init_mutex(&s_options);
    // printf("\n\tМьютексы инициализированы"); //
    // debug_display_philos(&s_options);
    // ft_init_threads(&s_options);
    // printf("\n\tПотоки открыты"); //

    return (0);
}