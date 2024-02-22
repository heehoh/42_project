/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:38:46 by hujeong           #+#    #+#             */
/*   Updated: 2022/11/24 17:01:14 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	is_set(char s, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (s == set[i])
			return (1);
		++i;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	int		i;
	char	*str;

	len = ft_strlen(s1);
	if (len == 0)
		return (ft_strdup(""));
	i = 0;
	while (is_set(s1[i], set))
		++i;
	while (is_set(s1[len - 1], set))
		--len;
	if (len > i)
		str = (char *)malloc(len - i + 1);
	else
	{
		str = (char *)ft_calloc(1, 1);
		return (str);
	}
	if (str == 0)
		return (0);
	str[len - i] = '\0';
	while (--len >= i)
		str[len - i] = s1[len];
	return (str);
}
