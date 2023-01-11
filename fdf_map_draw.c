/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:40:45 by hujeong           #+#    #+#             */
/*   Updated: 2023/01/11 21:07:46 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	line_draw(t_vars *vars, t_data *img, t_map map1, t_map map2)
{
    int dx;
    int dy;

    dx = map2.x - map1.x;
    dy = map2.y - map1.y;
    while (1)
    {
        
    }
}

void map_draw(t_vars *vars, t_data *img, t_map *map)
{
    int i;
    int j;
    int width;
    int height;

    i = 0;
    width = vars->width;
    height = vars->height;
    while (i < height - 1)
    {
        j = 0;
        while (j < width - 1)
        {
            line_draw(vars, img, map[width * i + j], map[width * i + j + 1]);
            line_draw(vars, img, map[width * i + j], map[width * (i + 1) + j]);
            ++j;
        }
        ++i;
    }
    mlx_put_image_to_window(vars->mlx, vars->win, img->img, 0, 0);
}