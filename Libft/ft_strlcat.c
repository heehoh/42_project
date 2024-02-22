/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:11:00 by hujeong           #+#    #+#             */
/*   Updated: 2022/11/23 12:49:37 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i])
		++i;
	if (i > dstsize)
		return (ft_strlen(src) + dstsize);
	while (src[j] && i + j + 1 < dstsize)
	{
		dst[i + j] = src[j];
		++j;
	}
	dst[i + j] = '\0';
	while (src[j])
		++j;
	return (i + j);
}
