/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:25:51 by hujeong           #+#    #+#             */
/*   Updated: 2023/02/18 15:33:21 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	hard_sort_case3(t_stack *a)
{
	t_node	*node;

	node = a->top;
	if (node->num < node->next->num)
	{
		if (a->bottom->num < node->num)
			rra(a);
		else if (a->bottom->num < node->next->num)
		{
			rra(a);
			sa(a);
		}
		return ;
	}
	if (node->next->num > a->bottom->num)
	{
		sa(a);
		rra(a);
	}
	else if (node->num < a->bottom->num)
		sa(a);
	else
		ra(a);
}

static void	hard_sort(t_stack *a, int count)
{
	if (count == 2)
		sa(a);
	else if (count == 3)
		hard_sort_case3(a);
	return ;
}

static void	push_stack_b(t_stack *a, t_stack *b, t_pivot *pivot)
{
	int	i;

	i = a->size;
	while (a->size > 3 && i--)
	{
		if (a->top->num < pivot->second)
		{
			pb(a, b);
			rb(b);
		}
		else if (a->top->num < pivot->third)
			pb(a, b);
		else
			ra(a);
	}
	while (a->size > 3)
		pb(a, b);
}

void	sort_stack(t_stack *a, t_stack *b, t_pivot *pivot)
{
	if (a->size <= 3)
	{
		hard_sort(a, a->size);
		return ;
	}
	push_stack_b(a, b, pivot);
	hard_sort_case3(a);
	greedy(a, b, pivot->third);
	greedy(a, b, pivot->second);
	greedy(a, b, pivot->first);
}
