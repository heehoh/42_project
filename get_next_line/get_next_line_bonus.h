/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:05:49 by hujeong           #+#    #+#             */
/*   Updated: 2023/01/16 11:50:14 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# define READ 1
# define NO 0
# define ERROR -1

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <sys/types.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*store;
	ssize_t			size;
	int				fd;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
int		read_check(t_list *node, int fd, ssize_t i);
char	*read_loop(t_list **head, t_list *node, int fd, char *buff);
char	*get_one_line(t_list **head, t_list *node, int fd);
char	*line_store(t_list *node, char *buf, ssize_t rd_size);
char	*make_oneline(t_list *node);
int		trim_store(t_list **head, t_list *node, ssize_t i, ssize_t j);
t_list	*ft_lstnew(t_list *prev, int fd);
void	*ft_lstclear(t_list **head);
void	*ft_lstcut(t_list **head, t_list *node);

#endif
