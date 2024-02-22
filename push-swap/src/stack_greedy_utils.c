/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_greedy_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:27:22 by hujeong           #+#    #+#             */
/*   Updated: 2023/02/18 14:49:10 by hujeong          ###   ########.fr       */
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

static void	count_op2(t_node *top, t_node *bottom, t_node *node, t_count *count)
{
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
	count_op2(a->top, a->bottom, node, count);
	count_op_util(count, least);
}
