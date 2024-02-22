/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 20:32:44 by hujeong           #+#    #+#             */
/*   Updated: 2022/12/09 15:39:52 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdint.h>

# define LOW 0
# define UP 1

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(const char *s);
int		ft_putnbr(long long n);
int		ft_puthex(unsigned int hex, int up_low);
int		ft_putadr(void *adr);
char	*ft_itoa(long long n, int base_l);
char	*ft_ptoa(uintptr_t n, int base_l);
size_t	ft_strlen(const char *s);
void	ft_toupper(char *c);

#endif
