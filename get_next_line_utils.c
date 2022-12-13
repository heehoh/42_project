/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:47:09 by hujeong           #+#    #+#             */
/*   Updated: 2022/12/13 17:55:19 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	if (s1 != NULL)
		free(s1);
	s1 = NULL;
	return (str);
}

t_list	*ft_lstnew(int fd)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->fd = fd;
	new->store = NULL;
	new->next = NULL;
	return (new);
}

char	*one_line_trim(char **store, ssize_t i, ssize_t j)
{
	char	*one_line;
	char	*new_store;
	ssize_t	len;

	while ((*store)[i])
		if ((*store)[i++] == '\n')
			break ;
	one_line = (char *)malloc(i);
	if (one_line == NULL)
		return (NULL);
	while (++j < i)
		one_line[j] = (*store)[j];
	len = ft_strlen(*store);
	new_store = (char *)malloc(len - i + 1);
	if (new_store == NULL)
	{
		free(one_line);
		return (NULL);
	}
	j = -1;
	while (++j <= len - i)
		new_store[j] = (*store)[j + i];
	free(*store);
	*store = new_store;
	return (one_line);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = s;
	i = 0;
	while (i < n)
		str[i++] = 0;
}
