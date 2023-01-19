/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9fdf_viewpoint_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:32:22 by hujeong           #+#    #+#             */
/*   Updated: 2023/01/19 17:18:22 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	show_top_view(t_angle *angle)
{
	angle->x = 0;
	angle->y = 0;
	angle->z = 0;
}

void	show_front_view(t_angle *angle)
{
	angle->x = radian(90);
	angle->y = 0;
	angle->z = 0;
}

void	show_side_view(t_angle *angle)
{
	angle->x = radian(90);
	angle->y = radian(90);
	angle->z = 0;
}
