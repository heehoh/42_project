/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:23:37 by hujeong           #+#    #+#             */
/*   Updated: 2023/02/18 17:50:42 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "../libft/libft.h"
#include <unistd.h>

static int	is_sorted(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (b->top != (t_node *)0)
		return (0);
	node = a->top;
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
	t_stack	a;
	t_stack	b;
	char	*op;

	if (argc == 1)
		return (0);
	set_stack(&a, &b, argv);
	op = get_next_line(0);
	while (op)
	{
		sort_stack(&a, &b, op);
		op = get_next_line(0);
	}
	if (is_sorted(&a, &b))
		write(STDOUT_FILENO, "OK\n", 3);
	else
		write(STDOUT_FILENO, "KO\n", 3);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
