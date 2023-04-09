/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:01:58 by hujeong           #+#    #+#             */
/*   Updated: 2023/04/09 15:45:04 by hujeong          ###   ########.fr       */
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
