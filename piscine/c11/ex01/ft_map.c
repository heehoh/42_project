/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:10:56 by hujeong           #+#    #+#             */
/*   Updated: 2022/10/20 19:54:30 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*a;

	a = (int *)malloc(sizeof(int) * length);
	i = 0;
	while (i < length)
	{
		a[i] = (*f)(tab[i]);
		++i;
	}
	return (a);
}
