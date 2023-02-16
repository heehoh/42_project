/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:25:32 by hujeong           #+#    #+#             */
/*   Updated: 2023/02/16 16:19:50 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	print_malloc_error(void)
{
	write(STDERR_FILENO, "malloc fail\n", 12);
	exit(EXIT_FAILURE);
}

void	print_error(void)
{
	write(STDERR_FILENO, "error\n", 6);
	exit(EXIT_FAILURE);
}
