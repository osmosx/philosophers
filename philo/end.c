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

static int	count_eat(t_data *data)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < data->philo_count)
	{
		if (data->philo[i].count_eat == 0)
		{
			count++;
		}
		if (count == data->philo_count)
		{
			pthread_mutex_lock(data->philo->print);
			printf("%lldms %d "EAT_ALL"", \
			get_time() - data->philo->run_time, data->philo->id);
			pthread_mutex_unlock(data->philo->print);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	die(t_data *data)
{
	int			i;
	int			j;

	i = 0;
	while (i < data->philo_count)
	{
		if (get_time() - data->philo[i].last_eat >= data->philo[i].time_to_die)
		{
			pthread_mutex_lock(data->philo->print);
			j = -1;
			while (++j < data->philo_count)
				pthread_detach(data->philo[j].thread);
			printf("%lldms %d "DIE"", \
			get_time() - data->philo->run_time, data->philo->id);
			return (1);
		}
			i++;
	}
	return (0);
}

int	end_of_life(t_data *data)
{
	while (1)
	{
		if (die(data) == 1)
			return (1);
		if (count_eat(data) == 1)
			return (1);
	}
}
