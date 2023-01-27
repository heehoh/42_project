/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:50:55 by hujeong           #+#    #+#             */
/*   Updated: 2023/01/27 20:21:01 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_cmd(t_cmd *cmd)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 2)
	{
		j = -1;
		while (cmd[i].path[++j])
		{
			free(cmd[i].path[j]);
			cmd[i].path[j] = NULL;
		}
		free(cmd[i].path);
		cmd[i].path = NULL;
		j = -1;
		while (cmd[i].option[++j])
		{
			free(cmd[i].option[j]);
			cmd[i].option[j] = NULL;
		}
		free(cmd[i].option);
		cmd[i].option = NULL;
	}
}

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
		cmd->path[i] = ft_strjoin(path[i], cmd_without_path);
		++i;
	}
	cmd->path[i] = NULL;
	free(cmd_without_path);
}

int	main(int argc, char **argv, char **env)
{
	t_cmd	cmd[2];
	char	**path;
	int		i;
	int		j;

	path = get_path(env);
	i = -1;
	while (path[++i])
		ft_printf("%s\n", path[i]);
	i = -1;
	while (++i < 2)
		set_cmd(&cmd[i], "cmd 'hi ho' ll", path);
	i = -1;
	while (++i < 2)
	{
		j = -1;
		while (cmd[i].path[++j])
			ft_printf("cmd option %d : %s\n", i, cmd[i].path[j]);
		j = -1;
		while (cmd[i].option[++j])
			ft_printf("cmd option %d : %s\n", i, cmd[i].option[j]);
	}
	free_path(path);
	free_cmd(cmd);
	system("leaks a.out");
	return (0);
}

void	free_path(char **path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		free(path[i]);
		path[i] = NULL;
		++i;
	}
	free(path);
	path = NULL;
}
