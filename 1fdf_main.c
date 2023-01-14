/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1fdf_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:40:16 by hujeong           #+#    #+#             */
/*   Updated: 2023/01/14 14:41:31 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

int main(int argc, char **argv)
{
    t_vars	vars;
    t_data  img;
    t_map   *map;

    if (argc != 2)
        error_msg(1);
    get_map(&vars, &map, argv[1]);
    ft_mlx(&vars, &img);
	map_draw(&vars, &img, map);
//  mlx_key_hook(vars.win, close, &vars);
    mlx_loop(vars.mlx);
}

void    ft_mlx(t_vars *vars, t_data *img)
{
    vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 1920, 1200, "FdF");
	img->img = mlx_new_image(vars->mlx, 1920, 1200);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),
                                    &(img->line_length), &(img->endian));
}