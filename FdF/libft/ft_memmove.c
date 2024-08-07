/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:16:02 by hujeong           #+#    #+#             */
/*   Updated: 2023/01/11 10:26:32 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ds;
	unsigned char	*sr;
	size_t			i;

	if (dst == 0 && src == 0)
		return (0);
	ds = dst;
	sr = (unsigned char *)src;
	i = 0;
	if (dst > src)
	{
		while (len--)
			ds[len] = sr[len];
	}
	else
	{
		while (i < len)
		{
			ds[i] = sr[i];
			++i;
		}
	}
	return (dst);
}
