/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:25:08 by hujeong           #+#    #+#             */
/*   Updated: 2023/04/07 22:15:04 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "philo.h"

void	monitoring(t_philo *philo)
{
	int		i;
	size_t	starve_time;

	pthread_mutex_lock(&(philo->com->print));
	if (philo->com->full_philo_num == philo->com->total_num)
	{
		philo->com->is_finish = true;
		pthread_mutex_unlock(&(philo->com->print));
		return ;
	}
	i = -1;
	while (++i < philo->com->total_num)
	{
		starve_time = get_time(philo->com->start_time) - philo[i].last_eat_time;
		if (starve_time > philo->com->time_to_die)
		{
			printf("%lldms %3d %s", starve_time + philo[i].last_eat_time,
				philo[i].num, DIE);
			philo->com->is_finish = true;
			pthread_mutex_unlock(&(philo->com->print));
			return ;
		}
	}
	pthread_mutex_unlock(&(philo->com->print));
}

void	*philo_thread(void *thread)
{
	t_philo	*philo;

	philo = (t_philo *)thread;
	pthread_mutex_lock(&(philo->com->sit));
	pthread_mutex_unlock(&(philo->com->sit));
	if (philo->num % 2 == 0)
		usleep(100);
	while (1)
	{
		if (pick(philo, philo->left) || pick(philo, philo->right)
			|| eating(philo) || sleeping(philo) || thinking(philo))
			break ;
		if (philo->com->eat_set == true && philo->eat_num
			== philo->com->min_eat)
		{
			pthread_mutex_lock(&(philo->com->sit));
			++(philo->com->full_philo_num);
			pthread_mutex_unlock(&(philo->com->sit));
			while (philo->com->is_finish == false)
				usleep(1000);
			break ;
		}
	}
	return (NULL);
}

int	clean_thread(pthread_t *thread, t_philo *philo, t_fork *fork, int num)
{
	int	i;

	pthread_mutex_lock(&(philo->com->print));
	philo->com->is_finish = true;
	pthread_mutex_unlock(&(philo->com->print));
	if (num != philo->com->total_num)
		pthread_mutex_unlock(&(philo->com->sit));
	i = -1;
	while (++i < num)
		pthread_join(thread + i, NULL);
	free(thread);
	i = -1;
	while (++i < philo->com->total_num)
		pthread_mutex_destroy(&(fork[i].mutex));
	pthread_mutex_destroy(&(philo->com->sit));
	pthread_mutex_destroy(&(philo->com->print));
	free(philo);
	free(fork);
	return (1);
}

int	main_thread(t_philo *philo, t_fork *fork, pthread_t *thread)
{
	int	i;

	thread = (pthread_t *)malloc(sizeof(pthread_t) * philo->com->total_num);
	if (thread == NULL)
	{
		free(philo);
		free(fork);
		return (1);
	}
	pthread_mutex_lock(&(philo->com->sit));
	i = -1;
	while (++i < philo->com->total_num)
		if (pthread_create(thread + i, NULL, philo_thread, philo + i) != 0)
			return (clean_thread(thread, philo, fork, i));
	philo->com->start_time = get_current_ms_time();
	monitoring(philo);
	pthread_mutex_unlock(&(philo->com->sit));
	while (philo->com->is_finish == true)
		monitoring(philo);
	clean_thread(thread, philo, fork, philo->com->total_num);
	return (0);
}
