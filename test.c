/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:50:55 by hujeong           #+#    #+#             */
/*   Updated: 2023/01/26 19:55:17 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp("PATH", env[i], 4) == 0)
			break ;
		++i;
	}
	return (env[i] + 5);
}

int	main(int argc, char **argv, char **env)
{
	char	*path;

	path = get_path(env);
	ft_printf("%s\n", path);
	return (0);
}
