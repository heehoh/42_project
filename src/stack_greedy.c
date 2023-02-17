/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_greedy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:26:03 by hujeong           #+#    #+#             */
/*   Updated: 2023/02/17 18:02:57 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	greedy(t_stack *a, t_stack *b, int pivot)
{
	t_count	count;
	t_count	least;
	t_node	*node;
	int		rotate;

	while (b->size && (b->top->num >= pivot || b->bottom->num >= pivot))
	{
		init_count(&least, 2147483647, 0);
		node = b->top;
		rotate = 0;
		while (node && node->num >= pivot)
		{
			init_count(&count, rotate, 0);
			count_op(a, node, &count, &least);
			node = node->next;
			++rotate;
		}
		node = b->bottom;
		rotate = 1;
		while (node && node->num >= pivot)
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
