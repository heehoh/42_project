/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:15:16 by hujeong           #+#    #+#             */
/*   Updated: 2023/02/12 17:37:18 by hujeong          ###   ########.fr       */
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

int	stack_empty_check(t_stack *stack)
{
	if (stack->top == NULL)
		return (1);
	return (0);
}

void	new_node(t_node *prev, int num)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	new->num = num;
	new->next = NULL;
	new->prev = prev;
}