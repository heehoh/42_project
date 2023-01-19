/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5fdf_map_draw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:28:22 by hujeong           #+#    #+#             */
/*   Updated: 2023/01/19 17:18:19 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

static void	line_draw(t_img *img, t_map map1, t_map map2);
static void	line_draw_util1(t_map *map1, t_map *map2, t_change *change);
static void	line_draw_util2(t_map *map1, t_map *map2, t_change *change);

void	map_draw(t_vars *vars, t_img *img, t_map *map)
{
	int	i;
	int	j;
	int	width;
	int	height;

	width = vars->width;
	height = vars->height;
	i = -1;
	while (++i <= height - 1)
	{
		j = -1;
		while (++j < width - 1)
			line_draw(img, map[width * i + j], map[width * i + j + 1]);
	}
	i = -1;
	while (++i <= width - 1)
	{
		j = -1;
		while (++j < height - 1)
			line_draw(img, map[width * j + i], map[width * (j + 1) + i]);
	}
}

static void	line_draw(t_img *img, t_map map1, t_map map2)
{
	t_change	change;

	change.dx = fabs(map2.x - map1.x);
	change.dy = fabs(map2.y - map1.y);
	if (change.dx > change.dy)
	{
		change.flag = change.dx;
		while ((int)map1.x != (int)map2.x)
		{
			my_mlx_pixel_put(img, map1.x, map1.y, map1.color);
			line_draw_util1(&map1, &map2, &change);
		}
	}
	else
	{
		change.flag = change.dy;
		while ((int)map1.y != (int)map2.y)
		{
			my_mlx_pixel_put(img, map1.x, map1.y, map1.color);
			line_draw_util2(&map1, &map2, &change);
		}
	}
	my_mlx_pixel_put(img, map1.x, map1.y, map1.color);
}

static void	line_draw_util1(t_map *map1, t_map *map2, t_change *change)
{
	change->flag += change->dy;
	if (map1->x < map2->x)
		++(map1->x);
	else if (map1->x > map2->x)
		--(map1->x);
	if (change->flag >= 2 * change->dx)
	{
		change->flag -= change->dx;
		if (map1->y < map2->y)
			++(map1->y);
		else if (map1->y > map2->y)
			--(map1->y);
	}
	if ((map1->color > map2->color))
		map1->color = map2->color;
}

static void	line_draw_util2(t_map *map1, t_map *map2, t_change *change)
{
	change->flag += change->dx;
	if (map1->y < map2->y)
		++(map1->y);
	else if (map1->y > map2->y)
		--(map1->y);
	if (change->flag >= 2 * change->dy)
	{
		change->flag -= change->dy;
		if (map1->x < map2->x)
			++(map1->x);
		else if (map1->x > map2->x)
			--(map1->x);
	}
	if ((map1->color > map2->color))
		map1->color = map2->color;
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x > 1920 || y < 0 || y > 1080)
		return ;
	dst = img->addr + (y * img->line_length
			+ x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
