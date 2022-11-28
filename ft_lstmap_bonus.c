/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:52:19 by hujeong           #+#    #+#             */
/*   Updated: 2022/11/28 14:53:08 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tem;
	void	*ptr;

	if (lst == 0 || f == 0 || del == 0)
		return (0);
	new = 0;
	while (lst)
	{
		ptr = f(lst->content);
		tem = ft_lstnew(ptr);
		if (tem == 0)
		{
			del(ptr);
			if (new != 0)
				ft_lstclear(&new, del);
			return (0);
		}
		ft_lstadd_back(&new, tem);
		lst = lst->next;
	}
	return (new);
}
