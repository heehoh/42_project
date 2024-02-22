/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:37:52 by hujeong           #+#    #+#             */
/*   Updated: 2022/10/20 17:59:05 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		len;
	char	*tem;

	len = 0;
	while (tab[len])
		++len;
	while (len - 1)
	{
		i = 0;
		while (i < len -1)
		{
			if ((*cmp)(tab[i], tab[i + 1]) > 0)
			{
				tem = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tem;
			}
			++i;
		}
		--len;
	}
}	
