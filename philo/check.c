/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nenvoy <nenvoy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:49:03 by nenvoy            #+#    #+#             */
/*   Updated: 2022/02/09 17:49:21 by nenvoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static int	check_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	check(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 5 || argc == 6)
	{
		if (ft_atoi(argv[1]) > 200 || ft_atoi(argv[1]) < 2
			|| ft_atoi(argv[2]) < 60 || ft_atoi(argv[3]) < 60
			|| ft_atoi(argv[4]) < 60)
			return (1);
		if (argc == 6 && ft_atoi(argv[5]) < 0)
			return (1);
		while (i < argc)
		{
			if (check_number(argv[i]))
				return (1);
			i++;
		}
	}
	else
		return (1);
	return (0);
}
