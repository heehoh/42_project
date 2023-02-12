/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:05:38 by hujeong           #+#    #+#             */
/*   Updated: 2023/02/12 13:46:43 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] == c)
			++i;
		else
		{
			while (s[i] != c && s[i])
				++i;
			++word;
		}
	}
	return (word);
}

static char	*save_str(char *str, char c, int letter, int i)
{
	char	*strs;

	while (str[i])
	{
		if (str[i] == c)
			++i;
		else
		{
			++letter;
			++i;
			if (str[i] == c)
				break ;
		}
	}
	strs = (char *)malloc(sizeof(char) * letter + 1);
	if (strs == NULL)
		return (NULL);
	strs[letter] = '\0';
	while (letter >= 1)
		strs[--letter] = str[--i];
	return (strs);
}

static char	*move_str(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			++i;
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
	word = count_word(str, c);
	strs = (char **)malloc(sizeof(char *) * (word + 1));
	if (strs == NULL)
		return (NULL);
	i = -1;
	while (++i < word)
	{		
		strs[i] = save_str(str, c, 0, 0);
		if (strs[i] == NULL)
		{
			while (i >= 0)
				free(strs[i--]);
			free(strs);
			return (0);
		}
		str = move_str(str, c);
	}
	strs[i] = 0;
	return (strs);
}
