/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:01:58 by hujeong           #+#    #+#             */
/*   Updated: 2023/04/11 10:58:40 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include "philo.h"

size_t	get_current_ms_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

size_t	get_time(size_t start_time)
{
	return (get_current_ms_time() - start_time);
}

void	philo_doing(size_t time, size_t start_time, size_t time_to_do)
{
	while (get_time(time) - start_time < time_to_do)
		usleep(100);
}

t_bool	is_full(t_philo *philo)
{
	if (philo->com->eat_set && philo->eat_num == philo->com->min_eat)
	{
		mutex_count_plus(&philo->com->count, &philo->com->full_philo_num);
		while (!(mutex_read(&philo->com->finish, &philo->com->is_finish)))
			usleep(1000);
		return (true);
	}
	return (false);
}

int	ft_atoi(const char *str)
{
	long	value;
	int		sign;
	int		i;

	value = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		++str;
	if (str[i] == '-')
		return (-1);
	else if (str[i] == '+')
		++str;
	while (str[i] == '0')
		++str;
	while (str[i] >= '0' && str[i] <= '9')
		value = value * 10 + str[i++] - '0';
	if (str[i] != '\0')
		return (-1);
	if (sign == 1 && (i > 10 || (i == 10 && value >= 2147483648)))
		return (-1);
	return (sign * value);
}
