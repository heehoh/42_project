/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:43:43 by hujeong           #+#    #+#             */
/*   Updated: 2023/01/11 21:07:49 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "libft/libft.h"

typedef struct s_map
{
	int	x;
	int	y;
	int	z;
}	t_map;

typedef struct  s_vars
{
	void	*mlx;
	void	*win;
    int     width;
    int     height;
}	t_vars;

typedef struct  s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}   t_data;

typedef struct	s_dummy
{
	int	x;
	int	y;
}	t_dummy;

void    get_map(t_vars *vars, t_map *map, char *argv);
void	line_draw(t_data *img, int x1, int y1, int x2, int y2);
void 	error_msg(int err_num);
void    rotate(t_map *map, double alpha, double beta, double gamma);

# endif