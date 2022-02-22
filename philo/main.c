/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nenvoy <nenvoy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:49:03 by nenvoy            #+#    #+#             */
/*   Updated: 2022/02/09 17:49:21 by nenvoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	*philo_actions(void *argv)
{
	t_philo	*philo;

	philo = (t_philo *)argv;
	if (philo->id % 2 != 0)
		usleep(100);
	while (1)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
}

void	thread_create(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		if ((pthread_create(&data->philo[i].thread, NULL,
					philo_actions, &data->philo[i])) != 0)
			return ;
		i++;
	}
	if (end_of_life(data) == 1)
		return ;
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (check(argc, argv))
		return (error_msg());
	init(argc, argv, &data);
	thread_create(&data);
	return (0);
}
