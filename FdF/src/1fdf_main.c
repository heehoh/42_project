/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1fdf_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:40:16 by hujeong           #+#    #+#             */
/*   Updated: 2023/01/19 18:01:05 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

static void	ft_mlx(t_vars *vars, t_img *img);
static int	close_win(t_vars *vars);
static int	key_press(int key, t_vars *vars);

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		error_msg(1);
	get_map(&vars, &(vars.map), &(vars.show), argv[1]);
	ft_mlx(&vars, &(vars.img));
	set_default(&vars);
	map_draw(&vars, &(vars.img), vars.show);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	mlx_hook(vars.win, KEY_PRESS, 0, key_press, &vars);
	mlx_hook(vars.win, WIN_CLOSE, 0, close_win, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

static void	ft_mlx(t_vars *vars, t_img *img)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 1920, 1080, "FdF");
	img->img = mlx_new_image(vars->mlx, 1920, 1080);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),
			&(img->line_length), &(img->endian));
}

static int	close_win(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

static int	key_press(int key, t_vars *vars)
{
	if (key == ESC)
		close_win(vars);
	return (0);
}
