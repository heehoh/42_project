/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:49:49 by hujeong           #+#    #+#             */
/*   Updated: 2022/11/23 11:36:00 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*s;
	size_t	i;

	s = (char *)malloc(count * size);
	if (s == 0)
		return (0);
	i = 0;
	while (i < count * size)
		s[i++] = 0;
	return (s);
}
