/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:38:18 by hujeong           #+#    #+#             */
/*   Updated: 2023/02/18 17:28:03 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra(t_stack *a)
{
	if (a->size >= 2)
		rotate(a);
}

void	rb(t_stack *b)
{
	if (b->size >= 2)
		rotate(b);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}
