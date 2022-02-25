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

void	*philo_actions(t_philo	*philo)
{
	philo->run_time = get_time();
	while (1)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
		if (philo->count_eat != -1)
			philo->count_eat--;
	}
}

void	philo_process(t_philo *philo)
{
	pthread_t	monitor;

	if (pthread_create(&monitor, NULL, monitoring, philo) != 0)
		exit(1);
	philo_actions(philo);
	if (pthread_join(monitor, NULL) != 0)
		exit(1);
	exit(0);
}

int	create_action(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->philo_count)
	{
		data->philo[i].pid = fork();
		if (data->philo[i].pid == 0)
			philo_process(&data->philo[i]);
		if (data->philo[i].pid < 0)
		{
			while (i >= 0)
			{
				kill(data->philo[i].pid, SIGKILL);
				i--;
			}
			write(2, "Fork error\n", 12);
			exit(1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (check(argc, argv))
		return (error_msg());
	if (init(argc, argv, &data) != 0)
	{
		write(2, "init error\n", 12);
		exit(1);
	}
	create_action(&data);
	waitpid(-1, NULL, 0);
	sem_close(data.forks);
	sem_close(data.print);
	sem_unlink("/fork");
	sem_unlink("/print");
	free(data.philo);
	return (0);
}
