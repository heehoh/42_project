/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:15:16 by hujeong           #+#    #+#             */
/*   Updated: 2023/02/13 14:49:52 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

void	stack_init(t_stack *a, t_stack *b)
{
	a->top = NULL;
	a->bottom = NULL;
	b->top = NULL;
	b->bottom = NULL;
}

void	push(t_stack *stack, t_node *new)
{
	if (stack->top == NULL)
		stack->bottom = new;
	new->next = stack->top;
	stack->top->prev = new;
	stack->top = new;
}

t_node	*pop(t_stack *stack)
{
	t_node	*node;

	if (stack->top == stack->bottom)
		stack->bottom = NULL;
	node = stack->top;
	stack->top = stack->top->next;
	stack->top->prev = NULL;
	node->next = NULL;
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

void	swap(t_stack *stack)
{
	t_node	*node1;
	t_node	*node2;

	if (stack->top == NULL || stack->top->next == NULL)
		return ;
	node1 = pop(stack);
	node2 = pop(stack);
	node1->prev = node2;
	node1->next = stack->top;
	node2->next = node1;
	stack->top = node2;
}
