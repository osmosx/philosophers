/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nenvoy <nenvoy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:49:03 by nenvoy            #+#    #+#             */
/*   Updated: 2022/02/09 17:49:21 by nenvoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static int	check_die(t_philo *philo)
{
	if (get_time() - philo->start_eat > philo->time_to_die)
	{
		if (philo->start_eat == 0 && get_time() % 1000 < philo->time_to_die)
			return (0);
		return (1);
	}
	return (0);
}

void	*monitoring(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *)arg;
	usleep(3000);
	while (1)
	{
		if (check_die(philo) > 0)
		{
			sem_wait(philo->p_print);
			printf("%lldms %d "DIE"", get_time() - philo->run_time, philo->id);
			exit(0);
		}
		if (philo->count_eat == 0)
		{
			sem_wait(philo->p_print);
			printf("%lldms %d "EAT_ALL"", get_time() - philo->run_time, \
																philo->id);
			exit(0);
		}
	}
}
