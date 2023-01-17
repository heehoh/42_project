/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:43:43 by hujeong           #+#    #+#             */
/*   Updated: 2023/01/16 18:33:00 by hujeong          ###   ########.fr       */
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
}	t_vars;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_dummy
{
	double	x;
	double	y;
}	t_dummy;

typedef struct s_angle
{
	double	x;
	double	y;
	double	z;
}	t_angle;

typedef struct s_change
{
	int	dx;
	int	dy;
	int	flag;
}	t_change;

# define PI 3.141592

void	get_map(t_vars *vars, t_map **map, char *argv);
void	map_draw(t_vars *vars, t_data *img, t_map *map);
void	error_msg(int err_num);
void	rotate(t_vars *vars, t_map *map, t_angle *a);
void	ft_mlx(t_vars *vars, t_data *img);
double	radian(double angle);
void	get_xyz(t_vars *vars, t_map *map, char *store);
void	move_xyz(t_vars *vars, t_map *map, int distance);
int		count_nb(char *line);
void	move_if_color(char **line);

#endif
