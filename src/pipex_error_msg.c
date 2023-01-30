/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error_msg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:04:19 by hujeong           #+#    #+#             */
/*   Updated: 2023/01/30 16:35:47 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include <errno.h>
#include <string.h>

void	err_arg(char *s)
{
	write(2, s, ft_strlen(s));
	exit(EXIT_FAILURE);
}

void	err_pipe(void)
{
	write(2, "pipe error\n", 12);
	exit(EXIT_FAILURE);
}

void	err_cmd(char *s)
{
	write(2, "command not found: ", 20);
	write(2, s, ft_strlen(s));
	exit(EXIT_FAILURE);
}

void	err_open(char *s)
{
	perror(s);
	exit(EXIT_FAILURE);
}

void	err_fork(void)
{
	ft_printf("%s", strerror(errno));
	exit(EXIT_FAILURE);
}
