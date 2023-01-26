/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:09:12 by hujeong           #+#    #+#             */
/*   Updated: 2023/01/11 10:26:58 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

int	check_type(const char c, va_list *ap)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_putchar(va_arg(*ap, int));
	else if (c == 's')
		len = ft_putstr(va_arg(*ap, char *));
	else if (c == 'd' || c == 'i')
		len = ft_putnbr(va_arg(*ap, int));
	else if (c == 'u')
		len = ft_putnbr(va_arg(*ap, unsigned int));
	else if (c == 'x')
		len = ft_puthex(va_arg(*ap, unsigned int), LOW);
	else if (c == 'X')
		len = ft_puthex(va_arg(*ap, unsigned int), UP);
	else if (c == 'p')
		len = ft_putadr(va_arg(*ap, void *));
	else if (c == '%')
		len = write(1, "%", 1);
	else
		return (-1);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	i;
	int		len;
	int		check;

	va_start(ap, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
			check = check_type(format[++i], &ap);
		else
			check = write(1, &format[i], 1);
		if (check < 0)
			return (-1);
		++i;
		len += check;
	}
	va_end(ap);
	return (len);
}
