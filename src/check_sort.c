/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:20:43 by hujeong           #+#    #+#             */
/*   Updated: 2023/02/14 15:30:34 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	print_sort(t_stack *a, t_stack *b)
{
	t_node	*node;

	while (a->size != 0)
	{
		node = pop(a);
		printf("%d ", node->num);
		free(node);
	}
	printf("\n");
	if (b->size == 0)
		printf("complite\n");
}
