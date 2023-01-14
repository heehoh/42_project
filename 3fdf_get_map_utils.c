/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3fdf_get_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:13:48 by hujeong           #+#    #+#             */
/*   Updated: 2023/01/14 15:34:00 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void move_after_atoi(char **store, t_map *map, int *count);
static void move_if_color(char **line);

void	get_xyz(t_vars *vars, t_map *map, char *store)
{
    int     count;

    count = 0;
    map[0].x = 0;
    map[0].y = 0;
    map[0].z = ft_atoi(store);
    move_after_atoi(&store, map, &count);
    while (++count < vars->width * vars->height)
    {
        map[count].x = map[count - 1].x + 1;
        if (map[count].x == vars->width)
        {
            map[count].x = 0;
            map[count].y = map[count - 1].y + 1;
        }
        else
            map[count].y = map[count - 1].y;
        map[count].z = ft_atoi(store);
        move_after_atoi(&store, map, &count); 
    }
}

int count_nb(char *line)
{
    int count;

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

static void move_after_atoi(char **store, t_map *map, int *count)
{
    while (**store == ' ' || (**store >= 9 && **store <= 13))
		++(*store);
    if (**store == '-' || **store == '+')
        ++(*store);
	while (**store >= '0' && **store <= '9')
            ++(*store);
    if (**store == ',')
    {
        ++(*store);
        map[*count].color = ft_atoi(*store);
        move_if_color(store);
    }
    else
        map[*count].color = 0x77FFFFFF;
}

static void move_if_color(char **line)
{
    if (**line == '0' && (*(*line + 1) == 'x' || *(*line + 1) == 'X'))
        *line = *line + 2;
    else
        error_msg(2);
    while ((**line >= '0' && **line <= '9') ||
			(**line >= 'a' && **line <= 'f') ||
			(**line >= 'A' && **line <= 'F'))
            ++(*line);
}