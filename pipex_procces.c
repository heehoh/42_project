/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_procces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:20:08 by hujeong           #+#    #+#             */
/*   Updated: 2023/01/27 20:37:14 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	creat_proccess(t_cmd *cmd, char **argv, char **env)
{
	pid_t	pid;
	int		fd[2];
	int		status;

	pipe(fd);
	pid = fork();
	if (pid < 0)
		perror("fork fail");
	else if (pid == 0)
	{
		pid = fork();
		if (pid < 0)
			perror("fork fail");
		else if (pid == 0)
			process_before_pipe(&cmd[0], fd, argv[1], env);
		process_after_pipe(&cmd[1], fd, argv[4], env);
	}
	waitpid(pid, &status, NULL);
}

void	process_before_pipe(t_cmd *cmd, int *fd, char *infile, char **env)
{

}

void	process_after_pipe(t_cmd *cmd, int *fd, char *outfile, char **env)
{

}
