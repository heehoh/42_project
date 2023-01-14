/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2fdf_get_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:41:37 by hujeong           #+#    #+#             */
/*   Updated: 2023/01/14 15:02:17 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fdf.h"

static char    *get_map_loop(t_vars *vars, char *store, int fd);

void get_map(t_vars *vars, t_map **map, char *argv)
{
    char    *line;
    char    *store;
    int     fd;

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
    get_xyz(vars, *map, store);
    move_xyz(vars, *map, 30);
    free(store);
}

static char    *get_map_loop(t_vars *vars, char *store, int fd)
{
    char    *tem;
    char    *line;

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
