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
	printf("%lldms %d "FORK_R"%lldms %d "EAT"", \
	get_time() - philo->run_time, philo->id, \
	get_time() - philo->run_time, philo->id);
	pthread_mutex_unlock(philo->print);
}

void	eating(t_philo *philo)
{
	left_fork(philo);
	right_fork(philo);
	pthread_mutex_lock(&(philo->m_time));
	philo->last_eat = get_time();
	pthread_mutex_unlock(&(philo->m_time));
	ft_time(philo->last_eat, philo->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	if (philo->count_eat > 0)
	{
		pthread_mutex_lock(&(philo->m_time));
		philo->count_eat--;
		pthread_mutex_unlock(&(philo->m_time));
	}
}

void	sleeping(t_philo *philo)
{
	long long	start_sleep;

	start_sleep = get_time();
	pthread_mutex_lock(philo->print);
	printf("%lldms %d "SLEEP"", \
	get_time() - philo->run_time, philo->id);
	pthread_mutex_unlock(philo->print);
	ft_time(start_sleep, philo->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	pthread_mutex_lock(philo->print);
	printf("%lldms %d "THINK"", \
	get_time() - philo->run_time, philo->id);
	pthread_mutex_unlock(philo->print);
}
