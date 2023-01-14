/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4fdf_map_draw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:40:45 by hujeong           #+#    #+#             */
/*   Updated: 2023/01/13 18:19:20 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"
#include <mlx.h>

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	line_draw(t_data *img, t_map map1, t_map map2)
{
    int dx;
    int dy;
    int flag;

    dx = fabs(map2.x - map1.x);
    dy = fabs(map2.y - map1.y);
    if (dx > dy)
    {
        flag = dx;
        if (map1.x < map2.x)
        {
            while (map1.x < map2.x)
            {
                my_mlx_pixel_put(img, map1.x, map1.y, map1.color);
                flag += dy;
                ++map1.x;
                if (flag >= 2 * dx)
                {
                    flag -= dx;
                    if (map1.y < map2.y)
                        ++map1.y;
                    else
                        --map1.y;
                }
            }
        }
        else
        {
            while (map1.x > map2.x)
            {
                my_mlx_pixel_put(img, map1.x, map1.y, map1.color);
                flag += dy;
                --map1.x;
                if (flag >= 2 * dx)
                {
                    flag -= dx;
                    if (map1.y < map2.y)
                        ++map1.y;
                    else
                        --map1.y;
                }
            }
        }
    }
    else
    {
        flag = dy;
        if (map1.y < map2.y)
        {
            while (map1.y < map2.y)
            {
                    my_mlx_pixel_put(img, map1.x, map1.y, map1.color);
                flag += dx;
                ++map1.y;
                if (flag > dy)
                {
                    flag -= dy;
                    if (map1.x < map2.x)
                        ++map1.x;
                    else
                        --map1.x;
                }
            }
        }
        else
        {
            while (map1.y > map2.y)
            {
                my_mlx_pixel_put(img, map1.x, map1.y, map1.color);
                flag += dx;
                --map1.y;
                if (flag > dy)
                {
                    flag -= dy;
                    if (map1.x < map2.x)
                        ++map1.x;
                    else
                        --map1.x;
                }
            }
        }
    }
}

void map_draw(t_vars *vars, t_data *img, t_map *map)
{
    int i;
    int j;
    int width;
    int height;

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
    mlx_put_image_to_window(vars->mlx, vars->win, img->img, 0, 0);
}