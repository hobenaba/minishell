/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifie_and_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 07:44:40 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/06/16 18:04:05 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	modifie_env_node(char *env, char *new_value)
{
	t_env	*cur;

	cur = g_var.list;
	while (cur)
	{
		if (!ft_strcmp(cur->env, env))
		{
			if (!new_value)
				return ;
			else if (!cur->value && (!new_value || new_value[0] == '\0'))
			{
				free(cur->value);
				cur->value = ft_strdup("");
			}
			else
			{
				free(cur->value);
				cur->value = ft_strdup(new_value);
			}
			return ;
		}
		cur = cur->next;
	}
}

void	modifie_and_add(t_env *new_env_node)
{
	if (env_search(g_var.list, new_env_node->env) != 0)
	{
		modifie_env_node(new_env_node->env, new_env_node->value);
		free(new_env_node->env);
		free(new_env_node->value);
		free(new_env_node);
		return ;
	}
	ft_lstaddback_env(&g_var.list, new_env_node);
}
