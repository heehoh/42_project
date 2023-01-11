/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error_msg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:28:28 by hujeong           #+#    #+#             */
/*   Updated: 2023/01/11 21:08:31 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void error_msg(int err_num)
{
    if (err_num == 1)
        perror("Invalid argument");
    else if (err_num == 2)
        perror("Invalid map");
    else if (err_num == 3)
        perror("malloc fail");
    else if (err_num == 4)
        perror("no file");
    exit(EXIT_FAILURE);
}