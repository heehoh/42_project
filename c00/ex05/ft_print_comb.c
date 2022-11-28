/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:00:13 by hujeong           #+#    #+#             */
/*   Updated: 2022/09/29 20:32:25 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

void	ft_print_comb(void)
{
	char	num[3];

	num[0] = '0';
	num[1] = '1';
	num[2] = '2';
	while (num[0] <= '7')
	{
		while (num[1] <= '8')
		{
			while (num[2] <= '9')
			{
				write (1, num, 3);
				if (num[0] != '7')
					write (1, ", ", 2);
				num[2] += 1;
			}
			num[1] += 1;
			num[2] = num[1] + 1;
		}
		num[0] += 1;
		num[1] = num[0] + 1;
		num[2] = num[1] + 1;
	}
}
