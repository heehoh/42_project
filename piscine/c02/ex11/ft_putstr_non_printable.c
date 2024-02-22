/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:49:54 by hujeong           #+#    #+#             */
/*   Updated: 2022/10/07 09:48:01 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_hex(unsigned char np)
{
	unsigned char	str[16];
	int				i;
	unsigned char	div;
	unsigned char	mod;

	i = 0;
	while (i < 10)
	{
		str[i] = i + '0';
		i++;
	}
	str[10] = 'a';
	str[11] = 'b';
	str[12] = 'c';
	str[13] = 'd';
	str[14] = 'e';
	str[15] = 'f';
	div = np / 16;
	mod = np % 16;
	write(1, "\\", 1);
	write(1, &str[div], 1);
	write(1, &str[mod], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] > 126)
			ft_print_hex((unsigned char)str[i]);
		else
			write(1, &str[i], 1);
		i++;
	}
}
