/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:53:45 by hujeong           #+#    #+#             */
/*   Updated: 2023/02/14 14:53:15 by hujeong          ###   ########.fr       */
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

	if (argc == 1)
		return (0);
	count = 0;
	nums = get_nums(argc, argv, &count);
	if (count == 1)
		return (0);
	set_stack(&a, &b, nums, count);
	sort_nums(nums, count);
	sort_stack(&a, &b, nums, count);
	return (0);
}
