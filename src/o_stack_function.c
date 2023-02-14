/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_stack_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:15:16 by hujeong           #+#    #+#             */
/*   Updated: 2023/02/14 18:39:22 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void	set_stack(t_stack *a, t_stack *b, int nums[], int count)
{
	a->top = NULL;
	a->bottom = NULL;
	a->size = 0;
	b->top = NULL;
	b->bottom = NULL;
	b->size = 0;
	while (--count >= 0)
		push(a, new_node(nums[count]));
}

void	push(t_stack *stack, t_node *new)
{
	if (stack->size == 0)
	{
		stack->bottom = new;
		stack->top = new;
		++(stack->size);
		return ;
	}
	new->next = stack->top;
	stack->top->prev = new;
	stack->top = new;
	++(stack->size);
}

t_node	*pop(t_stack *stack)
{
	t_node	*node;

	if (stack->size == 1)
		stack->bottom = NULL;
	node = stack->top;
	stack->top = stack->top->next;
	stack->top->prev = NULL;
	node->next = NULL;
	--(stack->size);
	return (node);
}

t_node	*new_node(int num)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	new->num = num;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
