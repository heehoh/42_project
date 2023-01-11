/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:21:55 by hujeong           #+#    #+#             */
/*   Updated: 2022/12/30 12:31:11 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	unsigned long long	value;
	int					sign;
	int					i;

	value = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		++str;
	if (str[i] == '-')
	{
		sign = -1;
		++str;
	}
	else if (str[i] == '+')
		++str;
	while (str[i] == '0')
		++str;
	while (str[i] >= '0' && str[i] <= '9')
		value = value * 10 + str[i++] - '0';
	if (sign == 1 && (i > 18 || (i == 18 && value >= 9223372036854775807)))
		return (-1);
	if (sign == -1 && (i > 18 || (i == 18 && value > 9223372036854775807)))
		return (0);
	return (sign * value);
}
