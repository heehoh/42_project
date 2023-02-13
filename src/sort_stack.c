/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:25:51 by hujeong           #+#    #+#             */
/*   Updated: 2023/02/13 17:38:30 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "push_swap.h"

void	sort_stack(t_stack *a, t_stack *b, int *nums, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (a->top < nums[count / 3])
		{
			pb(a, b);
			rb(b);
		}
		else if (a->top >= nums[(count / 3) * 2])
			ra(a);
		else
			pb(a, b);
		++i;
	}
	while (a->top == NULL)
	{
		pb(a, b);
	}
	greedy(a, b, nums, count);
}

void	greedy(t_stack *a, t_stack *b, int *nums, int count)
{
}

void	select_set_operation(t_option *option)
{
	
}