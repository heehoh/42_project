/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 11:06:06 by hujeong           #+#    #+#             */
/*   Updated: 2023/04/17 10:07:43 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_common	com;
	t_philo		*philo;
	t_fork		*fork;

	if ((argc != 5 && argc != 6) || set_common(&com, argc, argv)
		|| set_fork(&com, &fork) || set_philo(&com, &philo, fork)
		|| main_thread(philo, fork, NULL, -1))
		return (1);
	return (0);
}
