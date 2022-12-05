/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:51:14 by hujeong           #+#    #+#             */
/*   Updated: 2022/12/02 12:37:20 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

void	varfunc(char *hi, ...)
{
	va_list ap;

	va_start(ap, hi);
	printf("%d", va_arg(ap, int));
	printf("\n");
	printf("%d\n", va_arg(ap, int));
	printf("%s\n", va_arg(ap, char*));
}

int	main()
{
	varfunc("hihi", 12, 128, "hello");
}
