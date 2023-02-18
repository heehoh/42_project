/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:56:08 by hujeong           #+#    #+#             */
/*   Updated: 2023/02/18 17:32:11 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap_bonus.h"

void	nope(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
	print_error();
}

void	sort_stack(t_stack *a, t_stack *b, char *op)
{
	if (ft_strncmp(op, "pa", 2) == 0)
		pa(a, b);
	else if (ft_strncmp(op, "pb", 2) == 0)
		pb(a, b);
	else if (ft_strncmp(op, "sa", 2) == 0)
		sa(a);
	else if (ft_strncmp(op, "sb", 2) == 0)
		sb(b);
	else if (ft_strncmp(op, "ss", 2) == 0)
		ss(a, b);
	else if (ft_strncmp(op, "ra", 2) == 0)
		ra(a);
	else if (ft_strncmp(op, "rb", 2) == 0)
		rb(b);
	else if (ft_strncmp(op, "rr", 2) == 0)
		rr(a, b);
	else if (ft_strncmp(op, "rra", 3) == 0)
		rra(a);
	else if (ft_strncmp(op, "rrb", 3) == 0)
		rrb(b);
	else if (ft_strncmp(op, "rrr", 3) == 0)
		rrr(a, b);
	else
		nope(a, b);
}
