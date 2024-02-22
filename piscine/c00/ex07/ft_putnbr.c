/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:24:02 by hujeong           #+#    #+#             */
/*   Updated: 2022/10/05 09:52:00 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
			str[index] = nb % 10 + '0';
			nb /= 10;
			index++;
		}
		while (index)
		{
			write(1, &str[index - 1], 1);
			index--;
		}
	}
}
