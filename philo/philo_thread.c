/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:25:08 by hujeong           #+#    #+#             */
/*   Updated: 2023/04/13 11:08:01 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "philo.h"

int	monitoring(t_philo *philo)
{
	if (mutex_count_read(&philo->com->count, &philo->com->full_philo_num)
		== philo->com->total_num)
		return (mutex_write(&philo->com->finish, &philo->com->is_finish));
	if (mutex_dead_print(philo))
		return (1);
	usleep(100);
	return (0);
}

void	*philo_thread(void *thread)
{
	t_philo	*philo;

	philo = (t_philo *)thread;
	mutex_read(&philo->com->start, &philo->com->is_start);
	if (is_full(philo))
		return (NULL);
	if (philo->num % 2 == 0)
		while (mutex_count_read(&philo->com->order, &philo->com->odd_num_start)
			!= philo->com->odd_num)
			usleep(100);
	else
		mutex_count_plus(&philo->com->order, &philo->com->odd_num_start);
	while (1)
	{
		if (eating(philo))
			break ;
		if (is_full(philo))
			break ;
		if (sleeping(philo) || thinking(philo))
			break ;
	}
	return (NULL);
}

int	clean_philo(t_common *com, t_philo *philo, t_fork *fork)
{
	int	i;

	if (fork != NULL)
	{
		i = -1;
		while (++i < com->total_num)
			pthread_mutex_destroy(&fork[i].mutex);
	}
	pthread_mutex_destroy(&com->start);
	pthread_mutex_destroy(&com->count);
	pthread_mutex_destroy(&com->print);
	pthread_mutex_destroy(&com->order);
	pthread_mutex_destroy(&com->finish);
	free(philo);
	free(fork);
	return (1);
}

int	clean_thread(pthread_t *thread, t_philo *philo, t_fork *fork, int num)
{
	int	i;

	if (num != philo->com->total_num)
	{
		mutex_write(&philo->com->finish, &philo->com->is_finish);
		pthread_mutex_unlock(&philo->com->start);
	}
	i = -1;
	while (++i < num)
		pthread_join(*(thread + i), NULL);
	free(thread);
	return (clean_philo(philo->com, philo, fork));
}

int	main_thread(t_philo *philo, t_fork *fork, pthread_t *thread, int i)
{
	thread = (pthread_t *)malloc(sizeof(pthread_t) * philo->com->total_num);
	if (thread == NULL)
		return (clean_philo(philo->com, philo, fork));
	pthread_mutex_lock(&(philo->com->start));
	while (++i < philo->com->total_num)
		if (pthread_create(thread + i, NULL, philo_thread, philo + i) != 0)
			return (clean_thread(thread, philo, fork, i));
	philo->com->start_time = get_current_ms_time();
	monitoring(philo);
	philo->com->is_start = true;
	pthread_mutex_unlock(&philo->com->start);
	while (!(mutex_read(&(philo->com->finish), &(philo->com->is_finish))))
		monitoring(philo);
	clean_thread(thread, philo, fork, philo->com->total_num);
	return (0);
}
