/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:38:18 by hujeong           #+#    #+#             */
/*   Updated: 2023/02/14 18:39:22 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include "push_swap.h"

void	ra(t_stack *a)
{
	if (a->top == a->bottom)
		return ;
	rotate(a);
	write(STDOUT_FILENO, "ra\n", 3);
}

void	rb(t_stack *b)
{
	if (b->top == b->bottom)
		return ;
	rotate(b);
	write(STDOUT_FILENO, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	write(STDOUT_FILENO, "rr\n", 3);
}
