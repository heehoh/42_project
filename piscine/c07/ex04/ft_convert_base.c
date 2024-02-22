/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:45:03 by hujeong           #+#    #+#             */
/*   Updated: 2022/10/17 14:07:54 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_base_count(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		++i;
	return (i);
}

int	ft_invalid_base(char *base, int base_n)
{
	int	i;

	i = 0;
	while (i < base_n)
	{
		if (base[i] == '+' || base[i] == '-'\
				|| base[i] == '\t' || base[i] == '\n' || base[i] == '\v'\
				|| base[i] == '\f' || base[i] == '\r' || base[i] == ' ')
			return (1);
		i++;
	}
	while (base_n - 1)
	{
		i = 0;
		while (i < base_n - 1)
		{
			if (base[i] == base[base_n - 1])
				return (1);
			i++;
		}
		base_n--;
	}
	return (0);
}

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

int	ft_valid_nb(char *str, char *base, int base_n)
{
	int	j;

	j = 0;
	while (j < base_n)
	{
		if (*str == base[j])
			return (0);
		j++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	int		j;
	int		sign;
	int		value;
	int		base_n;

	base_n = ft_base_count(base);
	if (base_n == 0 || base_n == 1 || ft_invalid_base(base, base_n))
		return (0);
	i = 0;
	sign = 1;
	value = 0;
	delete_space_sign(str, &i, &sign);
	while (str[i])
	{
		if (ft_valid_nb(&str[i], base, base_n))
			break ;
		j = 0;
		while (j < base_n)
			if (str[i] == base[j++])
				break ;
		value = value * base_n + j - 1;
		++i;
	}
	return (sign * value);
}
