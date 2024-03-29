/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:55:47 by hujeong           #+#    #+#             */
/*   Updated: 2022/10/15 09:47:38 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	long long	i;

	if (nb < 2)
		return (0);
	i = 2;
	while (i * i <= (long long)nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}
