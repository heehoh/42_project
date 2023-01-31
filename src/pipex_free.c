/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:57:47 by hujeong           #+#    #+#             */
/*   Updated: 2023/01/31 12:29:51 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
}

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
		cmd[i].cmd = NULL;
	}
}
