/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:56:08 by hujeong           #+#    #+#             */
/*   Updated: 2023/02/18 17:58:51 by hujeong          ###   ########.fr       */
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
	if (ft_strncmp(op, "pa\n", 3) == 0)
		pa(a, b);
	else if (ft_strncmp(op, "pb\n", 3) == 0)
		pb(a, b);
	else if (ft_strncmp(op, "sa\n", 3) == 0)
		sa(a);
	else if (ft_strncmp(op, "sb\n", 3) == 0)
		sb(b);
	else if (ft_strncmp(op, "ss\n", 3) == 0)
		ss(a, b);
	else if (ft_strncmp(op, "ra\n", 3) == 0)
		ra(a);
	else if (ft_strncmp(op, "rb\n", 3) == 0)
		rb(b);
	else if (ft_strncmp(op, "rr\n", 3) == 0)
		rr(a, b);
	else if (ft_strncmp(op, "rra\n", 4) == 0)
		rra(a);
	else if (ft_strncmp(op, "rrb\n", 4) == 0)
		rrb(b);
	else if (ft_strncmp(op, "rrr\n", 4) == 0)
		rrr(a, b);
	else
		nope(a, b);
}
