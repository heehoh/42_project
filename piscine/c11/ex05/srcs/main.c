/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:47:39 by hujeong           #+#    #+#             */
/*   Updated: 2022/10/20 19:55:44 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stop.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_cmp_ope(char *ope)
{
	int		i;
	char	*str;

	i = 0;
	str = "+-*/%";
	if (ope[1] == 0)
	{
		while (str[i])
		{
			if (ope[0] == str[i])
				return (i);
			i++;
		}
	}
	return (-1);
}

void	ft_putnbr_over_zero(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb == 0)
		write(1, "0", 1);
}

void	ft_putnbr(int nb)
{
	char	str[20];
	int		index;

	index = 0;
	if (nb == -2147483648 || nb == 0)
		ft_putnbr_over_zero(nb);
	else
	{
		if (nb < 0)
		{
			nb *= -1;
			write(1, "-", 1);
		}
		while (nb)
		{
			str[index++] = nb % 10 + '0';
			nb /= 10;
		}
		while (index)
		{
			write(1, &str[index - 1], 1);
			index--;
		}
	}
	write(1, "\n", 1);
}

int	main(int argc, char *argv[])
{
	int		num[3];
	int		(*fp[5])(int, int);

	fp[0] = add;
	fp[1] = sub;
	fp[2] = mul;
	fp[3] = div;
	fp[4] = mod;
	if (argc == 4)
	{
		num[0] = ft_atoi(argv[1]);
		num[1] = ft_cmp_ope(argv[2]);
		num[2] = ft_atoi(argv[3]);
		if (num[2] == 0 && num[1] == 3)
			ft_putstr(STOP_DIV);
		else if (num[2] == 0 && num[1] == 4)
			ft_putstr(STOP_MOD);
		else if (num[1] != -1)
			ft_putnbr((*fp[num[1]])(num[0], num[2]));
		else
			write(1, "0\n", 2);
	}
	return (0);
}
