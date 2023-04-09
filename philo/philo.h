/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 11:45:26 by hujeong           #+#    #+#             */
/*   Updated: 2023/04/09 17:45:23 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stddef.h>
# define PICK "has taken a fork\n"
# define EAT "is eating\n"
# define SLEEP "is sleeping\n"
# define THINK "is thinking\n"
# define DIE "died\n"

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_fork
{
	pthread_mutex_t	mutex;
	t_bool			is_pick;
}	t_fork;

typedef struct s_common
{
	int				total_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	t_bool			eat_set;
	t_bool			is_start;
	t_bool			is_finish;
	int				full_philo_num;
	int				min_eat;
	size_t			start_time;
	pthread_mutex_t	start;
	pthread_mutex_t	print;
	pthread_mutex_t	finish;
}	t_common;

typedef struct s_philo
{
	int			num;
	int			eat_num;
	size_t		last_eat_time;
	size_t		msg_time;
	t_fork		*left;
	t_fork		*right;
	t_common	*com;
}	t_philo;

int		ft_atoi(const char *str);
size_t	get_current_ms_time(void);
size_t	get_time(size_t start_time);
int		set_common(t_common *com, int argc, char **argv);
int		set_fork(t_common *com, t_fork **fork);
int		set_philo(t_common *com, t_philo **philo, t_fork *fork);
int		main_thread(t_philo *philo, t_fork *fork, pthread_t *thread, int i);
int		eating(t_philo *philo);
int		sleeping(t_philo *philo);
int		thinking(t_philo *philo);
t_bool	mutex_read(pthread_mutex_t *mutex, t_bool *bool);
int		mutex_print(t_philo *philo, size_t *msg_time, char *msg);

#endif