/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:49:20 by hujeong           #+#    #+#             */
/*   Updated: 2022/10/20 16:46:58 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stop.h"

void	delete_space_sign(char *str, int *i, int *sign)
{
	while (1)
	{
		if (str[*i] == '\t' || str[*i] == '\n' || str[*i] == '\v'\
				|| str[*i] == '\f' || str[*i] == '\r' || str[*i] == ' ')
			++*i;
		else
			break ;
	}
	while (1)
	{
		if (str[*i] == '-')
		{
			++*i;
			*sign *= -1;
		}
		else if (str[*i] == '+')
			++*i;
		else
			break ;
	}
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	value;

	i = 0;
	sign = 1;
	value = 0;
	delete_space_sign(str, &i, &sign);
	while (1)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			value *= 10;
			value += str[i] - '0';
			++i;
		}
		else
			break ;
	}
	return (sign * value);
}
