/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:39:21 by hujeong           #+#    #+#             */
/*   Updated: 2023/02/02 12:01:24 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <sys/wait.h>
# include "../libft/libft.h"

typedef struct s_cmd
{
	char	*cmd;
	char	**path;
	char	**option;
}	t_cmd;

char	**get_path(char **env);
void	set_cmd(t_cmd *cmd, char *cmd_options, char **path);
void	check_cmd(t_cmd *cmd);
void	creat_process(t_cmd *cmd, char **argv, char **env);
void	process_before_pipe(t_cmd *cmd, int *fd, char *infile, char **env);
void	process_after_pipe(t_cmd *cmd, int *fd, char *outfile, char **env);
void	free_path(char **path);
void	free_cmd(t_cmd *cmd);
void	err_arg(char *s);
void	err_pipe(void);
void	err_fork(void);
void	err_cmd(char *s);
void	err_open(char *s);

#endif