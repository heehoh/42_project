/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:05:38 by hujeong           #+#    #+#             */
/*   Updated: 2023/01/26 18:17:45 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c, int word)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			++i;
		else if (s[i] == '\'' || s[i] == '\"')
		{
			++i;
			while (s[i] != '\'' && s[i] != '\"' && s[i] != '\0')
				++i;
			if (s[i])
				++i;
			++word;
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

static char	*save_str_utils(char *s)
{
	char	*str;
	int		letter;
	int		i;

	++s;
	i = 0;
	letter = 0;
	while (s[i] != '\'' && s[i] != '\"' && s[i] != '\0')
	{
		++i;
		++letter;
	}
	str = (char *)malloc(sizeof(char) * letter + 1);
	if (str == NULL)
		return (NULL);
	str[letter] = '\0';
	while (letter >= 1)
		str[--letter] = s[--i];
	return (str);
}

static char	*save_str(char *s, char c, int letter, int i)
{
	char	*str;

	while (s[i])
	{
		if (s[i] == c)
			++i;
		else if (s[i] == '\'' || s[i] == '\"')
			return (save_str_utils(&(s[i])));
		else
		{
			++letter;
			++i;
			if (s[i] == c)
				break ;
		}
	}
	str = (char *)malloc(sizeof(char) * letter + 1);
	if (str == NULL)
		return (NULL);
	str[letter] = '\0';
	while (letter >= 1)
		str[--letter] = s[--i];
	return (str);
}

static char	*move_str(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			++i;
		else if (str[i] == '\'' || str[i] == '\"')
		{
			++i;
			while (str[i] != '\'' && str[i] != '\"' && str[i] != '\0')
				++i;
			if (str[i])
				++i;
			break ;
		}
		else
		{
			++i;
			if (str[i] == c)
				break ;
		}	
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
	if (strs == NULL)
		return (NULL);
	i = -1;
	while (++i < word)
	{		
		strs[i] = save_str(str, c, 0, 0);
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
