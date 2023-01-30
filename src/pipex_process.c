/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:20:08 by hujeong           #+#    #+#             */
/*   Updated: 2023/01/30 16:36:40 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	creat_process(t_cmd *cmd, char **argv, char **env)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) < 0)
		err_pipe();
	pid = fork();
	if (pid < 0)
		err_fork();
	else if (pid == 0)
		process_before_pipe(&cmd[0], fd, argv[1], env);
	process_after_pipe(&cmd[1], fd, argv[4], env);
}

void	process_before_pipe(t_cmd *cmd, int *fd, char *infile, char **env)
{
	int	infile_fd;

	infile_fd = open(infile, O_RDONLY);
	if (infile_fd < 0)
		exit(EXIT_FAILURE);
	check_cmd(cmd);
	dup2(infile_fd, 0);
	dup2(fd[1], 1);
	close(infile_fd);
	close(fd[0]);
	close(fd[1]);
	if (execve(cmd->cmd, cmd->option, env) == -1)
		err_cmd(cmd->option[0]);
}

void	process_after_pipe(t_cmd *cmd, int *fd, char *outfile, char **env)
{
	int	outfile_fd;

	outfile_fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile_fd < 0)
		err_open(outfile);
	check_cmd(cmd);
	dup2(fd[0], 0);
	dup2(outfile_fd, 1);
	close(fd[0]);
	close(fd[1]);
	close(outfile_fd);
	if (execve(cmd->cmd, cmd->option, env) == -1)
		err_cmd(cmd->option[0]);
}
