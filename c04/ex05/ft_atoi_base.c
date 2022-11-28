/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:46:11 by hujeong           #+#    #+#             */
/*   Updated: 2022/10/13 16:08:02 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_base_count2(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		++i;
	return (i);
}

int	ft_invalid_base2(char *base, int radix)
{
	int	i;

	i = 0;
	while (i < radix)
	{
		if (base[i] == '+' || base[i] == '-'\
				|| base[i] == '\t' || base[i] == '\n' || base[i] == '\v'\
				|| base[i] == '\f' || base[i] == '\r' || base[i] == ' ')
			return (1);
		i++;
	}
	while (radix - 1)
	{
		i = 0;
		while (i < radix - 1)
		{
			if (base[i] == base[radix - 1])
				return (1);
			i++;
		}
		radix--;
	}
	return (0);
}

void	delete_space_sign2(char *str, int *i, int *sign)
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

int	ft_valid_nb(char *str, char *base, int radix)
{
	int	j;

	j = 0;
	while (j < radix)
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
	int		radix;

	radix = ft_base_count2(base);
	if (radix == 0 || radix == 1 || ft_invalid_base2(base, radix))
		return (0);
	i = 0;
	sign = 1;
	value = 0;
	delete_space_sign2(str, &i, &sign);
	while (str[i])
	{
		if (ft_valid_nb(&str[i], base, radix))
			break ;
		j = 0;
		while (j < radix)
			if (str[i] == base[j++])
				break ;
		value = value * radix + j - 1;
		++i;
	}
	return (sign * value);
}
