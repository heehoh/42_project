/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nums.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:49:28 by hujeong           #+#    #+#             */
/*   Updated: 2023/02/18 14:19:42 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

static char	*get_whole_arg(char *argv[])
{
	size_t	i;
	char	*tem;

	i = 1;
	tem = ft_strdup(argv[1]);
	while (argv[++i])
	{
		tem = ft_strjoin(ft_strjoin(tem, " "), argv[i]);
		if (tem == NULL)
			print_malloc_error();
	}
	i = 0;
	while (tem[i])
	{
		if (tem[i] >= 9 && tem[i] <= 13)
			tem[i] = ' ';
		else if (!(tem[i] == ' ' || (tem[i] >= '0' && tem[i] <= '9')
				|| (tem[i] == '-') || tem[i] == '+'))
		{
			free(tem);
			return (NULL);
		}
		++i;
	}
	return (tem);
}

static char	**get_new_argv(char *argv[])
{
	char	*tem;
	char	**new_argv;
	int		i;

	i = 0;
	while (argv[++i])
	{
		if (argv[i][0] == '\0')
			print_error();
	}
	tem = get_whole_arg(argv);
	if (tem == NULL)
		print_error();
	new_argv = ft_split(tem, ' ');
	free(tem);
	if (new_argv == NULL)
		print_malloc_error();
	return (new_argv);
}

static void	free_new_argv(char **new_argv)
{
	int	i;

	i = -1;
	while (new_argv[++i])
		free(new_argv[i]);
	free(new_argv);
}

int	*get_nums(char *argv[], int *count)
{
	int			*nums;
	long long	num;
	int			i;
	char		**new_argv;

	new_argv = get_new_argv(argv);
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
		{
			free(nums);
			free_new_argv(new_argv);
			print_error();
		}
		nums[i] = num;
	}
	free_new_argv(new_argv);
	return (nums);
}
