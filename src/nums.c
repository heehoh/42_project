/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nums.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:49:28 by hujeong           #+#    #+#             */
/*   Updated: 2023/02/14 15:07:42 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

char	**get_new_argv(int argc, char *argv[])
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

int	*get_nums(int argc, char *argv[], int *count)
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

void	sort_nums(int *nums, int count)
{
	int	i;
	int	j;
	int	tem;

	i = -1;
	while (++i < count - 1)
	{
		j = -1;
		while (++j < (count - i - 1))
		{
			if (nums[j] > nums[j + 1])
			{
				tem = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = tem;
			}
		}
	}
	i = -1;
	while (++i < count - 1)
		if (nums[i] == nums[i + 1])
			print_error();
}
