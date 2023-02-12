/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:21:55 by hujeong           #+#    #+#             */
/*   Updated: 2023/02/12 13:59:12 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pass_white_space_sign(char	**str, int *sign)
{
	while (**str == ' ' || (**str >= 9 && **str <= 13))
		++(*str);
	if (**str == '-')
	{
		*sign = -1;
		++(*str);
	}
	else if (**str == '+')
		++(*str);
	while (**str == '0')
		++(*str);
}

long long	ft_atoi(const char *str)
{
	long long	value;
	int			sign;
	int			i;

	value = 0;
	sign = 1;
	i = 0;
	pass_white_space_sign(&str, &sign);
	while (str[i] >= '0' && str[i] <= '9')
		value = value * 10 + str[i++] - '0';
	if (str[i] != '\0' && (str[i] < '0' || str[i] > '9'))
		print_error();
	if (i > 11 || (value > INT32_MAX && sign == 1)
		|| (value * sign) < INT32_MIN)
		print_error();
	return (sign * value);
}

void	print_error(void)
{
	write(STDERR_FILENO, "error\n", 6);
	exit(EXIT_FAILURE);
}
