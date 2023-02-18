/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:22:03 by hujeong           #+#    #+#             */
/*   Updated: 2023/02/18 17:27:00 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pa(t_stack *a, t_stack *b)
{
	if (b->size > 0)
		push(a, pop(b));
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->size > 0)
		push(b, pop(a));
}

void	sa(t_stack *a)
{
	if (a->size >= 2)
		swap(a);
}

void	sb(t_stack *b)
{
	if (b->size >= 2)
		swap(b);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}
