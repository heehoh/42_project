/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_procces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:20:08 by hujeong           #+#    #+#             */
/*   Updated: 2023/01/27 21:04:24 by hujeong          ###   ########.fr       */
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
	int	infile_fd;
	int	i;

	infile_fd = open(infile, O_RDONLY);
	if (infile_fd < 0)
		perror(infile);
	dup2(infile_fd, 0);
	dup2(fd[1], 1);
	close(infile_fd);
	close(fd[0]);
	close(fd[1]);
	if (execve(cmd->cmd, cmd->option, env) == -1)
		perror("execve");
}

void	process_after_pipe(t_cmd *cmd, int *fd, char *outfile, char **env)
{
	int	outfile_fd;
	int	i;

	outfile_fd = open(outfile, O_WRONLY);
	if (outfile_fd < 0)
		perror(outfile);
	dup2(fd[0], 0);
	dup2(outfile_fd, 1);
	close(fd[0]);
	close(fd[1]);
	close(outfile_fd);
	if (execve(cmd->cmd, cmd->option, env) == -1)
		perror("execve");
}
