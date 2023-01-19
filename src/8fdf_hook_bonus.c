/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8fdf_hook_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:31:38 by hujeong           #+#    #+#             */
/*   Updated: 2023/01/19 18:15:50 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include <mlx.h>

void	clear_img(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < 1920)
	{
		j = 0;
		while (j < 1080)
		{
			my_mlx_pixel_put(&(vars->img), i, j, 0);
			j++;
		}
		i++;
	}
}

int	close_win(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

void	key_press2(int key, t_vars *vars)
{
	if (key == PLUS_KEY)
		vars->distance *= 2;
	else if (key == MINUS_KEY && vars->distance > 1)
		vars->distance /= 2;
	else if (key == S_KEY)
		show_side_view(&vars->angle);
	else if (key == F_KEY)
		show_front_view(&vars->angle);
	else if (key == TAB_KEY)
		vars->color *= -1;
}

int	key_press1(int key, t_vars *vars)
{
	if (key == ESC)
		close_win(vars);
	else if (key == SPACE_BAR)
		set_default(vars);
	else if (key == Z_KEY)
		vars->angle.x += vars->rotate;
	else if (key == X_KEY)
		vars->angle.y += vars->rotate;
	else if (key == C_KEY)
		vars->angle.z += vars->rotate;
	else if (key == R_KEY)
		vars->rotate *= -1;
	else if (key == T_KEY)
		show_top_view(&vars->angle);
	else if (key == UP_KEY)
		vars->locate.y -= 10;
	else if (key == DOWN_KEY)
		vars->locate.y += 10;
	else if (key == LEFT_KEY)
		vars->locate.x -= 10;
	else if (key == RIGHT_KEY)
		vars->locate.x += 10;
	else
		key_press2(key, vars);
	return (0);
}
