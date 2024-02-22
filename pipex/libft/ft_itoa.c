/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:06:13 by hujeong           #+#    #+#             */
/*   Updated: 2023/01/11 10:24:59 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_nbr(char *nbr, long long n, size_t len, int base_l)
{
	char	*base;

	base = "0123456789abcdef";
	nbr[len] = '\0';
	if (n < 0)
	{
		nbr[0] = '-';
		nbr[--len] = base[-(n % base_l)];
		n = -(n / base_l);
	}
	else if (n == 0)
		nbr[0] = '0';
	while (n)
	{
		nbr[--len] = base[n % base_l];
		n /= base_l;
	}
}

char	*ft_itoa(long long n, int base_l)
{
	char		*nbr;
	long long	nb;
	size_t		len;

	nb = n;
	len = 0;
	if (nb <= 0)
		++len;
	while (nb)
	{
		nb /= base_l;
		++len;
	}
	nbr = (char *)malloc(len + 1);
	if (nbr == NULL)
		return (0);
	fill_nbr(nbr, n, len, base_l);
	return (nbr);
}

static void	fill_nbr2(char *nbr, uintptr_t n, size_t len, int base_l)
{
	char	*base;

	base = "0123456789abcdef";
	nbr[len] = '\0';
	if (n == 0)
		nbr[0] = '0';
	while (n)
	{
		nbr[--len] = base[n % base_l];
		n /= base_l;
	}
}

char	*ft_ptoa(uintptr_t n, int base_l)
{
	char			*nbr;
	uintptr_t		nb;
	size_t			len;

	nb = n;
	len = 0;
	if (nb == 0)
		++len;
	while (nb)
	{
		nb /= base_l;
		++len;
	}
	nbr = (char *)malloc(len + 1);
	if (nbr == NULL)
		return (0);
	fill_nbr2(nbr, n, len, base_l);
	return (nbr);
}
