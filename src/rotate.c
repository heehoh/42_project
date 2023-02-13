/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:38:18 by hujeong           #+#    #+#             */
/*   Updated: 2023/02/13 16:07:56 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include "push_swap.h"

void	rotate(t_stack *stack)
{
	t_node	*node;

	if (stack->top == stack->bottom)
		return ;
	node = pop(stack);
	stack->bottom->next = node;
	node->prev = stack->bottom;
	stack->bottom = node;
}

void	ra(t_stack *a)
{
	rotate(a);
	write(STDOUT_FILENO, "ra\n", 3);
}

void	rb(t_stack *b)
{
	rotate(b);
	write(STDOUT_FILENO, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	write(STDOUT_FILENO, "rr\n", 3);
}
