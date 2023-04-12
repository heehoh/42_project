/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_set_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:36:33 by hujeong           #+#    #+#             */
/*   Updated: 2023/04/12 19:58:21 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	set_philo(t_philo *philo)
{
	philo->fork = sem_open("fork", O_CREAT);
	if (philo->fork == SEM_FAILED)
}
