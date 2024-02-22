/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:15:16 by hujeong           #+#    #+#             */
/*   Updated: 2023/02/18 15:32:39 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

static t_node	*new_node(int num)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (new == NULL)
		print_malloc_error();
	new->num = num;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

static int	check_dup_num(t_stack *a, int num)
{
	t_node	*node;

	node = a->top;
	while (node != NULL)
	{
		if (node->num == num)
			return (1);
		node = node->next;
	}
	return (0);
}

void	free_stack(t_stack *stack)
{
	t_node	*tem;

	while (stack->top)
	{
		tem = stack->top->next;
		free(stack->top);
		stack->top = tem;
	}
}

void	set_stack(t_stack *a, t_stack *b, int nums[], int count)
{
	a->top = NULL;
	a->bottom = NULL;
	a->size = 0;
	b->top = NULL;
	b->bottom = NULL;
	b->size = 0;
	while (--count >= 0)
	{
		if (check_dup_num(a, nums[count]))
		{
			free(nums);
			free_stack(a);
			print_error();
		}
		push(a, new_node(nums[count]));
	}
}

void	get_pivot(int *nums, int count, t_pivot *pivot)
{
	int	i;
	int	j;
	int	tem;

	i = -1;
	while (++i < count - 1)
	{
		j = -1;
		while (++j < (count - i - 1))
		{
			if (nums[j] > nums[j + 1])
			{
				tem = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = tem;
			}
		}
	}
	pivot->first = nums[0];
	pivot->second = nums[count / 3];
	pivot->third = nums[count / 3 * 2];
	free(nums);
}
