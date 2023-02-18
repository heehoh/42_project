/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_greedy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:26:03 by hujeong           #+#    #+#             */
/*   Updated: 2023/02/18 23:33:11 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	compare_size(int *size1, int *size2, t_stack *a)
{
	t_node	*node;

	*size1 = 0;
	*size2 = 0;
	node = a->top;
	while (node->next && node->num < node->next->num)
	{
		++(*size1);
		node = node->next;
	}
	node = a->bottom;
	while (node->prev && node->num > node->prev->num)
	{
		++(*size2);
		node = node->prev;
	}
}

static void	rotation_a(t_stack *a, int pivot)
{
	int		size1;
	int		size2;

	compare_size(&size1, &size2, a);
	if (size1 > size2)
	{
		while (a->top->num != pivot)
			rra(a);
	}
	else
	{
		while (a->top->num != pivot)
			ra(a);
	}
}

static void	get_least_op(t_count *least, t_stack *a, t_stack *b, int pivot)
{
	t_count	count;
	t_node	*node;
	int		rotate;

	node = b->top;
	rotate = 0;
	while (node && node->num >= pivot)
	{
		init_count(&count, rotate, 0);
		count_op(a, node, &count, least);
		node = node->next;
		++rotate;
	}
	node = b->bottom;
	rotate = 1;
	while (node && node->num >= pivot)
	{
		init_count(&count, 0, rotate);
		count_op(a, node, &count, least);
		node = node->prev;
		++rotate;
	}
}

static void	operate(t_stack *a, t_stack *b, t_count *least)
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

void	greedy(t_stack *a, t_stack *b, int pivot)
{
	t_count	least;

	while (b->size && (b->top->num >= pivot || b->bottom->num >= pivot))
	{
		init_count(&least, 2147483647, 0);
		get_least_op(&least, a, b, pivot);
		operate(a, b, &least);
	}
	if (is_sorted(a))
		return ;
	rotation_a(a, pivot);
}
