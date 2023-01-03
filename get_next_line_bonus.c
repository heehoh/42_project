/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:25:42 by hujeong           #+#    #+#             */
/*   Updated: 2023/01/03 18:02:41 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	static t_list	*head;
	char			buff[BUFFER_SIZE];
	char			*one_line;
	int				check;

	check = read_check(head, fd);
	if (check == READ)
		one_line = read_loop(head, fd, buff);
	else if (check == NO)
		one_line = get_one_line(head, fd);
	else
	{
		ft_lstclear(&head);
		return (NULL);
	}
	if (one_line == NULL)
		ft_lstclear(&head);
	return (one_line);
}

int	read_check(t_list *node, int fd)
{
	ssize_t	i;

	if (node == NULL || node->fd == fd)
	{
		if (node != NULL)
			node = ft_lstnew(fd);
		if (node == NULL)
			return (ERROR);
		i = -1;
		while (++i < node->size)
			if (node->store[i] == '\n')
				return (NO);
		return (READ);
	}
	while (node->next)
	{
		if (node->next->fd == fd)
		{
			i = -1;
			while (++i < node->next->size)
				if (node->next->store[i] == '\n')
					return (NO);
			return (READ);
		}
		node = node->next;
	}
	node->next = ft_lstnew(fd);
	if (node->next == NULL)
		return (ERROR);
	return (READ);
}

char	*read_loop(t_list *node, int fd, char *buff)
{
	ssize_t	read_size;
	ssize_t	i;

	while (node->fd != fd)
		node = node->next;
	while (1)
	{
		read_size = read(fd, buff, BUFFER_SIZE);
		node->store = line_store(node, buff, read_size);
		if (node->store == NULL)
			return (NULL);
		i = -1;
		while (++i < read_size)
			if (buff[i] == '\n')
				break ;
		if (i == read_size && read_size == BUFFER_SIZE)
			continue ;
		return (get_one_line(node, fd));
	}
}

char	*get_one_line(t_list *node, int fd)
{
	char	*one_line;

	while (node->fd != fd)
		node = node->next;
	one_line = make_oneline(node);
	if (one_line == NULL)
		return (NULL);
	if (trim_store(node, -1, -1))
		return (NULL);
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