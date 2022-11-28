/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:13:18 by hujeong           #+#    #+#             */
/*   Updated: 2022/10/13 10:45:36 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_base_count(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		++i;
	return (i);
}

int	ft_invalid_base(char *base, int radix)
{
	int	i;

	i = 0;
	while (i < radix)
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		++i;
	}
	while (radix - 1)
	{
		i = 0;
		while (i < radix - 1)
		{
			if (base[i] == base[radix - 1])
				return (1);
			++i;
		}
		--radix;
	}
	return (0);
}

void	ft_print_base(int nbr, int mod, int radix, char *base)
{
	if (nbr == 0)
		return ;
	mod = nbr % radix;
	ft_print_base(nbr / radix, mod, radix, base);
	write(1, &base[mod], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	mod;
	int	radix;

	radix = ft_base_count(base);
	if (radix == 0 || radix == 1 || ft_invalid_base(base, radix))
		return ;
	mod = nbr % radix;
	if (nbr < 0)
	{
		mod *= -1;
		write(1, "-", 1);
		ft_print_base(-(nbr / radix), mod, radix, base);
	}
	else
		ft_print_base(nbr / radix, mod, radix, base);
	write(1, &base[mod], 1);
}
