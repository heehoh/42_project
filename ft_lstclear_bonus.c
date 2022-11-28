/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:23:28 by hujeong           #+#    #+#             */
/*   Updated: 2022/11/28 15:32:41 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tem;

	if (lst == 0 || del == 0)
		return ;
	while (*lst)
	{
		tem = (*lst)->next;
		(*lst)->next = 0;
		ft_lstdelone(*lst, del);
		*lst = tem;
	}
	lst = 0;
}
