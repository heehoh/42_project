/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:38:22 by hujeong           #+#    #+#             */
/*   Updated: 2023/03/08 13:33:11 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../../libft/libft.h"

t_env	*get_env_list(char **env)
{
	size_t	i;
	t_env	*env_list;
	t_env	*node;

	env_list = (t_env *)malloc(sizeof(t_env));
	env_list->var = ft_strdup(env[0]);
	node = env_list;
	i = 0;
	while (env[++i])
	{
		node->next = (t_env *)malloc(sizeof(t_env));
		node->next->var = ft_strdup(env[i]);
		node = node->next;
	}
	node->next = NULL;
	return (env_list);
}
