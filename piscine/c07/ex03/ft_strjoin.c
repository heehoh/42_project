/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:22:04 by hujeong           #+#    #+#             */
/*   Updated: 2022/10/18 20:11:57 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_length(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_str_space(int size, char **strs, char *sep)
{
	int		i;
	int		str_len;
	char	*str;

	i = 0;
	str_len = 0;
	if (size > 0)
	{
		while (i < size)
			str_len += ft_length(strs[i++]);
		str_len += ft_length(sep) * (size - 1);
	}
	str = (char *)malloc(sizeof(char) * str_len + 1);
	return (str);
}

char	*ft_strcat(char *dest, char *src, int size)
{
	if (size == 0)
		return (dest);
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	char	*a;
	int		i;

	if (size < 0)
		return (0);
	else
	{
		str = ft_str_space(size, strs, sep);
		a = str;
		if (str == NULL)
			return (0);
		if (size > 0)
		{
			a = ft_strcat(str, strs[0], size);
			i = 1;
			while (i < size)
			{
				a = ft_strcat(a, sep, size);
				a = ft_strcat(a, strs[i++], size);
			}
		}
		*a = '\0';
		return (str);
	}
}
