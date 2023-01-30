/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:05:38 by hujeong           #+#    #+#             */
/*   Updated: 2023/01/28 17:10:55 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c, int word)
{
	int		i;
	char	tem;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			++i;
		else if (s[i] == '\'' || s[i] == '\"')
		{
			tem = s[++i - 1];
			while (s[i] != tem && s[i])
				++i;
			++word;
			if (s[i] == tem)
				++i;
		}
		else
		{
			while (s[i] != c && s[i])
				++i;
			++word;
		}
	}
	return (word);
}

static char	*save_str(char *str, char c, int i)
{
	char	*strs;
	char	tem;

	while (*str == c)
		++str;
	if (str[i] == '\'' || str[i] == '\"')
	{
		tem = str[0];
		++str;
		while (str[i] != tem && str[i])
			++i;
	}
	else
	{
		while (str[i] != c && str[i])
			++i;
	}
	strs = (char *)malloc(sizeof(char) * i + 1);
	if (strs == NULL)
		return (NULL);
	strs[i] = '\0';
	while (--i >= 0)
		strs[i] = str[i];
	return (strs);
}

static char	*move_str(char *str, char c)
{
	int		i;
	char	tem;

	i = 0;
	while (str[i] == c)
		++i;
	if (str[i] == '\'' || str[i] == '\"')
	{
		tem = str[++i - 1];
		while (str[i] != tem && str[i])
			++i;
		if (str[i] == tem)
			++i;
	}
	else
	{
		while (str[i] != c)
			++i;
	}
	return (&str[i]);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	char	*str;
	int		word;
	int		i;

	str = (char *)s;
	word = count_word(str, c, 0);
	strs = (char **)malloc(sizeof(char *) * (word + 1));
	if (strs == 0)
		return (0);
	i = -1;
	while (++i < word)
	{		
		strs[i] = save_str(str, c, 0);
		if (strs[i] == NULL)
		{
			while (--i >= 0)
				free(strs[i]);
			free(strs);
			return (0);
		}
		str = move_str(str, c);
	}
	strs[i] = NULL;
	return (strs);
}
