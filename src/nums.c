/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nums.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:49:28 by hujeong           #+#    #+#             */
/*   Updated: 2023/02/15 14:36:33 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

char	*get_whole_arg(int argc, char *argv[])
{
	size_t	i;
	char	*tem;

	tem = ft_strdup(argv[1]);
	i = 1;
	while (++i < argc)
	{
		tem = ft_strjoin(tem, " ");
		tem = ft_strjoin(tem, argv[i]);
		if (tem == NULL)
			print_malloc_error();
	}
	i = 0;
	while (tem[i])
	{
		if (tem[i] >= 9 && tem[i] <= 13)
			tem[i] = ' ';
		else if (!(tem[i] == ' ' || (tem[i] >= '0' && tem[i] <= '9')))
		{
			free(tem);
			return (NULL);
		}
		++i;
	}
	return (tem);
}

char	**get_new_argv(int argc, char *argv[])
{
	size_t	i;
	char	*tem;
	char	**new_argv;

	tem = get_whole_arg(argc, argv);
	if (tem == NULL)
		print_error();
	new_argv = ft_split(tem, ' ');
	if (new_argv == NULL)
		print_malloc_error();
	free(tem);
	return (new_argv);
}

int	*get_nums(int argc, char *argv[], int *count)
{
	int			*nums;
	long long	num;
	int			i;
	char		**new_argv;

	new_argv = get_new_argv(argc, argv);
	while (new_argv[(*count)])
		++(*count);
	nums = (int *)malloc(sizeof(int) * (*count));
	if (nums == NULL)
		print_malloc_error();
	i = -1;
	while (new_argv[++i])
	{
		num = ft_atoll(new_argv[i]);
		if (num > INT32_MAX || num < INT32_MIN)
			print_error();
		nums[i] = num;
	}
	i = -1;
	while (new_argv[++i])
		free(new_argv[i]);
	free(new_argv);
	return (nums);
}
