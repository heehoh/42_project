/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:24:27 by hujeong           #+#    #+#             */
/*   Updated: 2022/10/20 17:42:41 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	asc;
	int	des;

	i = 0;
	asc = 0;
	des = 0;
	while (i + 1 < length)
	{
		if (f(tab[i], tab[i + 1]) >= 0)
			++des;
		if (f(tab[i], tab[i + 1]) <= 0)
			++asc;
		++i;
	}
	if (asc == i || des == i)
		return (1);
	else
		return (0);
}
