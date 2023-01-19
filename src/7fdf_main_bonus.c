/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7fdf_main_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:30:36 by hujeong           #+#    #+#             */
/*   Updated: 2023/01/19 17:24:29 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include <mlx.h>

static int	main_loop(t_vars *vars);
static void	ft_mlx(t_vars *vars, t_img *img);

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		error_msg(1);
	get_map(&vars, &(vars.map), &(vars.show), argv[1]);
	ft_mlx(&vars, &(vars.img));
	set_default(&vars);
	mlx_hook(vars.win, KEY_PRESS, 0, key_press1, &vars);
	mlx_hook(vars.win, WIN_CLOSE, 0, close_win, &vars);
	mlx_loop_hook(vars.mlx, main_loop, &vars);
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

static int	main_loop(t_vars *vars)
{
	clear_img(vars);
	map_draw(vars, &(vars->img), vars->show);
	rotate_xyz(vars, vars->show, &vars->angle, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}
