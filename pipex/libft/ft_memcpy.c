/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:10:02 by hujeong           #+#    #+#             */
/*   Updated: 2023/01/11 10:26:21 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ds;
	unsigned char	*sr;
	size_t			i;

	if (dst == 0 && src == 0)
		return (0);
	ds = (unsigned char *)dst;
	sr = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		ds[i] = sr[i];
		++i;
	}
	return (dst);
}
