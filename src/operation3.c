/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:28:35 by hujeong           #+#    #+#             */
/*   Updated: 2023/02/14 18:39:22 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
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
// checker 에서는 스택의 크기에 따라 명령이 수행될지 판단하는 if문이 필요하다 하지만 push-swap은 프로그램에서 알아서 그런 경우는 pa를 하지 않게 할 수 있음으로 방지 가능하다.