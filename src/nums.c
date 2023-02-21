/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nums.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:49:28 by hujeong           #+#    #+#             */
/*   Updated: 2023/02/19 15:37:13 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

static void	check_argv(char *argv[])
{
	int		i;
	int		j;
	int		number_flag;

	i = 1;
	while (argv[i])
	{
		j = -1;
		number_flag = 0;
		while(argv[i][++j])
		{
			if  (argv[i][j] >= '0' && argv[i][j] <= '9')
				number_flag = 1;
			else if (!(argv[i][j] == ' ' || (argv[i][j] == '-') || argv[i][j] == '+'))
				print_error();
		}
		if (number_flag == 0)
			print_error();
		++i;
	}
}

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

	check_argv(argv);
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
		if (num > 2147483647LL || num < -2147483648LL)
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
