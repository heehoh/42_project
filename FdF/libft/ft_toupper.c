/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:29:18 by hujeong           #+#    #+#             */
/*   Updated: 2023/01/02 16:05:39 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_toupper(char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 'a' + 'A';
}