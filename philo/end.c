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

static void	detach(t_data *data)
{
	int	i;

	i = 0;
	while (i++ < data->philo_count)
		pthread_detach(data->philo[i].thread);
}

static int	count_eat(t_data *data)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < data->philo_count)
	{
		pthread_mutex_lock(&(data->philo[i].m_time));
		if (data->philo[i].count_eat == 0)
			count++;
		if (count == data->philo_count)
		{
			pthread_mutex_lock(data->philo[i].print);
			detach(data);
			printf("%lldms %d "EAT_ALL"", \
			get_time() - data->philo[i].run_time, data->philo->id);
			return (1);
		}
		pthread_mutex_unlock(&(data->philo[i].m_time));
		i++;
	}
	return (0);
}

static int	die(t_data *data)
{
	int			i;

	i = 0;
	while (i < data->philo_count)
	{
		pthread_mutex_lock(&(data->philo[i].m_time));
		if (get_time() - data->philo[i].last_eat > data->philo[i].time_to_die)
		{
			pthread_mutex_lock(data->philo[i].print);
			detach(data);
			printf("%lldms %d "DIE"", \
			get_time() - data->philo->run_time, data->philo->id);
			return (1);
		}
		pthread_mutex_unlock(&(data->philo[i].m_time));
		i++;
	}
	return (0);
}

static void	destroy_mt(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->philo->m_time);
	pthread_mutex_destroy(data->forks);
	pthread_mutex_destroy(&data->print);
}

int	end_of_life(t_data *data)
{
	while (1)
	{
		if (die(data) == 1)
		{
			destroy_mt(data);
			return (1);
		}
		if (count_eat(data) == 1)
		{
			destroy_mt(data);
			return (1);
		}
	}
}
