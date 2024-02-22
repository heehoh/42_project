/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:14:19 by hujeong           #+#    #+#             */
/*   Updated: 2022/11/23 18:05:48 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	int		i;
	char	*str;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(len1 + len2 + 1);
	if (str == 0)
		return (0);
	i = 0;
	while (i < len1)
	{
		str[i] = s1[i];
		++i;
	}
	while (i < len1 + len2)
	{
		str[i] = s2[i - len1];
		++i;
	}
	str[i] = '\0';
	return (str);
}
