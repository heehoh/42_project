/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:42:19 by hujeong           #+#    #+#             */
/*   Updated: 2023/01/19 17:08:29 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include "key.h"
# include "fdf.h"

void	show_top_view(t_angle *angle);
void	show_front_view(t_angle *angle);
void	show_side_view(t_angle *angle);
void	clear_img(t_vars *vars);
int		close_win(t_vars *vars);
void	key_press2(int key, t_vars *vars);
int		key_press1(int key, t_vars *vars);

#endif