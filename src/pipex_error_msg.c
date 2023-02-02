/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error_msg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:04:19 by hujeong           #+#    #+#             */
/*   Updated: 2023/02/02 12:00:30 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <errno.h>
#include <string.h>

void	err_arg(char *s)
{
	write(2, s, ft_strlen(s));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

void	err_pipe(void)
{
	write(2, "pipe error\n", 11);
	exit(EXIT_FAILURE);
}

void	err_fork(void)
{
	ft_printf("%s\n", strerror(errno));
	exit(EXIT_FAILURE);
}

void	err_open(char *s)
{
	ft_printf("%s: %s\n", strerror(errno), s);
	exit(EXIT_FAILURE);
}

void	err_cmd(char *s)
{
	write(2, "command not found: ", 19);
	write(2, s, ft_strlen(s));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}
