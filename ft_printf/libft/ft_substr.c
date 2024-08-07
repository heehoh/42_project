/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:06:09 by hujeong           #+#    #+#             */
/*   Updated: 2022/11/23 18:03:29 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;

	i = ft_strlen(s);
	if (i < start)
	{
		sub = ft_strdup("");
		return (sub);
	}
	else if (len > i - start)
		len = i - start;
	sub = (char *)malloc(len + 1);
	if (sub == 0)
		return (0);
	i = 0;
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		++i;
	}
	sub[i] = '\0';
	return (sub);
}
