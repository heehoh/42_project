/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:19:53 by hujeong           #+#    #+#             */
/*   Updated: 2023/03/24 09:10:48 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../libft/libft.h"
#include "../minishell.h"

int	builtin_pwd(t_current *current, int write_fd)
{
	if (current->path[0] == '\0')
	{
		write(2, "pwd: error retrieving current directory:", 40);
		if (getcwd(current->path, 1024) == NULL)
		{
			write(2, "getcwd: cannot access parent directories", 41);
			write(2, ": No such file or directory\n", 28);
			return (1);
		}
		write(write_fd, current->path, ft_strlen(current->path));
	}
	else
		write(write_fd, current->path, ft_strlen(current->path));
	write(write_fd, "\n", 1);
	return (0);
}
