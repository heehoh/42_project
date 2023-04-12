/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:17:45 by hujeong           #+#    #+#             */
/*   Updated: 2023/04/12 19:51:58 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <semaphore.h>
# define PICK "has taken a fork\n"
# define EAT "is eating\n"
# define SLEEP "is sleeping\n"
# define THINK "is thinking\n"
# define DIE "died\n"

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_philo
{
	int		total_num;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		full_philo_num;
	t_bool	eat_set;
	int		min_eat;
	int		num;
	int		eat_num;
	size_t	start_time;
	size_t	last_eat_time;
	sem_t	*fork;
}	t_philo;


#endif