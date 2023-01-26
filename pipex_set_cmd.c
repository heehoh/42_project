/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_set_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:19:30 by hujeong           #+#    #+#             */
/*   Updated: 2023/01/26 20:00:39 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(char **env)
{
	char	*path;
	char	**paths;
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

void	set_cmd(t_cmd *cmd, char *cmd_options, char **path)
{

}

void	free_cmd(t_cmd *cmd)
{}