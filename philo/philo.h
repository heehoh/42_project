/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 11:45:26 by hujeong           #+#    #+#             */
/*   Updated: 2023/04/03 20:13:01 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

enum	e_fork
{
	put,
	grep
};

typedef struct s_fork
{
	pthread_mutex_t	*mutex;
	e_fork			status;
}	t_fork;

typedef struct s_philo
{
	s_fork	*left;
	s_fork	*right;
}	t_philo;

typedef struct s_monitoring
{

	int	total_number;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
}	t_monitoring;

#endif