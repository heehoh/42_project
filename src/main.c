/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:53:45 by hujeong           #+#    #+#             */
/*   Updated: 2023/02/15 14:39:08 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

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
	nums = get_nums(argc, argv, &count);
	if (count == 1)
		return (0);
	set_stack(&a, &b, nums, count);
	get_pivot(nums, count, &pivot);
	sort_stack(&a, &b, &pivot);
	return (0);
}

void	print_malloc_error(void)
{
	write(STDERR_FILENO, "malloc fail\n", 12);
	exit(EXIT_FAILURE);
}

void	print_error(void)
{
	write(STDERR_FILENO, "error\n", 6);
	exit(EXIT_FAILURE);
}
