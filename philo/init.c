/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nenvoy <nenvoy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:49:03 by nenvoy            #+#    #+#             */
/*   Updated: 2022/02/09 17:49:21 by nenvoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_data *data, int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		data->philo[i].id = i + 1;
		data->philo[i].time_to_die = ft_atoi(argv[2]);
		data->philo[i].time_to_eat = ft_atoi(argv[3]);
		data->philo[i].time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			data->philo[i].count_eat = ft_atoi(argv[5]);
		else
			data->philo[i].count_eat = -1;
		data->philo[i].run_time = 0;
		data->philo[i].print = data->print;
		data->philo[i].left_fork = &data->forks[i];
		data->philo[i].right_fork = &data->forks[(i + 1) % data->philo_count];
		i++;
	}
}

static int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_count);
	if (!data->forks)
		return (1);
	while (i < data->philo_count)
		pthread_mutex_init(&data->forks[i++], NULL);
	pthread_mutex_init(&data->print, NULL);
	return (0);
}

int	init(int argc, char **argv, t_data *data)
{
	int	i;

	i = 0;
	data->philo_count = ft_atoi(argv[1]);
	data->philo = malloc(sizeof(t_philo) * data->philo_count);
	if (!data->philo)
		return (1);
	init_mutex(data);
	init_philo(data, argc, argv);
	return (0);
}
