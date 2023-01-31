/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:06:27 by hujeong           #+#    #+#             */
/*   Updated: 2023/01/31 14:20:28 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_cmd	cmd[2];
	char	**path;

	if (argc != 5)
		err_arg("invalid number of argument");
	path = get_path(env);
	set_cmd(&cmd[0], argv[2], path);
	set_cmd(&cmd[1], argv[3], path);
	free_path(path);
	check_cmd(&cmd[0]);
	check_cmd(&cmd[1]);
	creat_process(cmd, argv, env);
	free_cmd(cmd);
	return (0);
}
