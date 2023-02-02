/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_set_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:19:30 by hujeong           #+#    #+#             */
/*   Updated: 2023/02/02 15:06:26 by hujeong          ###   ########.fr       */
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
		if (ft_strncmp("PATH=", env[i], 5) == 0)
			break ;
		++i;
	}
	if (env[i] == NULL)
		exit(EXIT_FAILURE);
	path = ft_split(env[i] + 5, ':');
	return (path);
}

void	set_cmd(t_cmd *cmd, char *cmd_options, char **path)
{
	char	*cmd_without_path;
	int		i;

	cmd->option = ft_split(cmd_options, ' ');
	if (cmd->option[0][0] == '/')
	{
		cmd->path = (char **)malloc(sizeof(char *) * 2);
		cmd->path[0] = ft_strdup(cmd->option[0]);
		cmd->path[1] = NULL;
		return ;
	}
	cmd_without_path = ft_strjoin("/", cmd->option[0]);
	i = 0;
	while (path[i])
		++i;
	cmd->path = (char **)malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (path[++i])
		cmd->path[i] = ft_strjoin(path[i], cmd_without_path);
	cmd->path[i] = NULL;
	free(cmd_without_path);
}

void	check_cmd(t_cmd *cmd)
{
	int	i;

	i = -1;
	while (cmd->path[++i])
		if (access(cmd->path[i], F_OK) == 0)
			break ;
	if (cmd->path[i] == NULL)
		err_cmd(cmd->option[0]);
	else
		cmd->cmd = cmd->path[i];
}
