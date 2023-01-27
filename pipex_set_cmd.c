/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_set_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:19:30 by hujeong           #+#    #+#             */
/*   Updated: 2023/01/27 20:22:21 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(char **env)
{
	char	**path;
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp("PATH", env[i], 4) == 0)
			break ;
		++i;
	}
	path = ft_split(env[i] + 5, ':');
	return (path);
}

void	set_cmd(t_cmd *cmd, char *cmd_options, char **path)
{
	char	*cmd_without_path;
	int		i;

	cmd->option = ft_split(cmd_options, ' ');
	if (cmd->option == NULL)
		perror("ft_split fail");
	cmd_without_path = ft_strjoin("/", cmd->option[0]);
	i = 0;
	while (path[i])
		++i;
	cmd->path = (char **)malloc(sizeof(char *) * (i + 1));
	if (cmd->path == NULL)
		perror("malloc fail");
	i = 0;
	while (path[i])
	{
		cmd->path[i] = ft_strjoin(cmd_without_path, path[i]);
		++i;
	}
	cmd->path[i] = NULL;
	free(cmd_without_path);
}
