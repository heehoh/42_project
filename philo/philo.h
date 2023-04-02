/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 11:45:26 by hujeong           #+#    #+#             */
/*   Updated: 2023/04/02 15:34:53 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

enum	e_fork
{
	put,
	grep
};

typedef struct s_philo
{
	int	total_number;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
}	t_philo;

#endif