/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:38:31 by hujeong           #+#    #+#             */
/*   Updated: 2022/10/05 09:50:24 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	combn_print(char *comb, int init_n, int n)
{
	while (n < init_n)
	{
		write(1, &comb[n], 1);
		n++;
	}
	if (comb[0] != 10 - init_n + '0')
		write(1, ", ", 2);
	return ;
}

void	pick(char *comb, int init_n, int n)
{
	int		index;
	char	number;

	if (n == 0)
	{
		combn_print(comb, init_n, n);
	}
	else
	{
		index = init_n - n;
		if (index == 0)
			number = '0';
		else
			number = comb[index - 1] + 1;
		while (number <= '9')
		{
			comb[index] = number;
			pick(comb, init_n, n - 1);
			number++;
		}
	}
}

void	ft_print_combn(int n)
{
	char	comb[9];

	pick(comb, n, n);
}
