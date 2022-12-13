/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:47:23 by hujeong           #+#    #+#             */
/*   Updated: 2022/12/13 17:54:59 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define READ 1
# define NO 0
# define ERROR -1

# include <sys/types.h>
# include <stdlib.h>

typedef struct s_list
{
	int				fd;
	char			*store;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
char	*get_one_line(t_list *line, int fd);
char	*read_loop(t_list *line, int fd, char *buff, ssize_t read_size);
int		read_check(t_list *line, int fd);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
t_list	*ft_lstnew(int fd);
char	*one_line_trim(char **store, ssize_t i, ssize_t j);
void	ft_bzero(void *s, size_t n);

#endif
