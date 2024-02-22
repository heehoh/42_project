/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:18:45 by hujeong           #+#    #+#             */
/*   Updated: 2022/10/04 21:23:07 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap2(int *a, int *b)
{
	int	tem;

	tem = *a;
	*a = *b;
	*b = tem;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = size - 1;
	while (i > 0)
	{
		j = 0;
		while (j < i)
		{
			if (tab[j] > tab [j + 1])
				swap2(&tab[j], &tab[j + 1]);
			j++;
		}
		i--;
	}
}
