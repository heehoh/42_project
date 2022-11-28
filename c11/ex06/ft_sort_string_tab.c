/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:56:00 by hujeong           #+#    #+#             */
/*   Updated: 2022/10/20 17:52:26 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	unsigned char	*str1;
	unsigned char	*str2;
	int				i;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (str1[i] - str2[i]);
}

void	ft_sort_string_tab(char **tab)
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
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
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
