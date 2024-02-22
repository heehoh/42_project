/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:25:39 by hujeong           #+#    #+#             */
/*   Updated: 2022/10/15 10:10:49 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *a, char *b)
{
	while (*a || *b)
	{
		if (*a != *b)
			return (*a - *b);
		++a;
		++b;
	}
	return (0);
}

void	ft_print(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		while (*argv[i])
		{
			write(1, argv[i], 1);
			argv[i]++;
		}
		write (1, "\n", 1);
		++i;
	}
}

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	char	*a;

	if (argc <= 1)
		return (0);
	i = argc - 1;
	while (i > 1)
	{
		j = 1;
		while (j < i)
		{
			if (ft_strcmp(argv[j], argv[j + 1]) > 0)
			{
				a = argv[j];
				argv[j] = argv[j + 1];
				argv[j + 1] = a;
			}
			++j;
		}
		--i;
	}
	ft_print(argc, argv);
	return (0);
}
