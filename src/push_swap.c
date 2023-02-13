/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:53:45 by hujeong           #+#    #+#             */
/*   Updated: 2023/02/13 17:39:16 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*nums;
	int		count;
	t_stack	a;
	t_stack	b;

	if (argc == 1)
		return (0);
	count = 0;
	stack_init(&a, &b);
	nums = get_nums(argc, argv, &count);
	if (count == 1)
		return (0);
	set_stack(&a, nums, count);
	sort_nums(nums, count);
	sort_stack(&a, &b, nums, count);
	return (0);
}

int	*get_nums(int argc, char **argv, int *count)
{
	int		*nums;
	int		i;
	char	**new_argv;

	new_argv = get_new_argv(argc, argv);
	while (new_argv[(*count)])
		++(*count);
	nums = (int *)malloc(sizeof(int) * (*count));
	i = -1;
	while (new_argv[++i])
		nums[i] = ft_atoi(new_argv[i]);
	i = -1;
	while (new_argv[++i])
		free(new_argv[i]);
	free(new_argv);
	return (nums);
}

char	**get_new_argv(int argc, char **argv)
{
	size_t	i;
	char	*tem;
	char	**new_argv;

	tem = ft_strdup(argv[1]);
	i = 1;
	while (++i < argc)
	{
		tem = ft_strjoin(tem, " ");
		tem = ft_strjoin(tem, argv[i]);
	}
	i = 0;
	while (tem[i])
	{
		if (tem[i] >= 9 && tem[i] <= 13)
			tem[i] = ' ';
		++i;
	}
	new_argv = ft_split(tem, ' ');
	free(tem);
	return (new_argv);
}

void	set_stack(t_stack *stack, int *nums, int count)
{
	int	i;

	i = -1;
	while (++i < count)
		push(stack, new_node(nums[i]));
}

void	sort_nums(int *nums, int count)
{
	int	i;
	int	j;
	int	tem;

	i = 0;
	while (i < count - 1)
	{
		j = 0;
		while (j < (count - i - 1))
		{
			if (nums[j] > nums[j + 1])
			{
				tem = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = tem;
			}
			++j;
		}
		++i;
	}
}
