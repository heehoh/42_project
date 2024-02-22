/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:21:55 by hujeong           #+#    #+#             */
/*   Updated: 2023/01/13 15:53:38 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static unsigned int	ft_atoi_x(const char *str);

long long	ft_atoi(const char *str)
{
	long long	value;
	int			sign;
	int			i;

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
	if (str[i] == '0' && (str[i + 1] == 'x' || str[i + 1] == 'X'))
		return (ft_atoi_x(str + 2));
	while (str[i] == '0')
		++str;
	while (str[i] >= '0' && str[i] <= '9')
		value = value * 10 + str[i++] - '0';
	return (sign * value);
}

static unsigned int	ft_atoi_x(const char *str)
{
	unsigned int	value;
	int				i;

	value = 0;
	i = 0;
	while ((str[i] >= '0' && str[i] <= '9')
		|| (str[i] >= 'a' && str[i] <= 'f')
		|| (str[i] >= 'A' && str[i] <= 'F'))
	{
		if (str[i] >= '0' && str[i] <= '9')
			value = value * 16 + str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			value = value * 16 + str[i] - 'a' + 10;
		else
			value = value * 16 + str[i] - 'A' + 10;
		++i;
	}
	return (value);
}
