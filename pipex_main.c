/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:06:27 by hujeong           #+#    #+#             */
/*   Updated: 2023/01/26 19:57:25 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_cmd	cmd[2];
	pid_t	pid[2];
	int		fd[2];
	int		status[2];
	char	**path;

	path = get_path(env);
	set_cmd(&cmd[0], argv[2], path);
	set_cmd(&cmd[1], argv[3], path);
	pipe(fd);
	pid[0] = fork();
	if (pid[0] == 0)
		process_before_pipe(&cmd[0], fd, env);
	pid[1] = fork();
	if (pid[1] == 0)
		process_after_pipe(&cmd[1], fd, env);
	waitpid(pid[0], &status[0], NULL);
	waitpid(pid[1], &status[1], NULL);
	free_path(path);
	free_cmd(&cmd[0]);
	free_cmd(&cmd[1]);
	return (0);
}
