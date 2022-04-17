#include "../includes/philosophers.h"

int main(int argc, char **argv)
{
    t_args options;

    if(ft_validation(argc, argv) == 0)
        return (0);
    if(ft_structure_init(&options, argc, argv) == 0)
        return (0);
    debug_display_struct(&options);
    return (0);
}