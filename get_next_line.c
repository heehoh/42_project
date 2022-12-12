/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:26:55 by hujeong           #+#    #+#             */
/*   Updated: 2022/12/12 20:21:35 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	buff_store(t_list *line, char *buff, int fd)
{
	t_list	*new;

	while (line->next)
	{
		if (line->s_fd == fd)
			break ;
		line = line->next;
	}
	if (line->s_fd != fd)
	{
		line->next = new;
		new->s_fd = fd;
		new->store = buff;
	}
	else
	{
		line->store = ft_strjoin(line->store, buff);
		if (line->store == NULL)
			return (-1);
	}
	return (0);
}

char	*get_one_line(t_list *line, char *buff, int fd)
{

}

char	*get_next_line(int fd)
{
	static t_list	*line;
	char			buff[BUFF_SIZE + 1];
	char			*one_line
	ssize_t 		read_size;
	size_t			i;

	while (1)
	{

		read_size = read(fd, buff, BUFF_SIZE);
		if (read_size < 0)
			return (0);
		i = 0;
		buff[read_size] = '\0';
		while (i < read_size)
			if (buff[i++] == '\n')
				break ;
		if (buff[i - 1] == '\n' || read_size != BUFF_SIZE)
		{
			one_line = get_one_line(line, buff, i);
			if (buff[i - 1] == '\n' && read_size == BUFF_SIZE)
				if (buff_store(line, &buff[i], fd) < 0)
					return (0);
			break ;
		}
		if (buff_store(one_line, buff, fd) < 0)
			return (0);
	}
	return (one_line);
}
