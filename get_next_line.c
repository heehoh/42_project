/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:25:42 by hujeong           #+#    #+#             */
/*   Updated: 2022/12/23 13:02:51 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	static char		*store;
	static ssize_t	store_size;
	char			buff[BUFFER_SIZE];
	char			*one_line;
	int				check;

	check = read_check(store);
	if (check == READ)
		one_line = read_loop(&store, &store_size, fd, buff);
	else
		one_line = get_one_line(&store, &store_size);
	return (one_line);
}

int	read_check(char	*store)
{
	size_t	i;

	if (store == NULL)
		return (READ);
	i = -1;
	while (store[++i])
		if (store[i] == '\n')
			return (NO);
	return (READ);
}

char	*read_loop(char **store, ssize_t *store_size, int fd, char *buff)
{
	ssize_t	read_size;
	ssize_t	i;

	while (1)
	{
		read_size = read(fd, buff, BUFFER_SIZE);
		*store = line_store(store, store_size, buff, read_size);
		if (*store == NULL)
			return (NULL);
		i = -1;
		while (++i < read_size)
			if (buff[i] == '\n')
				break ;
		if (i == read_size && read_size == BUFFER_SIZE)
			continue ;
		return (get_one_line(store, store_size));
	}
}

char	*get_one_line(char **store, ssize_t *store_size)
{
	char	*one_line;

	one_line = make_oneline(store, store_size);
	if (one_line == NULL)
		return (NULL);
	trim_store(store, store_size, -1, -1);
	return (one_line);
}
/*
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int	fd;
	int	i;

	fd = open("only_nl.txt", O_RDONLY);
	i = 0;
	while (i++ < 1)
		printf("%s", get_next_line(fd));
}*/
