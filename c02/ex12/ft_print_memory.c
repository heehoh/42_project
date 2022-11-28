/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:46:05 by hujeong           #+#    #+#             */
/*   Updated: 2022/10/10 12:15:35 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(unsigned char a)
{
	unsigned char	hex[16];
	int				i;

	i = 0;
	while (i < 10)
	{
		hex[i] = i + '0';
		i++;
	}
	hex[10] = 'a';
	hex[11] = 'b';
	hex[12] = 'c';
	hex[13] = 'd';
	hex[14] = 'e';
	hex[15] = 'f';
	write(1, &hex[a], 1);
}

void	ft_print_first_char_address(unsigned char *a)
{
	unsigned long long	address;
	unsigned char		str[16];
	int					i;

	address = (unsigned long long)a;
	i = 0;
	while (i < 16)
	{
		str[i] = address % 16;
		address /= 16;
		i++;
	}
	while (i > 0)
	{
		print_hex(str[i - 1]);
		i--;
	}
	write(1, ": ", 2);
}

void	ft_print_hex_asc(unsigned char *str, unsigned int i, unsigned int size)
{
	unsigned int	div;
	unsigned int	mod;
	unsigned int	j;

	j = 0;
	while ((i * 16) + j < size && j < 16)
	{
		div = str[j] / 16;
		mod = str[j] % 16;
		print_hex(div);
		print_hex(mod);
		if ((j + 1) % 2 == 0)
			write(1, " ", 1);
		j++;
	}
	if (j != 16 && size % 16 != 0)
	{
		while (j++ < 16)
		{
			write(1, "  ", 2);
			if (j % 2 == 0)
				write(1, " ", 1);
		}
	}
}

void	ft_print_char(unsigned char *str, unsigned int i, unsigned int size)
{
	unsigned int	j;

	j = 0;
	while ((i * 16) + j < size && j < 16)
	{
		if (str[j] < 32 || str[j] > 126)
			write(1, ".", 1);
		else
			write(1, &str[j], 1);
		j++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	str[16];
	unsigned int	i;
	unsigned int	j;

	if (size == 0)
		return (addr);
	i = 0;
	while (i * 16 < size)
	{
		j = 0;
		while (j + (i * 16) < size && j < 16)
		{
			str[j] = *((unsigned char *)addr + j + (i * 16));
			j++;
		}
		ft_print_first_char_address(addr + (i * 16));
		ft_print_hex_asc(str, i, size);
		ft_print_char(str, i, size);
		write(1, "\n", 1);
		i++;
	}
	return (addr);
}
