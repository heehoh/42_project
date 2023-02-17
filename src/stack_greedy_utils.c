/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_greedy_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:27:22 by hujeong           #+#    #+#             */
/*   Updated: 2023/02/18 01:13:28 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sum(t_count *s)
{
	return (s->ra + s->rb + s->rr + s->rra + s->rrb + s->rrr);
}

void	init_count(t_count *count, int rb, int rrb)
{
	count->ra = 0;
	count->rb = rb;
	count->rr = 0;
	count->rra = 0;
	count->rrb = rrb;
	count->rrr = 0;
}

static void	count_op_util(t_count *count, t_count *least)
{
	while (count->ra > 0 && count->rb > 0)
	{
		++(count->rr);
		--(count->ra);
		--(count->rb);
	}
	while (count->rra > 0 && count->rrb > 0)
	{
		++(count->rrr);
		--(count->rra);
		--(count->rrb);
	}
	if (sum(count) < sum(least))
		*least = *count;
}

void	count_op(t_stack *a, t_node *node, t_count *count, t_count *least)
{
	t_node	*top;
	t_node	*bottom;

	top = a->top;
	bottom = a->bottom;
	if (top->num < node->num)
	{
		while (top && top->num < node->num)
		{
			++(count->ra);
			if (top->next && top->num > top->next->num)
				break ;
			top = top->next;
		}
		if (top == (t_node *)0)
			count->ra = 0;
	}
	else
	{
		while (bottom && bottom->num > node->num)
		{
			++(count->rra);
			if (bottom->prev && bottom->prev->num > bottom->num)
				break ;
			bottom = bottom->prev;
		}
		if (bottom == (t_node *)0)
			count->rra = 0;
	}
	count_op_util(count, least);
}

void	operate(t_stack *a, t_stack *b, t_count *least)
{
	while ((least->rrr)-- > 0)
		rrr(a, b);
	while ((least->rra)-- > 0)
		rra(a);
	while ((least->rrb)-- > 0)
		rrb(b);
	while ((least->rr)-- > 0)
		rr(a, b);
	while ((least->ra)-- > 0)
		ra(a);
	while ((least->rb)-- > 0)
		rb(b);
	pa(a, b);
}
