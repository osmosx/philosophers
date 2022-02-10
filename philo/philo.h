/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nenvoy <nenvoy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:50:32 by nenvoy            #+#    #+#             */
/*   Updated: 2022/02/09 16:50:36 by nenvoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define FORK   "\033[33m has taken a fork\033[0m\n"
# define EAT    "\033[32m is eating\033[0m\n"
# define SLEEP  "\033[35m is sleeping\033[0m\n"
# define THINK  "\033[36m is thinking\033[0m\n"
# define DIE    "\033[31m died\033[0m\n"

typedef struct s_philo
{
	int				id;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				count_eat;
	unsigned long	run_time;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	print;
}					t_philo;

typedef struct s_data
{
	t_philo			*philo;
	int				philo_count;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
}					t_data;

int				ft_atoi(const char *str);
int				check(int argc, char **argv);
int				init(int argc, char **argv, t_data *data);
void			*philo_actions(void *argv);
unsigned long	get_time(void);
#endif
