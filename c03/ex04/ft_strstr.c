/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 19:37:29 by hujeong           #+#    #+#             */
/*   Updated: 2022/10/11 21:47:43 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (to_find[0] == 0)
		return (str);
	while (str[i] && to_find[j])
	{
		if (str[i] == to_find[j])
		{
			if (str[i + 1] == to_find[j + 1] || to_find[j + 1] == 0)
				++j;
			else
				j = 0;
		}
		++i;
	}
	if (to_find[j] == 0)
		return (&str[i - j]);
	return (0);
}
