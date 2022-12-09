/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:23:41 by hujeong           #+#    #+#             */
/*   Updated: 2022/12/09 17:08:06 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(const char *s)
{
	if (s == 0)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}

int	ft_putnbr(long n)
{
	char	*nbr;
	int		len;

	nbr = ft_itoa(n, 10);
	if (nbr == NULL)
		return (-1);
	len = write(1, nbr, ft_strlen(nbr));
	free(nbr);
	return (len);
}

int	ft_puthex(unsigned int hex, int up_low)
{
	char	*nbr;
	int		len;
	int		i;

	nbr = ft_itoa(hex, 16);
	if (nbr == NULL)
		return (-1);
	i = 0;
	if (up_low == UP)
	{
		while (nbr[i])
			ft_toupper(&nbr[i++]);
	}
	len = write(1, nbr, ft_strlen(nbr));
	free(nbr);
	if (len < 0)
		return (-1);
	return (len);
}

int	ft_putadr(void *adr)
{
	char	*nbr;
	int		len;

	nbr = ft_ptoa((uintptr_t)adr, 16);
	if (nbr == NULL)
		return (-1);
	if (write(1, "0x", 2) < 0)
	{
		free(nbr);
		return (-1);
	}
	len = write(1, nbr, ft_strlen(nbr));
	free(nbr);
	if (len < 0)
		return (-1);
	return (len + 2);
}
