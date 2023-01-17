/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1fdf_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:40:16 by hujeong           #+#    #+#             */
/*   Updated: 2023/01/17 18:59:58 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

/*# define KEY_PRESS 2
# define KEY_RElEASE 3
# define MOUSE_PRESS 4 
# define MOUSE_REALESE 5
# define MOUSE_POINT 6*/

static void	ft_mlx(t_vars *vars, t_img *img);

int	main_loop(t_map *show)
{
	int	i;

	i = 1;
	show[i].x = 1;
	ft_printf("hi\n");
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_img	img;
	t_map	*map;
	t_map	*show;
	t_angle	a;

	if (argc != 2)
		error_msg(1);
	get_map(&vars, &map, &show, argv[1]);
	ft_mlx(&vars, &img);
	set_angle(&a);
	rotate_xyz(&vars, show, &a, 1);
	map_draw(&vars, &img, show);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
/*	mlx_hook(vars.win, KeyPress, 0, ft_key_press, &vars);
  	mlx_hook(vars.win, KeyRelease, 0, ft_key_release, &img);
	mlx_hook(vars.win, 6, 0, key_hook, &img);
	mlx_hook(vars.win, 4, 0, key_hook1, &img);
	mlx_hook(vars.win, 5, 0, key_hook2, &img);*/
	mlx_loop_hook(vars.mlx, main_loop, show);
	mlx_loop(vars.mlx);
}

static void	ft_mlx(t_vars *vars, t_img *img)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 1920, 1080, "FdF");
	img->img = mlx_new_image(vars->mlx, 1920, 1080);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),
			&(img->line_length), &(img->endian));
}
