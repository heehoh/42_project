/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:39:21 by hujeong           #+#    #+#             */
/*   Updated: 2023/01/26 20:00:20 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_cmd
{
	char	**path;
	char	**option;
}	t_cmd;

char	**get_path(char **env);
void	set_cmd(t_cmd *cmd, char *cmd_options, char **path);
void	free_cmd(t_cmd *cmd);
void	process_before_pipe(t_cmd *cmd, pid_t *pid, char **env);
void	process_after_pipe(t_cmd *cmd, pid_t *pid, char **env);
void	free_path(char **path);
void	free_cmd(t_cmd *cmd);

#endif