/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:25:51 by hujeong           #+#    #+#             */
/*   Updated: 2023/02/16 20:09:08 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
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

static void	hard_sort_case4(t_stack *a, t_stack *b)
{
	int	i;

	pb(a, b);
	hard_sort_case3(a);
	i = 0;
	while (a->bottom->num > b->top->num && i < 3)
	{
		rra(a);
		++i;
	}
	pa(a, b);
	while (!(is_sorted(a)))
		rra(a);

}

static void	hard_sort_case5(t_stack *a, t_stack *b)
{
	int	i;

	pb(a, b);
	pb(a, b);
	hard_sort_case3(a);
	if (b->top->num < b->bottom->num)
		sb(b);
	i = 0;
	while (b->size)
	{
		if (a->bottom->num > b->top->num && i < 3)
		{
			rra(a);
			++i;
		}
		else
			pa(a, b);
	}
	while (!(is_sorted(a)))
		rra(a);

}

static void	hard_sort(t_stack *a, t_stack *b, int count)
{
	if (count == 2)
		sa(a);
	else if (count == 3)
		hard_sort_case3(a);
	else if (count == 4)
		hard_sort_case4(a, b);
	else
		hard_sort_case5(a, b);
	return ;
}

void	sort_stack(t_stack *a, t_stack *b, t_pivot *pivot)
{
	if (a->size <= 5)
	{
		hard_sort(a, b, a->size);
		return ;
	}
	while (a->size > 0)
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
	hard_sort_case3(a);
	greedy(a, b, pivot->third);
	greedy(a, b, pivot->second);
	greedy(a, b, pivot->first);
}
