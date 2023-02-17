/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:53:22 by hujeong           #+#    #+#             */
/*   Updated: 2023/02/17 11:43:37 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "push_swap.h"

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
	if (stack->top != NULL)
		stack->top->prev = NULL;
	node->next = NULL;
	--(stack->size);
	return (node);
}

void	swap(t_stack *stack)
{
	t_node	*node1;
	t_node	*node2;

	if (stack->top == NULL || stack->top->next == NULL)
		return ;
	node1 = pop(stack);
	node2 = pop(stack);
	push(stack, node1);
	push(stack, node2);
}

void	rotate(t_stack *stack)
{
	t_node	*node;

	if (stack->top == stack->bottom)
		return ;
	node = pop(stack);
	++(stack->size);
	stack->bottom->next = node;
	node->prev = stack->bottom;
	stack->bottom = node;
}

void	reverse_rotate(t_stack *stack)
{
	t_node	*node;

	if (stack->top == stack->bottom)
		return ;
	node = stack->bottom;
	stack->bottom = stack->bottom->prev;
	stack->bottom->next = NULL;
	node->next = stack->top;
	node->prev = NULL;
	stack->top->prev = node;
	stack->top = node;
}
