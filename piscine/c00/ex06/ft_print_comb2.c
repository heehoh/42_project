/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:45:10 by hujeong           #+#    #+#             */
/*   Updated: 2022/10/04 12:45:27 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_2(char a)
{
	char	i;
	char	j;

	i = a / 10 + 48;
	j = a % 10 + 48;
	write(1, &i, 1);
	write(1, &j, 1);
}

void	ft_print_comb2(void)
{
	char	a;
	char	b;

	a = 0;
	b = 0;
	while (a <= 98)
	{
		while (b <= 99)
		{
			if (a < b)
			{
				ft_putchar_2(a);
				write(1, " ", 1);
				ft_putchar_2(b);
				if (a != 98)
					write(1, ", ", 2);
			}
			b++;
		}
		a++;
		b = a;
	}
}
