/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:41:06 by hujeong           #+#    #+#             */
/*   Updated: 2023/02/18 17:55:09 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "../libft/libft.h"

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

static void	default_stack(t_stack *a, t_stack *b)
{
	a->top = NULL;
	a->bottom = NULL;
	a->size = 0;
	b->top = NULL;
	b->bottom = NULL;
	b->size = 0;
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

void	set_stack(t_stack *a, t_stack *b, char *argv[])
{
	long long	num;
	int			i;
	char		**new_argv;

	new_argv = get_new_argv(argv);
	default_stack(a, b);
	i = -1;
	while (new_argv[++i])
		;
	while (--i >= 0)
	{
		num = ft_atoll(new_argv[i]);
		if (check_dup_num(a, num) || num > 2147483647LL || num < -2147483648LL)
		{
			free_new_argv(new_argv);
			free_stack(a);
			print_error();
		}
		push(a, new_node(num));
	}
	free_new_argv(new_argv);
}
