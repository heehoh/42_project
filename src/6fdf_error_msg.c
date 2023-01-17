/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6fdf_error_msg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:28:53 by hujeong           #+#    #+#             */
/*   Updated: 2023/01/16 18:33:29 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	error_msg(int err_num)
{
	if (err_num == 1)
		perror("Invalid argument");
	else if (err_num == 2)
		perror("Invalid map");
	else if (err_num == 3)
		perror("malloc fail");
	else if (err_num == 4)
		perror("no file");
	else if (err_num == 5)
		perror("get_next_line fail");
	else if (err_num == 6)
		perror("too big map");
	exit(EXIT_FAILURE);
}

double	radian(double angle)
{
	return (angle * PI / 180);
}