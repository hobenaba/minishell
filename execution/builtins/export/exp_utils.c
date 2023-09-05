/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 02:47:29 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/06/16 18:08:22 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	concat_value(t_env *node)
{
	t_env	*cur;
	char	*str;
	char	*name;

	name = ft_strtrim(node->env, "+");
	if (!name)
		return (1);
	free(node->env);
	node->env = name;
	cur = ft_getenv(g_var.list, node->env);
	if (cur && cur->value && (node->value[0] == '\0' || !node->value))
		return (1);
	if (cur && node->value[0] != '\0' && ft_strcmp(node->value, "\"\""))
	{
		str = ft_strjoin2(cur->value, node->value);
		if (!str)
			return (1);
		free(node->value);
		node->value = ft_strdup(str);
		free(str);
	}
	return (0);
}

int	check_export_args(t_env *new_node)
{
	int	len;
	int	check;

	len = ft_strlen(new_node->env);
	check = check_ident(new_node->env, new_node->value, len);
	if (check)
	{
		g_var.exit_status = 1;
		free(new_node->env);
		free(new_node->value);
		free(new_node);
		return (2);
	}
	if (new_node->env[len - 1] == '+')
	{
		if (concat_value(new_node))
		{
			free(new_node->env);
			free(new_node->value);
			free(new_node);
			return (3);
		}
	}	
	return (0);
}
