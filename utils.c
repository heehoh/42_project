/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:50:54 by hujeong           #+#    #+#             */
/*   Updated: 2022/12/07 13:26:42 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar(char c)
{
	int	len;

	len = write(1, &c, 1);
	return (len);
}

int	ft_putstr(char *s)
{
	int	len;

	if (s == 0)
		return (write(1, "(null)", 6));
	len = 0;
	while (s[len])
		len++;
	len = write(1, s, len);
	return (len);
}

static int	ft_putnbr_special(int n)
{
	int	len;

	if (n == -2147483648)
		len = write(1, "-2147483648", 11);
	else
		len = write(1, "0", 1);
	return (len);
}

int	ft_putnbr(int n)
{
	char	nb[10];
	int		len;
	int		i;

	if (n == -2147483648 || n == 0)
		return (ft_putnbr_special(n));
	len = 0;
	if (n < 0)
	{
		if (write(1, "-", 1) < 0)
			return (-1);
		++len;
		n *= -1;
	}
	i = 0;
	while (n)
	{
		nb[9 - i++] = n % 10 + '0';
		n /= 10;
	}
	len += write(1, &nb[10 - i], i);
	if (len <= 0)
		return (-1);
	return (len);
}

int	ft_putnbr_unsign(int n)
{
	unsigned int	nbr;
	char			nb[10];
	int				len;
	int				i;

	nbr = (unsigned int)n;
	if (nbr == 0)
		len = ft_putnbr_special(nbr);
	else
	{
		i = 0;
		while (nbr)
		{
			nb[9 - i++] = nbr % 10 + '0';
			nbr = nbr / 10;
		}
		len = write(1, &nb[10 - i], i);
	}
	return (len);
}
