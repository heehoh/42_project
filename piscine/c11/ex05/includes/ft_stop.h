/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stop.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:32:54 by hujeong           #+#    #+#             */
/*   Updated: 2022/10/20 17:23:19 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STOP_H
# define FT_STOP_H

# include <unistd.h>
# define STOP_DIV "Stop : division by zero\n"
# define STOP_MOD "Stop : modulo by zero\n"

int	add(int a, int b);
int	sub(int a, int b);
int	mul(int a, int b);
int	div(int a, int b);
int	mod(int a, int b);
int	ft_atoi(char *str);

#endif
