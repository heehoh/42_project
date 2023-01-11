/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_get_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:41:37 by hujeong           #+#    #+#             */
/*   Updated: 2023/01/11 21:07:47 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fdf.h"

static int count_nb(char *line)
{
    int count;
    int i;

    count = 0;
    i = 0;
    while (line[i])
    {
        while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
            ++i;
        if (line[i] = '-' || line[i] = '+')
            ++i;    
        if (line[i] < '0' || line[i] > '9')
            error_msg(2);
        while (line[i] >= '0' && line[i] <= '9')
            ++i;
        ++count;
        if (line[i] == '\n' || line[i] == '\0')
            break ;
    }
    return (count);
}

static char    *get_map_loop(t_vars *vars, char *line, int fd)
{
    char    *tem;
    char    *store;
    int     count_height;

    store = line;
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

static void	get_xyz(t_vars *vars, t_map *map, char *store)
{
    int     count;

    count = 0;
    map[0].x = 0;
    map[0].y = 0;
    while (count < vars->width * vars->height)
    {
	    map[count].z = -1 * ft_atoi(store);
        map[++count] = map[count - 1] + 1;
        if (map[count].x == vars->width)
        {
            map[count].x = 0;
            map[count].y = map[count - 1].y + 1;
        }
        else
            map[count].y = map[count - 1].y
	    while (*store == ' ' || (*store >= 9 && *store <= 13))
		    ++store;
        if (*store == '-' || *store = '+')
            ++store;
	    while (*store >= '0' && *store <= '9')
            ++store;
    }
    map[count] = NULL;
}

static void move_xyz(t_vars *vars, t_map *map, int distance)
{
    int     i;
    t_dummy dummy;

    i = -1;
    while (map[++i])
    {
        map[i].x -= vars->width / 2;
        map[i].y -= vars->height / 2;
    }
    rotate(map, 30, 30, 0);
    i = -1;
    while (map[++i])
    {
        dummy.x = (map[i].x * distance) + 960;
        dummy.x = (map[i].y * distance) + 540;
        if (dummy.x < 0 || dummy.x > 1920 || dummy.x < 0 || dummy.x > 1080)
        {
            i = -1;
            distance = distance / 3 * 2;
            if (distance < 3)
                error_msg(2);
            continue ;
        }
    }
    i = -1;
    while (map[++i])
    {
        map[i].x = map[i].x * distance + 960;
        map[i].y = map[i].y * distance + 540;
    }
}

void get_map(t_vars *vars, t_map *map, char *argv)
{
    char    *line;
    char    *store;
    int     fd;

    fd = open(argv, O_RDONLY);
    if (fd < 0)
        error_msg(4);
    line = get_next_line(fd);
    vars->width = count_nb(line);
    vars->height = 1;
    if (vars->width == ERROR)
        error_msg(2);
    store = get_map_loop(vars, line, fd);
    map = (t_map *)malloc(sizeof(t_map) * (vars->width * vars->height + 1));
    if (map == NULL)
    {
        free(store);
        error_msg(3);
    }
    get_xyz(vars, map, store);
    move_xyz(vars, map, 30, -1);
    free(store);
}
