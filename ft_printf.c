/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:09:12 by hujeong           #+#    #+#             */
/*   Updated: 2022/12/05 13:50:04 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		c = '0' + n % 10;
		write(fd, &c, 1);
	}
	else
	{
		c = '0' + n;
		write(fd, &c, 1);
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	check_conversion(char c, va_list ap)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(ap, int), 1);
	else if (c == 'd')
		ft_putnbr_fd(va_arg(ap, int), 1);
	else
		return;
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		letter;

	va_start(ap, format);
	i = 0;
	letter = 0;
	while (format[i])
	{
		if (format[i] == '%')
			check_conversion(format[++i], ap);
		else
			write(1, &format[i], 1);
		++i;
		++letter;
	}
	va_end(ap);
	return (letter);
}

int	main(void)
{
	char	k = 'h';

	ft_printf("hihihih %d i  %c  i %d \n", 2222222222222222, k, 222222222222222);
}
