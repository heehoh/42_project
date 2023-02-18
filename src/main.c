/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:53:45 by hujeong           #+#    #+#             */
/*   Updated: 2023/02/18 22:46:11 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	is_sorted(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	while (node->next)
	{
		if (node->num > node->next->num)
			return (0);
		node = node->next;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int		*nums;
	int		count;
	t_stack	a;
	t_stack	b;
	t_pivot	pivot;

	if (argc == 1)
		return (0);
	count = 0;
	nums = get_nums(argv, &count);
	set_stack(&a, &b, nums, count);
	if (is_sorted(&a))
	{
		free(nums);
		free_stack(&a);
		return (0);
	}
	get_pivot(nums, count, &pivot);
	sort_stack(&a, &b, &pivot);
	free_stack(&a);
	return (0);
}
