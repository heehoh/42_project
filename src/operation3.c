/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:28:35 by hujeong           #+#    #+#             */
/*   Updated: 2023/02/18 14:34:39 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

void	rra(t_stack *a)
{
	reverse_rotate(a);
	write(STDOUT_FILENO, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	reverse_rotate(b);
	write(STDOUT_FILENO, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(STDOUT_FILENO, "rrr\n", 4);
}
