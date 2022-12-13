/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:26:55 by hujeong           #+#    #+#             */
/*   Updated: 2022/12/13 18:35:44 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*get_next_line(int fd)
{
	static t_list	*line;
	char			buff[BUFFER_SIZE + 1];
	char			*one_line;
	ssize_t			check;

	check = read_check(line, fd);
	if (check == READ)
		one_line = read_loop(line, fd, buff, -1);
	else if (check == NO)
		one_line = get_one_line(line, fd);
	else
		one_line = NULL;
	ft_bzero(buff, BUFFER_SIZE);
	return (one_line);
}

int	read_check(t_list *line, int fd)
{
	ssize_t	i;

	while (line)
	{
		if (line->fd == fd)
		{
			if (line->store == NULL)
				return (READ);
			i = 0;
			while (line->store[i])
				if (line->store[i++] == '\n')
					return (NO);
			return (READ);
		}
		line = line->next;
	}
	return (READ);
}

char	*read_loop(t_list *line, int fd, char *buff, ssize_t i)
{
	ssize_t	read_size;

	while (1)
	{
		read_size = read(fd, buff, BUFFER_SIZE);
		if (read_size < 0)
			return (NULL);
		buff[read_size] = '\0';
		if (line == NULL)
			line = ft_lstnew(fd);
		while (1)
		{
			if (line->fd == fd)
				break ;
			if (line->next == NULL)
				line->next = ft_lstnew(fd);
			line = line->next;
		}
		line->store = ft_strjoin(line->store, buff);
		while (line->store[++i])
			if (line->store[i] == '\n')
				break ;
		if (line->store[i] == '\n' || read_size < BUFFER_SIZE)
			return (one_line_trim(&(line->store), 0, -1));
	}
}

char	*get_one_line(t_list *line, int fd)
{
	while (1)
	{
		if (line->fd == fd)
			break ;
		line = line->next ;
	}
	return (one_line_trim(&(line->store), 0, -1));
}
/*
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int	fd;
	int	i;

	fd = open("hello.txt", O_RDONLY);
	i = 0;
	while (i++ < 10)
		printf("%s", get_next_line(fd));
}*/
