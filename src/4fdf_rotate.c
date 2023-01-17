/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4fdf_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:20:55 by hujeong           #+#    #+#             */
/*   Updated: 2023/01/16 18:45:47 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

void	move_xyz(t_vars *vars, t_map *map, int distance)
{
	int		i;
	t_dummy	dummy;
	t_angle	a;

	i = -1;
	while (++i < vars->height * vars->width)
	{
		map[i].x -= vars->width / 2;
		map[i].y -= vars->height / 2;
	}
	a.x = radian(0);
	a.y = radian(0);
	a.z = radian(0);
	rotate(vars, map, &a);
	i = -1;
	while (++i < vars->height * vars->width)
	{
		dummy.x = (map[i].x * distance) + 960;
		dummy.y = (map[i].y * distance) + 540;
		if (dummy.x < 0 || dummy.x > 1920 || dummy.y < 0 || dummy.y > 1080)
		{
			i = -1;
			distance = distance / 3 * 2;
			if (distance < 3)
				break ;
			continue ;
		}
	}
	i = -1;
	while (++i < vars->height * vars->width)
	{
		map[i].x = map[i].x * distance + 960;
		map[i].y = map[i].y * distance + 540;
	}
}

void	rotate(t_vars *vars, t_map *map, t_angle *a)
{
	int		i;
	double	x;
	double	y;
	double	z;

	i = 0;
	while (i < vars->height * vars->width)
	{
		x = map[i].x;
		y = map[i].y;
		z = map[i].z;
		map[i].x = cos(a->z) * cos(a->y) * x
			+ (cos(a->z) * sin(a->y) * sin(a->x) - sin(a->z) * cos(a->x)) * y
			+ (cos(a->z) * sin(a->y) * cos(a->x) + sin(a->z) * sin(a->x)) * z;
		map[i].y = sin(a->z) * cos(a->y) * x
			+ (sin(a->z) * sin(a->y) * sin(a->x) + cos(a->z) * cos(a->x)) * y
			+ (sin(a->z) * sin(a->y) * cos(a->x) - cos(a->z) * sin(a->x)) * z;
		map[i].z = -1 * sin(a->y) * x + cos(a->y) * sin(a->x) * y
			+ cos(a->y) * cos(a->x) * z;
		++i;
	}
}

static void	test_distance()