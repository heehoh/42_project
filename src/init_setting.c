/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_setting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:55:44 by hujeong           #+#    #+#             */
/*   Updated: 2023/03/22 14:48:39 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "../libft/libft.h"
#include <stdio.h>

void	set_signal(void);

void	init_pwd(t_env *env, t_current *current)
{
	while (env)
	{
		if (ft_strncmp(env->var, "PWD=", 4) == 0)
		{
			free(env->var);
			env->var = ft_strjoin("PWD=", current->path);
			if (env->var == NULL)
				error_malloc();
			return ;
		}
		if (env->next == NULL)
		{
			env->next = (t_env *)malloc(sizeof(t_env));
			if (env->next == NULL)
				error_malloc();
			env->next->var = ft_strjoin("PWD=", current->path);
			if (env->next->var == NULL)
				error_malloc();
			return ;
		}
		env = env->next;
	}
}

void	init_setting(char **env, t_env **env_list, t_current *current)
{
	*env_list = get_env_list(env);
	current->path = (char *)malloc(sizeof(char) * 4096);
	if (current->path == NULL)
		error_malloc();
	if (getcwd(current->path, 4096) == NULL)
	{
		perror(INITERR);
		current->path[0] = '\0';
	}
	else
		init_pwd(*env_list, current);
	current->status = 0;
	set_signal();
}
