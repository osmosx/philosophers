/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nenvoy <nenvoy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:49:03 by nenvoy            #+#    #+#             */
/*   Updated: 2022/02/09 17:49:21 by nenvoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_time(long long start_time)
{
	long long	time;

	time = get_time();
	while (get_time() < (time + start_time))
		usleep(100);
}

int	error_msg(void)
{
	printf(" ____________________________________________________ \n");
	printf("|          Enter 4 or 5 arguments    |    Value      |\n");
	printf("|____________________________________________________|\n");
	printf("|        [1][Number of philosophers] |  [1 - 200]    |\n");
	printf("|        [2][Time to die]            |  [  > 60 ]    |\n");
	printf("|        [3][Time to eat]            |  [  > 60 ]    |\n");
	printf("|        [4][Time to sleep]          |  [  > 60 ]    |\n");
	printf("|        [5][Number of meals]        |  [  > 0  ]    |\n");
	printf("|____________________________________________________|\n");
	return (0);
}
