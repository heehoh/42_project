/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:47:09 by hujeong           #+#    #+#             */
/*   Updated: 2022/12/12 20:21:39 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(char *s)
{
	size_t	len;
	
	if (s == NULL)
		return (0);
	len = 0;
	while (s[len])
		++len;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	char	*str;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(len1 + len2 + 1);
	if (str == NULL)
		return (NULL);
	i = -1;
	while (++i < len1)
		str[i] = s1[i];
	i -= 1;
	while (++i < len1 + len2)
		str[i] = s2[i - len1];
	str[i] = '\0';
	free(s1);
	s1 = NULL;
	return (str);
}
