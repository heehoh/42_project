/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:13:37 by hujeong           #+#    #+#             */
/*   Updated: 2022/11/23 17:50:02 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

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
