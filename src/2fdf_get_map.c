/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2fdf_get_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:41:37 by hujeong           #+#    #+#             */
/*   Updated: 2023/01/19 17:18:17 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fdf.h"

static char		*get_map_loop(t_vars *vars, char *store, int fd);
static int		count_nb(char *line);
static void		move_if_color(char **line);

void	get_map(t_vars *vars, t_map **map, t_map **show, char *argv)
{
	char	*line;
	char	*store;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		error_msg(4);
	line = get_next_line(fd);
	if (line == NULL)
		error_msg(5);
	vars->width = count_nb(line);
	vars->height = 1;
	store = get_map_loop(vars, line, fd);
	*map = (t_map *)malloc(sizeof(t_map) * (vars->width * vars->height));
	if (*map == NULL)
	{
		free(store);
		error_msg(3);
	}
	set_map(vars, *map, store);
	free(store);
	*show = (t_map *)malloc(sizeof(t_map) * (vars->width * vars->height));
}

static char	*get_map_loop(t_vars *vars, char *store, int fd)
{
	char	*tem;
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (vars->width != count_nb(line))
		{
			free(line);
			free(store);
			error_msg(2);
		}
		tem = ft_strjoin(store, line);
		free(store);
		free(line);
		if (tem == NULL)
			error_msg(3);
		store = tem;
		++(vars->height);
	}
	return (store);
}

static int	count_nb(char *line)
{
	int	count;

	count = 0;
	while (*line)
	{
		while (*line == ' ' || (*line >= 9 && *line <= 13))
			++line;
		if (*line == '\0')
			break ;
		if (*line == '-' || *line == '+')
			++line;
		if (*line < '0' || *line > '9')
			error_msg(2);
		while (*line >= '0' && *line <= '9')
		++line;
		if (*line == ',')
		{
			++line;
			move_if_color(&line);
		}
		++count;
	}
	return (count);
}

static void	move_if_color(char **line)
{
	if (**line == '0' && (*(*line + 1) == 'x' || *(*line + 1) == 'X'))
		*line = *line + 2;
	else
		error_msg(2);
	while ((**line >= '0' && **line <= '9')
		|| (**line >= 'a' && **line <= 'f')
		|| (**line >= 'A' && **line <= 'F'))
			++(*line);
}
