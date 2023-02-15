/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:44:15 by hujeong           #+#    #+#             */
/*   Updated: 2023/02/15 14:41:53 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

size_t		ft_strlen(const char *s);
long long	ft_atoll(const char *str);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char *s1, char const *s2);
char		**ft_split(char const *s, char c);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# define READ 1
# define NO 0
# define ERROR -1

char		*get_next_line(int fd);
int			read_check(char *store);
char		*read_loop(char **store, ssize_t *store_size, int fd, char *buff);
char		*get_one_line(char **store, ssize_t *st_size);
char		*line_store(char **store, ssize_t *st_size, char *buf,
				ssize_t rd_size);
char		*make_oneline(char **store, ssize_t *st_size);
void		trim_store(char **store, ssize_t *st_size, ssize_t i, ssize_t j);

#endif