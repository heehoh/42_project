/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:25:08 by hujeong           #+#    #+#             */
/*   Updated: 2023/04/09 17:37:23 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "philo.h"

int	monitoring(t_philo *philo)
{
	int		i;
	size_t	time;

	if (philo->com->full_philo_num == philo->com->total_num)
		return (mutex_write(&(philo->com->finish), &(philo->com->is_finish)));
	i = -1;
	while (++i < philo->com->total_num)
	{
		time = get_time(philo->com->start_time);
		if (time - philo[i].last_eat_time >= (size_t)philo->com->time_to_die)
			return (mutex_print(philo + i, &time, DIE)
				+ mutex_write(&(philo->com->finish), &(philo->com->is_finish)));
	}
}

void	*philo_thread(void *thread)
{
	t_philo	*philo;

	philo = (t_philo *)thread;
	mutex_count_write();
	mutex_read(&philo->com->start, &philo->com->is_start);
	while (1)
	{
		if (eating(philo))
			break ;
		if (philo->eat_num == philo->com->min_eat)
		{
			++(philo->com->full_philo_num);
			while (!(mutex_read(&philo->com->finish, &philo->com->is_finish)))
				usleep(1000);
			break ;
		}
		if (sleeping(philo) || thinking(philo))
			break ;
	}
	return (NULL);
}

int	clean_philo(t_philo *philo, t_fork *fork, int i)
{
	while (++i < philo->com->total_num)
		pthread_mutex_destroy(&(fork[i].mutex));
	pthread_mutex_destroy(&(philo->com->start));
	pthread_mutex_destroy(&(philo->com->print));
	pthread_mutex_destroy(&(philo->com->finish));
	free(philo);
	free(fork);
	return (1);
}

int	clean_thread(pthread_t *thread, t_philo *philo, t_fork *fork, int num)
{
	int	i;

	if (num != philo->com->total_num)
	{
		mutex_write(&(philo->com->finish), &(philo->com->is_finish));
		pthread_mutex_unlock(&(philo->com->start));
	}
	i = -1;
	while (++i < num)
		pthread_join(*(thread + i), NULL);
	free(thread);
	return (clean_philo(philo, fork, -1));
}

int	main_thread(t_philo *philo, t_fork *fork, pthread_t *thread, int i)
{
	thread = (pthread_t *)malloc(sizeof(pthread_t) * philo->com->total_num);
	if (thread == NULL)
		return (clean_philo(philo, fork, -1));
	pthread_mutex_lock(&(philo->com->start));
	while (++i < philo->com->total_num)
		if (pthread_create(thread + i, NULL, philo_thread, philo + i) != 0)
			return (clean_thread(thread, philo, fork, i));
	philo->com->start_time = get_current_ms_time();
	monitoring(philo);
	pthread_mutex_unlock(&(philo->com->start));
	while (philo->com->is_finish == false)
		monitoring(philo);
	clean_thread(thread, philo, fork, philo->com->total_num);
	return (0);
}
