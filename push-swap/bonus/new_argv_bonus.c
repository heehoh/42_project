/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_argv_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:49:28 by hujeong           #+#    #+#             */
/*   Updated: 2023/02/26 17:20:14 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap_bonus.h"

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
		while (argv[i][++j])
		{
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
				number_flag = 1;
			else if (!(argv[i][j] == ' '
				|| (argv[i][j] == '-') || argv[i][j] == '+'))
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

char	**get_new_argv(char *argv[])
{
	char	*tem;
	char	**new_argv;

	check_argv(argv);
	tem = get_whole_arg(argv);
	if (tem == NULL)
		print_error();
	new_argv = ft_split(tem, ' ');
	free(tem);
	if (new_argv == NULL)
		print_malloc_error();
	if (new_argv[0] == NULL)
	{
		free(new_argv);
		print_error();
	}
	return (new_argv);
}

void	free_new_argv(char **new_argv)
{
	int	i;

	i = -1;
	while (new_argv[++i])
		free(new_argv[i]);
	free(new_argv);
}
