/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 11:06:06 by hujeong           #+#    #+#             */
/*   Updated: 2023/04/03 20:13:01 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "philo.h"

void	set_fork(t_fork *fork, int num)
{
	int	i;

	i = -1;
	while (++i < num)
		pthread_mutex_init(fork[0].mutex, NULL);
}

void	set_philo(t_philo *philo, t_fork *fork)
{
	philo[0].left = fork[0];
	philo[0].right = fork[1];
	philo[1].left = fork[1];
	philo[1].right = fork[0];
}

void	set_monitor(t_monitoring *monitor)
{
	monitor->total_number = 2;
	monitor->time_to_die = 500;
	monitor->time_to_eat = 100;
	monitor->time_to_sleep = 100;
}

int	main(void)
{
	t_fork			fork[2];
	t_philo			philo[2];
	t_monitoring	monitor;

	set_monitor(&monitor);
	set_fork(fork, 2);
	set_philo(philo, fork);
	pthread_create();
	return (0);
}
