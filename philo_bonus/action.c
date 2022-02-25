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
	sem_wait(philo->p_forks);
	sem_wait(philo->p_print);
	printf("%lldms %d "FORK_L"", \
	get_time() - philo->run_time, philo->id);
	sem_post(philo->p_print);
}

static void	right_fork(t_philo *philo)
{
	sem_wait(philo->p_forks);
	sem_wait(philo->p_print);
	printf("%lldms %d "FORK_R"", \
	get_time() - philo->run_time, philo->id);
	sem_post(philo->p_print);
}

void	eating(t_philo *philo)
{
	left_fork(philo);
	right_fork(philo);
	philo->start_eat = get_time();
	sem_wait(philo->p_print);
	printf("%lldms %d "EAT"", \
	get_time() - philo->run_time, philo->id);
	sem_post(philo->p_print);
	ft_time(philo->time_to_eat);
	sem_post(philo->p_forks);
	sem_post(philo->p_forks);
}

void	sleeping(t_philo *philo)
{
	sem_wait(philo->p_print);
	printf("%lldms %d "SLEEP"", \
	get_time() - philo->run_time, philo->id);
	sem_post(philo->p_print);
	ft_time(philo->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	sem_wait(philo->p_print);
	printf("%lldms %d "THINK"", \
	get_time() - philo->run_time, philo->id);
	sem_post(philo->p_print);
}
