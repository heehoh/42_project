/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:11:58 by hujeong           #+#    #+#             */
/*   Updated: 2022/12/05 14:30:57 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

#define hi(s) (s += 1) 

void	move(char **s)
{
	hi(*s);
}

int	main(void)
{
	char *s = "hello";
	move(&s);
	write(1, s, 1);
}
