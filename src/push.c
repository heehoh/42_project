/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:22:03 by hujeong           #+#    #+#             */
/*   Updated: 2023/02/12 17:37:18 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>
#include "push_swap.h"

void	push(t_stack *from, t_stack *to)
{
	t_node	*tem;

	if (from->top == NULL)
		return ;
	tem = from->top->next;
	from->top->next = to->top;
	to->top = from->top;
	from->top = tem;
}

void	pa(t_stack *a, t_stack *b)
{
	push(b, a);
	write(STDOUT_FILENO, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	push(a, b);
	write(STDOUT_FILENO, "pb\n", 3);
}
