/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:13:37 by hujeong           #+#    #+#             */
/*   Updated: 2023/01/11 10:28:19 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*s;

	s = (char *)haystack;
	if (needle[0] == 0)
		return (s);
	i = 0;
	while (s[i] && i < len)
	{
		j = 0;
		while (s[i + j] == needle[j] && i + j < len)
		{
			++j;
			if (needle[j] == '\0')
				return (&s[i]);
		}
		++i;
	}
	return (0);
}
