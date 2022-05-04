/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnidorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:12:37 by jnidorin          #+#    #+#             */
/*   Updated: 2022/05/04 16:12:46 by jnidorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_wrong_arg_num(void)
{
	printf("-------------------");
	printf("\nWrong args num: ");
	printf("\n1: Number of philosophers");
	printf("\n2: Time to die");
	printf("\n3: Time to eat");
	printf("\n4: Time to sleep");
	printf("\n5: Number of eatings");
	printf("\n-------------------\n");
}

int	ft_is_num(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!ft_atoi(argv[i]) || ft_atoi(argv[i]) < 1)
		{
			printf("Invalid argument: %s\n", argv[i]);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_validation(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		ft_wrong_arg_num();
		return (0);
	}
	if (!ft_is_num(argv))
		return (0);
	return (1);
}