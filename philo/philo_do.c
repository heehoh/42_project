/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_do.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:08:01 by hujeong           #+#    #+#             */
/*   Updated: 2023/04/22 11:02:30 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "philo.h"

int	put(t_fork *fork)
{
	fork->is_pick = false;
	pthread_mutex_unlock(&(fork->mutex));
	return (0);
}

int	pick(t_fork *fork)
{
	pthread_mutex_lock(&(fork->mutex));
	fork->is_pick = true;
	return (0);
}

int	eating(t_philo *philo)
{
	pick(philo->main);
	if (mutex_print(philo, &(philo->msg_time), PICK)
		|| philo->main == philo->secondary)
		return (put(philo->main) + 1);
	pick(philo->secondary);
	if (mutex_print(philo, &(philo->last_eat_time), EAT))
		return (put(philo->secondary) + put(philo->main) + 1);
	philo_doing(philo->com->start_time,
		philo->last_eat_time, philo->com->time_to_eat);
	put(philo->secondary);
	put(philo->main);
	++(philo->eat_num);
	return (0);
}

int	sleeping(t_philo *philo)
{
	if (mutex_print(philo, &(philo->msg_time), SLEEP))
		return (1);
	philo_doing(philo->com->start_time,
		philo->msg_time, philo->com->time_to_sleep);
	return (0);
}

int	thinking(t_philo *philo)
{
	if (mutex_print(philo, &(philo->msg_time), THINK))
		return (1);
	return (0);
}
