/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:59:13 by hujeong           #+#    #+#             */
/*   Updated: 2022/10/15 14:51:25 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	long long	i;

	if (nb <= 2)
		return (2);
	while (1)
	{
		i = 2;
		while (i * i <= (long long)nb)
		{
			if (nb % i == 0)
				break ;
			i++;
		}
		if (nb % i != 0)
			break ;
		nb++;
	}
	return ((int)nb);
}
