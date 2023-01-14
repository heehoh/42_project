/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:57:48 by hujeong           #+#    #+#             */
/*   Updated: 2023/01/14 17:57:40 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*line_store(t_list *node, char *buff, ssize_t rd_size)
{
	ssize_t	i;
	char	*new_store;	

	new_store = (char *)malloc(node->size + rd_size + 1);
	if (new_store == NULL)
		return (NULL);
	i = -1;
	while (++i < node->size)
		new_store[i] = node->store[i];
	--i;
	while (++i < node->size + rd_size)
		new_store[i] = buff[i - node->size];
	node->size += rd_size;
	new_store[node->size] = '\0';
	if (node->store != NULL)
		free(node->store);
	return (new_store);
}

char	*make_oneline(t_list *node)
{
	ssize_t	i;
	ssize_t	j;
	char	*one_line;

	i = -1;
	while (node->store[++i])
		if (node->store[i] == '\n')
			break ;
	if (node->store[i] == '\n')
		++i;
	one_line = (char *)malloc(i + 1);
	if (one_line == NULL)
		return (NULL);
	j = -1;
	while (++j < i)
		one_line[j] = node->store[j];
	one_line[j] = '\0';
	return (one_line);
}

int	trim_store(t_list *node, ssize_t i, ssize_t j)
{
	char	*new_store;

	while (node->store[++i])
		if (node->store[i] == '\n')
			break ;
	if (node->store[i] == '\n')
		++i;
	if (node->store[i] == '\0')
	{
		free(node->store);
		node->store = NULL;
		node->size = 0;
		return (0);
	}
	new_store = (char *)malloc(node->size - i + 1);
	if (new_store == NULL)
		return (ERROR);
	while (node->store[++j + i])
		new_store[j] = node->store[j + i];
	new_store[j] = '\0';
	node->size = j;
	free(node->store);
	node->store = new_store;
	return (0);
}

t_list	*ft_lstnew(t_list *prev, int fd)
{
	t_list	*new;

	if (fd < 0)
		return (NULL);
	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->fd = fd;
	new->size = 0;
	new->store = NULL;
	new->prev = prev;
	new->next = NULL;
	return (new);
}

void	*ft_lstclear(t_list **head)
{
	t_list	*tem;

	if (head == NULL)
		return (NULL);
	while (*head)
	{
		tem = (*head)->next;
		if ((*head)->store != NULL)
			free((*head)->store);
		free(*head);
		*head = tem;
	}
	return (NULL);
}
