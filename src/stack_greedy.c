/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_greedy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:26:03 by hujeong           #+#    #+#             */
/*   Updated: 2023/02/16 16:21:02 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sum(t_count *s)
{
	return (s->ra + s->rb + s->rr + s->rra + s->rrb + s->rrr);
}

static void	init_count(t_count *count, int rb, int rrb)
{
	count->ra = 0;
	count->rb = rb;
	count->rr = 0;
	count->rra = 0;
	count->rrb = rrb;
	count->rrr = 0;
}

static void	count_op(t_stack *a, t_node *node, t_count *count, t_count *least)
{
	t_node	*search;

	if (node->num < a->top->num)
	{
		search = a->bottom;
		while (node->num < search->num)
		{
			++(count->rra);
			search = search->prev;
		}
		while (count->rra > 0 && count->rrb > 0)
		{
			++(count->rrr);
			--(count->rra);
			--(count->rrb);
		}
	}
	else
	{
		search = a->top;
		while (node->num > search->num)
		{
			++(count->ra);
			search = search->next;
		}
		while (count->ra > 0 && count->rb > 0)
		{
			++(count->rr);
			--(count->ra);
			--(count->rb);
		}
	}
	if (sum(least) == 0 || sum(count) < sum(least))
		*least = *count;
}

static void	operate(t_stack *a, t_stack *b, t_count *least)
{
	while ((least->rrr)--)
		rrr(a, b);
	while ((least->rra)--)
		rra(a);
	while ((least->rrb)--)
		rrb(b);
	while ((least->rr)--)
		rr(a, b);
	while ((least->ra)--)
		ra(a);
	while ((least->rb)--)
		rb(b);
	pa(a, b);
}

void	greedy(t_stack *a, t_stack *b, int pivot)
{
	t_count	count;
	t_count	least;
	t_node	*node;
	int		rotate;

	while (b->size && (b->top->num >= pivot || b->bottom->num >= pivot))
	{
		init_count(&least, 0, 0);
		node = b->top;
		rotate = 0;
		while (node->num >= pivot)
		{
			init_count(&count, rotate, 0);
			count_op(a, node, &count, &least);
			node = node->next;
			++rotate;
		}
		node = b->bottom;
		rotate = 1;
		while (node->num >= pivot)
		{
			init_count(&count, 0, rotate);
			count_op(a, node, &count, &least);
			node = node->prev;
			++rotate;
		}
		operate(a, b, &least);
	}
	while (a->top->num != pivot)
		rra(a);
}
