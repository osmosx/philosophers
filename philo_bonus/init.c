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
		data->philo[i].p_forks = data->forks;
		data->philo[i].p_print = data->print;
		data->philo[i].time_to_die = ft_atoi(argv[2]);
		data->philo[i].time_to_eat = ft_atoi(argv[3]);
		data->philo[i].time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			data->philo[i].count_eat = ft_atoi(argv[5]);
		else
			data->philo[i].count_eat = -1;
		data->philo[i].run_time = get_time();
		data->philo[i].start_eat = get_time();
		i++;
	}
}

int	init_forks(t_data *data)
{
	sem_unlink("/fork");
	data->forks = sem_open("/fork", O_CREAT, 0644, data->philo_count);
	if (data->forks == SEM_FAILED)
		return (1);
	sem_unlink("/print");
	data->print = sem_open("/print", O_CREAT, 0644, 1);
	if (data->print == SEM_FAILED)
		return (1);
	return (0);
}

int	init(int argc, char **argv, t_data *data)
{
	data->philo_count = ft_atoi(argv[1]);
	data->philo = malloc(sizeof(t_philo) * data->philo_count);
	if (!data->philo)
		return (1);
	if (init_forks(data) != 0)
		return (1);
	init_philo(data, argc, argv);
	return (0);
}
