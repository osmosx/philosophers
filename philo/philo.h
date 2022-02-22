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

# define FORK_L  "\033[33m has taken a left fork\033[0m\n"
# define FORK_R  "\033[33m has taken a right fork\033[0m\n"
# define EAT     "\033[32m is eating\033[0m\n"
# define SLEEP   "\033[35m is sleeping\033[0m\n"
# define THINK   "\033[36m is thinking\033[0m\n"
# define EAT_ALL "\033[31m all philosophers have eaten\033[0m\n"
# define DIE	 "\033[31m died\033[0m\n"

typedef struct s_philo
{
	int				id;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				count_eat;
	long long		run_time;
	long long		last_eat;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*print;
	pthread_mutex_t	m_time;
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
int				error_msg(void);
int				init(int argc, char **argv, t_data *data);
void			*philo_actions(void *argv);
void			eating(t_philo *philo);
void			sleeping(t_philo *philo);
void			thinking(t_philo *philo);
long long		get_time(void);
void			ft_time(long long start_time);
int				end_of_life(t_data *data);
#endif
