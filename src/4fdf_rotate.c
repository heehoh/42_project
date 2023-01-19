/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4fdf_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:20:55 by hujeong           #+#    #+#             */
/*   Updated: 2023/01/19 18:33:01 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

static void	test_distance(t_vars *vars, t_map *show);

void	set_default(t_vars *vars)
{
	vars->angle.x = radian(45);
	vars->angle.y = radian(30);
	vars->angle.z = radian(-30);
	vars->locate.x = 960;
	vars->locate.y = 540;
	vars->rotate = 0.1;
	vars->distance = 60;
	vars->color = 1;
	rotate_xyz(vars, vars->show, &(vars->angle), 1);
}

void	rotate_xyz(t_vars *vars, t_map *show, t_angle *a, int first)
{
	int	i;

	i = -1;
	while (++i < vars->height * vars->width)
		show[i] = vars->map[i];
	rotate(vars, show, a);
	if (first)
		test_distance(vars, show);
	i = -1;
	if (vars->color == -1)
		while (++i < vars->height * vars->width)
			show[i].color = 0xAAFFFFFF;
	i = -1;
	while (++i < vars->height * vars->width)
	{
		show[i].x = (show[i].x * vars->distance) + vars->locate.x;
		show[i].y = (show[i].y * vars->distance) + vars->locate.y;
	}
}

void	rotate(t_vars *vars, t_map *show, t_angle *a)
{
	int		i;
	double	x;
	double	y;
	double	z;

	i = 0;
	while (i < vars->height * vars->width)
	{
		x = show[i].x;
		y = show[i].y;
		z = show[i].z;
		show[i].x = cos(a->z) * cos(a->y) * x
			+ (cos(a->z) * sin(a->y) * sin(a->x) - sin(a->z) * cos(a->x)) * y
			+ (cos(a->z) * sin(a->y) * cos(a->x) + sin(a->z) * sin(a->x)) * z;
		show[i].y = sin(a->z) * cos(a->y) * x
			+ (sin(a->z) * sin(a->y) * sin(a->x) + cos(a->z) * cos(a->x)) * y
			+ (sin(a->z) * sin(a->y) * cos(a->x) - cos(a->z) * sin(a->x)) * z;
		show[i].z = -1 * sin(a->y) * x + cos(a->y) * sin(a->x) * y
			+ cos(a->y) * cos(a->x) * z;
		++i;
	}
}

double	radian(double angle)
{
	return (angle * PI / 180);
}

static void	test_distance(t_vars *vars, t_map *show)
{
	t_dummy	dummy;
	int		i;

	i = -1;
	while (++i < vars->height * vars->width)
	{
		dummy.x = (show[i].x * vars->distance) + 960;
		dummy.y = (show[i].y * vars->distance) + 540;
		if (dummy.x < 0 || dummy.x > 1920 || dummy.y < 0 || dummy.y > 1080)
		{
			i = -1;
			vars->distance = vars->distance / 3 * 2;
			if (vars->distance < 3)
				break ;
			continue ;
		}
	}
}
