#include "../libft/libft.h"

void    ft_wrong_arg_num()
{
    printf("Wrong args num: ");
    printf("\n1: Number of philosophers");
	printf("\n2: Time to die");
	printf("\n3: Time to eat");
	printf("\n4: Time to sleep");
	printf("\n5: Number of eatings");
    exit(0);
}

void    ft_is_num(char **argv)
{
    int i;

    i = 1;
    while (argv[i])
	{
		if (!ft_atoi(argv[i]))
		{
			printf("Invalid argument: %s\n", argv[i]);
			exit(0);
		}
		i++;
	}
}

void ft_validation(int argc, char **argv)
{
    if (argc != 5 && argc !=6)
        ft_wrong_arg_num();
    ft_is_num(argv);
}