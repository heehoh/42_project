/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:49:18 by hujeong           #+#    #+#             */
/*   Updated: 2022/10/18 20:28:41 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);

int	ft_base_count(char *base);

int	ft_invalid_base(char *base, int base_n);

int	ft_count_place(int nb, int base_n)
{
	int	place;

	place = 0;
	if (nb == 0)
		++place;
	while (nb)
	{
		nb /= base_n;
		++place;
	}
	return (place);
}

char	*ft_nb_to_base(int nb, int base_n, int place, char *base_to)
{
	char	*nbr_to;

	nbr_to = (char *)malloc(sizeof(char) * place + 2);
	if (nbr_to == NULL)
		return (0);
	if (nb < 0)
	{
		nbr_to[0] = '-';
		nbr_to[place] = base_to[-(nb % base_n)];
		nbr_to[place + 1] = '\0';
		nb = -(nb / base_n);
	}
	else
	{	
		if (nb == 0)
			nbr_to[0] = base_to[0];
		nbr_to[place] = '\0';
	}
	while (nb)
	{
		nbr_to[place - 1] = base_to[nb % base_n];
		nb /= base_n;
		--place;
	}
	return (nbr_to);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;
	int		base_n;
	int		place;
	char	*nbr_to;

	base_n = ft_base_count(base_from);
	if (base_n == 0 || base_n == 1 || ft_invalid_base(base_from, base_n))
		return (0);
	base_n = ft_base_count(base_to);
	if (base_n == 0 || base_n == 1 || ft_invalid_base(base_to, base_n))
		return (0);
	nb = ft_atoi_base(nbr, base_from);
	place = ft_count_place(nb, base_n);
	nbr_to = ft_nb_to_base(nb, base_n, place, base_to);
	return (nbr_to);
}
