/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:22:03 by hujeong           #+#    #+#             */
/*   Updated: 2023/02/13 13:53:12 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>
#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	push(a, pop(b));
	write(STDOUT_FILENO, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	push(b, pop(a));
	write(STDOUT_FILENO, "pb\n", 3);
}

void	sa(t_stack *a)
{
	swap(a);
	write(STDOUT_FILENO, "sa\n", 3);
}

void	sb(t_stack *b)
{
	swap(b);
	write(STDOUT_FILENO, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	write(STDOUT_FILENO, "ss\n", 3);
}
