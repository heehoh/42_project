/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 20:01:09 by hujeong           #+#    #+#             */
/*   Updated: 2022/12/07 12:55:22 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	print_hex(int i)
{
	char	*hex;

	hex = "0123456789abcdef";
	return (write(1, &hex[i], 1));
}

static int	print_hex_up(int i)
{
	char	*hex;

	hex = "0123456789ABCDEF";
	return (write(1, &hex[i], 1));
}

int	ft_putadr(unsigned long adr)
{
	int				nbr[16];
	int				i;
	int				check;
	int				len;

	i = 0;
	if (adr == 0)
		nbr[i++] = adr;
	while (adr)
	{
		nbr[i++] = adr % 16;
		adr /= 16;
	}
	check = write(1, "0x", 2);
	if (check < 0)
		return (-1);
	len = check;
	while (i > 0)
	{
		check = print_hex(nbr[--i]);
		if (check < 0)
			return (-1);
		len += check;
	}
	return (len);
}

int	ft_puthex_up(unsigned int hex)
{
	int	nbr[8];
	int	i;
	int	check;
	int	len;

	i = 0;
	if (hex == 0)
		nbr[i++] = hex;
	while (hex)
	{
		nbr[i++] = hex % 16;
		hex /= 16;
	}
	len = 0;
	while (i > 0)
	{
		check = print_hex_up(nbr[--i]);
		if (check < 0)
			return (-1);
		len += check;
	}
	return (len);
}

int	ft_puthex_low(unsigned int hex)
{
	int	nbr[8];
	int	i;
	int	check;
	int	len;

	i = 0;
	if (hex == 0)
		nbr[i++] = hex;
	while (hex)
	{
		nbr[i++] = hex % 16;
		hex /= 16;
	}
	len = 0;
	while (i > 0)
	{
		check = print_hex(nbr[--i]);
		if (check < 0)
			return (-1);
		len += check;
	}
	return (len);
}
