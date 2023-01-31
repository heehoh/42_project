/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:20:08 by hujeong           #+#    #+#             */
/*   Updated: 2023/01/31 14:20:38 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	creat_process(t_cmd *cmd, char **argv, char **env)
{
	pid_t	pid[2];
	int		fd[2];
	int		infile_fd;
	int		outfile_fd;

	open_file(&infile_fd, &outfile_fd, argv[1], argv[4]);
	if (pipe(fd) < 0)
		err_pipe();
	pid[0] = fork();
	if (pid[0] < 0)
		err_fork();
	else if (pid[0] == 0)
		process_before_pipe(&cmd[0], fd, infile_fd, env);
	pid[1] = fork();
	if (pid[1] < 0)
		err_pipe();
	else if (pid[1] == 0)
		process_after_pipe(&cmd[1], fd, outfile_fd, env);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid[1], NULL, 0);
	wait(NULL);
}

void	process_before_pipe(t_cmd *cmd, int *fd, int infile_fd, char **env)
{
	dup2(infile_fd, 0);
	dup2(fd[1], 1);
	close(infile_fd);
	close(fd[0]);
	close(fd[1]);
	if (execve(cmd->cmd, cmd->option, env) == -1)
		err_cmd(cmd->option[0]);
}

void	process_after_pipe(t_cmd *cmd, int *fd, int outfile_fd, char **env)
{
	dup2(fd[0], 0);
	dup2(outfile_fd, 1);
	close(fd[0]);
	close(fd[1]);
	close(outfile_fd);
	if (execve(cmd->cmd, cmd->option, env) == -1)
		err_cmd(cmd->option[0]);
}

void	open_file(int *infile_fd, int *outfile_fd, char *infile, char *outfile)
{
	*infile_fd = open(infile, O_RDONLY);
	if (*infile_fd < 0)
		err_open(infile);
	*outfile_fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*outfile_fd < 0)
		err_open(outfile);
}
