/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nenvoy <nenvoy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:49:03 by nenvoy            #+#    #+#             */
/*   Updated: 2022/02/09 17:49:21 by nenvoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static void	left_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->print);
	printf("%lldms %d "FORK_L"", \
	get_time() - philo->run_time, philo->id);
	pthread_mutex_unlock(philo->print);
}

static void	right_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(philo->print);
	printf("%lldms %d "FORK_R"", \
	get_time() - philo->run_time, philo->id);
	pthread_mutex_unlock(philo->print);
}

static void	eating(t_philo *philo)
{
	long long	start_eat;

	start_eat = get_time();
	left_fork(philo);
	right_fork(philo);
	pthread_mutex_lock(philo->print);
	printf("%lldms %d "EAT"", \
	get_time() - philo->run_time, philo->id);
	pthread_mutex_unlock(philo->print);
	philo->last_eat = get_time();
	ft_time(philo->time_to_eat, start_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	if (philo->count_eat > 0)
		philo->count_eat--;
}

static void	sleeping(t_philo *philo)
{
	long long	start_sleep;

	start_sleep = get_time();
	pthread_mutex_lock(philo->print);
	printf("%lldms %d "SLEEP"", \
	get_time() - philo->run_time, philo->id);
	pthread_mutex_unlock(philo->print);
	ft_time(philo->time_to_eat, start_sleep);
}

static void	thinking(t_philo *philo)
{
	pthread_mutex_lock(philo->print);
	printf("%lldms %d "THINK"", \
	get_time() - philo->run_time, philo->id);
	pthread_mutex_unlock(philo->print);
}

void	*philo_actions(void *argv)
{
	t_philo	*philo;

	philo = (t_philo *)argv;
	if (philo->even_or_not == 1)
		usleep(100);
	while (1)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
}
