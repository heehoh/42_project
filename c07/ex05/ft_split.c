/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:36:54 by hujeong           #+#    #+#             */
/*   Updated: 2022/10/18 18:14:35 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		++i;
	}
	return (0);
}

int	ft_word_count(char *str, char *charset)
{
	int	word;

	word = 0;
	while (*str)
	{
		if (is_sep(*str, charset))
			++str;
		else
		{
			while (*str)
			{
				if (is_sep(*str, charset))
					break ;
				++str;
			}
			++word;
		}
	}
	return (word);
}

char	*ft_save_str(char *str, char *charset, int letter, int i)
{
	char	*strs;

	while (str[i])
	{
		if (is_sep(str[i], charset))
			++i;
		else
		{
			++letter;
			++i;
			if (is_sep(str[i], charset))
				break ;
		}
	}
	strs = (char *)malloc(sizeof(char) * letter + 1);
	if (strs == NULL)
		return (0);
	strs[letter] = '\0';
	while (letter >= 1)
		strs[--letter] = str[--i];
	return (strs);
}

char	*ft_move_str(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_sep(str[i], charset))
			++i;
		else
		{
			++i;
			if (is_sep(str[i], charset))
				break ;
		}	
	}
	return (&str[i]);
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	int		word;
	int		i;

	word = ft_word_count(str, charset);
	strs = (char **)malloc(sizeof(char *) * (word + 1));
	if (strs == NULL)
		return (0);
	i = 0;
	while (i < word)
	{		
		strs[i] = ft_save_str(str, charset, 0, 0);
		str = ft_move_str(str, charset);
		++i;
	}
	strs[i] = 0;
	return (strs);
}
