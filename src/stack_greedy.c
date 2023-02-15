/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_greedy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:26:03 by hujeong           #+#    #+#             */
/*   Updated: 2023/02/15 17:00:17 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sum(t_count *s)
{
	return (s->ra + s->rb + s->rr + s->rra + s->rrb + s->rrr);
}

static void	count_op(t_stack *a, t_node *node, t_count *count, t_least *least)
{
	if (node->num < a->top->num)
	{
		if (node->num < a->bottom->num)
		{
			++i;
		}

	}
}

static void	operate(t_least *least)
{

}

void	greedy(t_stack *a, t_stack *b, int pivot)
{
	t_count	count;
	t_least	least;
	t_node	*node;
	int		rb;
	int		rrb;

	init_count(&count, &least);
	while (b->size && (b->top >= pivot || b->bottom >= pivot))
	{
		node = b->top;
		while (node->num >= pivot)
		{
			count_op(a, node, &count, &least);
			node = node->next;
			++count.rb;
		}
		node = b->bottom;
		count.rb = 0;
		while (node->num >= pivot)
		{
			count_op(a, b, &count, &least);
			node = node->prev;
		}
		operate(&least);
	}
	while (a->top->num != pivot)
		rra(a);
}
