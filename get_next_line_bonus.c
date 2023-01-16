/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:25:42 by hujeong           #+#    #+#             */
/*   Updated: 2023/01/16 11:50:12 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>

char	*get_next_line(int fd)
{
	static t_list	*head;
	char			buff[BUFFER_SIZE];
	char			*one_line;
	int				check;

	if (head == NULL)
		head = ft_lstnew(NULL, fd);
	if (head == NULL)
		return (NULL);
	check = read_check(head, fd, 0);
	if (check == READ)
		one_line = read_loop(&head, head, fd, buff);
	else if (check == NO)
		one_line = get_one_line(&head, head, fd);
	else
		return (ft_lstclear(&head));
	return (one_line);
}

int	read_check(t_list *node, int fd, ssize_t i)
{
	if (node->fd == fd)
	{
		while (i < node->size)
			if (node->store[i++] == '\n')
				return (NO);
		return (READ);
	}
	while (node->next)
	{
		if (node->next->fd == fd)
		{
			while (i < node->next->size)
				if (node->next->store[i++] == '\n')
					return (NO);
			return (READ);
		}
		node = node->next;
	}
	node->next = ft_lstnew(node, fd);
	if (node->next == NULL)
		return (ERROR);
	return (READ);
}

char	*read_loop(t_list **head, t_list *node, int fd, char *buff)
{
	ssize_t	read_size;
	ssize_t	i;

	while (node->fd != fd)
		node = node->next;
	while (1)
	{
		read_size = read(fd, buff, BUFFER_SIZE);
		if (read_size < 0 || (read_size == 0 && node->size == 0))
			return (ft_lstcut(head, node));
		node->store = line_store(node, buff, read_size);
		if (node->store == NULL)
			return (ft_lstclear(head));
		i = -1;
		while (++i < read_size)
			if (buff[i] == '\n')
				break ;
		if (i == read_size && read_size == BUFFER_SIZE)
			continue ;
		return (get_one_line(head, node, fd));
	}
}

char	*get_one_line(t_list **head, t_list *node, int fd)
{
	char	*one_line;

	while (node->fd != fd)
		node = node->next;
	one_line = make_oneline(node);
	if (one_line == NULL)
		return (ft_lstclear(head));
	if (trim_store(head, node, -1, -1))
		return (ft_lstclear(head));
	return (one_line);
}

void	*ft_lstcut(t_list **head, t_list *node)
{
	t_list	*tem;

	if (*head == node)
	{
		if (node->next != NULL)
			tem = node->next;
		else
			tem = NULL;
		if (node->store != NULL)
			free(node->store);
		node->store = NULL;
		free(node);
		*head = tem;
		return (NULL);
	}
	tem = node->prev;
	tem->next = node->next;
	if (node->store != NULL)
		free(node->store);
	node->store = NULL;
	free(node);
	node = tem;
	return (NULL);
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