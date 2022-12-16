/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:57:48 by hujeong           #+#    #+#             */
/*   Updated: 2022/12/16 14:10:57 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

char	*line_store(char **store, ssize_t *st_size, char *buff, ssize_t rd_size)
{
	ssize_t	i;
	char	*new_store;	

	new_store = (char *)malloc(*st_size + rd_size + 1);
	if (rd_size < 0 || (*st_size == 0 && rd_size == 0) || new_store == NULL)
	{
		if (*store != NULL)
			free(*store);
		if (new_store != NULL)
			free(new_store);
		*store = NULL;
		*st_size = 0;
		return (NULL);
	}
	i = -1;
	while (++i < *st_size)
		new_store[i] = (*store)[i];
	--i;
	while (++i < *st_size + rd_size)
		new_store[i] = buff[i - *st_size];
	*st_size += rd_size;
	new_store[*st_size] = '\0';
	if (*store != NULL)
		free(*store);
	return (new_store);
}

char	*make_oneline(char **store, ssize_t *st_size)
{
	ssize_t	i;
	ssize_t	j;
	char	*one_line;

	i = -1;
	while ((*store)[++i])
		if ((*store)[i] == '\n')
			break ;
	if ((*store)[i] == '\n')
		++i;
	one_line = (char *)malloc(i + 1);
	if (one_line == NULL)
	{
		free(*store);
		*store = NULL;
		*st_size = 0;
		return (NULL);
	}
	j = -1;
	while (++j < i)
		one_line[j] = (*store)[j];
	one_line[i] = '\0';
	return (one_line);
}

void	trim_store(char **store, ssize_t *st_size, ssize_t i, ssize_t j)
{
	char	*new_store;

	while ((*store)[++i])
		if ((*store)[i] == '\n')
			break ;
	if ((*store)[i] == '\n')
		++i;
	new_store = (char *)malloc(*st_size - i + 1);
	if (new_store == NULL || (*store)[i] == '\0')
	{
		free(*store);
		if (new_store != NULL)
			free(new_store);
		*store = NULL;
		*st_size = 0;
		return ;
	}
	while ((*store)[++j + i])
		new_store[j] = (*store)[j + i];
	new_store[j] = '\0';
	*st_size = j;
	free(*store);
	*store = new_store;
}
