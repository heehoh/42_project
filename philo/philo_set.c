/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:06:27 by hujeong           #+#    #+#             */
/*   Updated: 2023/04/09 11:45:19 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo.h"

int	set_common(t_common *com, int argc, char **argv)
{
	com->total_num = ft_atoi(argv[1]);
	com->time_to_die = ft_atoi(argv[2]);
	com->time_to_eat = ft_atoi(argv[3]);
	com->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		com->eat_set = true;
		com->min_eat = ft_atoi(argv[5]);
	}
	else
	{
		com->eat_set = false;
		com->min_eat = 0;
	}
	if (com->total_num <= 0 || com->time_to_die < 0
		|| com->time_to_eat < 0 || com->time_to_sleep < 0
		|| (com->eat_set == true && com->min_eat < 0))
		return (1);
	pthread_mutex_init(&(com->print), NULL);
	pthread_mutex_init(&(com->start), NULL);
	pthread_mutex_init(&(com->finish), NULL);
	com->is_finish = false;
	com->full_philo_num = 0;
	return (0);
}

int	set_fork(t_common *com, t_fork **fork)
{
	int	i;

	*fork = (t_fork *)malloc(sizeof(t_fork) * com->total_num);
	if (*fork == NULL)
	{
		pthread_mutex_destroy(&(com->print));
		pthread_mutex_destroy(&(com->start));
		pthread_mutex_destroy(&(com->finish));
		return (1);
	}
	i = -1;
	while (++i < com->total_num)
		pthread_mutex_init(&((*fork + i)->mutex), NULL);
	return (0);
}

int	set_philo(t_common *com, t_philo **philo, t_fork *fork)
{
	int		i;

	*philo = (t_philo *)malloc(sizeof(t_philo) * com->total_num);
	if (*philo == NULL)
	{
		free(fork);
		return (1);
	}
	i = -1;
	while (++i < com->total_num)
	{
		(*philo)[i].num = i + 1;
		(*philo)[i].left = fork + i;
		(*philo)[i].eat_num = 0;
		(*philo)[i].last_eat_time = 0;
		if ((*philo)[i].num != com->total_num)
			(*philo)[i].right = fork + i + 1;
		else
			(*philo)[i].right = fork;
		(*philo)[i].com = com;
	}
	return (0);
}
