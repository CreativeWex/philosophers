#include "../includes/philosophers.h"

int main(int argc, char **argv)
{
    t_args options;

    if(ft_validation(argc, argv) == -1)
        return (0);

    ft_structure_init(&options, argc, argv);  
    // debug_display_struct(&options);
    return (0);
}