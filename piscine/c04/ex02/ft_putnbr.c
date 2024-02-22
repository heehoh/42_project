/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:15:25 by hujeong           #+#    #+#             */
/*   Updated: 2022/10/12 20:32:53 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_special_nb_print(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else
		write(1, "0", 1);
}

void	ft_putnbr(int nb)
{
	char	str[10];
	int		i;

	if (nb == -2147483648 || nb == 0)
	{
		ft_special_nb_print(nb);
		return ;
	}
	if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
	}
	i = 0;
	while (nb)
	{
		str[i] = nb % 10 + '0';
		nb /= 10;
		++i;
	}
	while (--i >= 0)
		write(1, &str[i], 1);
}
