/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_mutex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 13:48:14 by hujeong           #+#    #+#             */
/*   Updated: 2023/04/11 16:40:23 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philo.h"

int	mutex_print(t_philo *philo, size_t *msg_time, char *msg)
{
	pthread_mutex_lock(&(philo->com->print));
	if (mutex_read(&philo->com->finish, &philo->com->is_finish))
	{
		pthread_mutex_unlock(&philo->com->print);
		return (1);
	}
	*msg_time = get_time(philo->com->start_time);
	printf("%zu %d %s", *msg_time, philo->num, msg);
	pthread_mutex_unlock(&(philo->com->print));
	return (0);
}

int	mutex_count_read(pthread_mutex_t *mutex, int *num)
{
	int	value;

	pthread_mutex_lock(mutex);
	value = *num;
	pthread_mutex_unlock(mutex);
	return (value);
}

int	mutex_count_plus(pthread_mutex_t *mutex, int *num)
{
	pthread_mutex_lock(mutex);
	++(*num);
	pthread_mutex_unlock(mutex);
	return (0);
}

int	mutex_write(pthread_mutex_t *mutex, t_bool *bool)
{
	pthread_mutex_lock(mutex);
	*bool = true;
	pthread_mutex_unlock(mutex);
	return (0);
}

t_bool	mutex_read(pthread_mutex_t *mutex, t_bool *bool)
{
	t_bool	value;

	pthread_mutex_lock(mutex);
	value = *bool;
	pthread_mutex_unlock(mutex);
	return (value);
}
