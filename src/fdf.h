/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:43:43 by hujeong           #+#    #+#             */
/*   Updated: 2023/01/17 18:40:45 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"

typedef struct s_map
{
	double			x;
	double			y;
	double			z;
	unsigned int	color;
}	t_map;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		distance;
	int		max;
}	t_vars;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_angle
{
	double	x;
	double	y;
	double	z;
}	t_angle;

typedef struct s_dummy
{
	double	x;
	double	y;
}	t_dummy;

typedef struct s_change
{
	int	dx;
	int	dy;
	int	flag;
}	t_change;

# define PI 3.141592

void	get_map(t_vars *vars, t_map **map, t_map **show, char *argv);
void	get_xyz(t_vars *vars, t_map *map, char *store);
void	set_angle(t_angle *a);
void	rotate_xyz(t_vars *vars, t_map *show, t_angle *a, int first);
void	rotate(t_vars *vars, t_map *show, t_angle *a);
double	radian(double angle);
void	map_draw(t_vars *vars, t_img *img, t_map *show);
void	error_msg(int err_num);

#endif
