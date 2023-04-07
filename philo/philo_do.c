/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_do.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:08:01 by hujeong           #+#    #+#             */
/*   Updated: 2023/04/07 21:29:34 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "philo.h"

int	pick(t_philo *philo, t_fork *fork)
{
	pthread_mutex_lock(&(fork->mutex));
	pthread_mutex_lock(&(philo->com->print));
	if (philo->com->is_finish == true)
	{
		pthread_mutex_unlock(&(fork->mutex));
		pthread_mutex_unlock(&(philo->com->print));
		return (1);
	}
	fork->is_pick = true;
	printf("%lldms %3d %s", get_time(philo->com->start_time), philo->num, PICK);
	pthread_mutex_unlock(&(philo->com->print));
	return (0);
}

int	eating(t_philo *philo)
{
	size_t	eat_start_time;

	pthread_mutex_lock(&(philo->com->print));
	if (philo->com->is_finish == true)
	{
		pthread_mutex_unlock(&(philo->com->print));
		return (1);
	}
	eat_start_time = get_time(philo->com->start_time);
	printf("%lldms %3d %s", eat_start_time, philo->num, EAT);
	philo->last_eat_time = eat_start_time;
	pthread_mutex_unlock(&(philo->com->print));
	usleep(100);
	while (get_time(philo->com->start_time) - eat_start_time
		< philo->com->time_to_eat)
		usleep(100);
	philo->right->is_pick = false;
	pthread_mutex_unlock(philo->right);
	philo->left->is_pick = false;
	pthread_mutex_unlock(philo->left);
	return (0);
}

int	sleeping(t_philo *philo)
{
	size_t	sleep_start_time;

	pthread_mutex_lock(&(philo->com->print));
	if (philo->com->is_finish == true)
	{
		pthread_mutex_unlock(&(philo->com->print));
		return (1);
	}
	sleep_start_time = get_time(philo->com->start_time);
	printf("%lldms %3d %s", sleep_start_time, philo->num, SLEEP);
	pthread_mutex_unlock(&(philo->com->print));
	usleep(100);
	while (get_time(philo->com->start_time) - sleep_start_time
		< philo->com->time_to_sleep)
		usleep(100);
	return (0);
}

int	thinking(t_philo *philo)
{
	size_t	think_start_time;

	pthread_mutex_lock(&(philo->com->print));
	if (philo->com->is_finish == true)
	{
		pthread_mutex_unlock(&(philo->com->print));
		return (1);
	}
	think_start_time = get_time(philo->com->start_time);
	printf("%lldms %3d %s", think_start_time, philo->num, THINK);
	pthread_mutex_unlock(&(philo->com->print));
	usleep(100);
	return (0);
}
