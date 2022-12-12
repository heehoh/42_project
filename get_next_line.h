/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:47:23 by hujeong           #+#    #+#             */
/*   Updated: 2022/12/12 19:39:47 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

typedef struct s_list
{
	int		s_fd;
	char	*store;
	t_list	*next;
}	t_list;

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2)
#endif
