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

void	init_philo(t_philo *philo, t_data *data, char **argv, int id)
{
	philo->id = id + 1;
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	philo->count_eat = data->count_eat;
	philo->print[id] = data->print;

}

static int	int_mutex(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_count);
	if (!data->forks)
		return (1);
	data->print = malloc(sizeof(pthread_mutex_t));
	if (!data->print)
		return (1);
	while (i < data->philo_count)
		pthread_mutex_init(data->forks[i++], NULL);
	pthread_mutex_init(data->print, NULL);
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
	if (argc == 6)
		data->count_eat = ft_atoi(argv[5]);
	else
		data->count_eat = -1;
	int_mutex(data);
	while (id < data->philo_count)
	{
		init_philo(&data->philo[i], data, argv, i);
		i++;
	}
}
