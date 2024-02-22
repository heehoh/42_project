/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_mutex2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:09:12 by hujeong           #+#    #+#             */
/*   Updated: 2023/04/11 17:04:22 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philo.h"

size_t	mutex_dead_print(t_philo *philo)
{
	int		i;
	size_t	time;

	pthread_mutex_lock(&philo->com->print);
	i = -1;
	while (++i < philo->com->total_num)
	{
		time = get_time(philo->com->start_time);
		if (time - philo[i].last_eat_time >= (size_t)philo->com->time_to_die)
		{
			printf("%zu %d %s", time, philo[i].num, DIE);
			mutex_write(&philo->com->finish, &philo->com->is_finish);
			pthread_mutex_unlock(&philo->com->print);
			return (1);
		}
	}
	pthread_mutex_unlock(&philo->com->print);
	return (0);
}
