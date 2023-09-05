/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_underscore.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:48:48 by hobenaba          #+#    #+#             */
/*   Updated: 2023/06/27 20:00:26 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	add_to_under_score(t_parser *parser)
{
	char	*str;
	t_env	*node;
	t_data	*args;

	args = parser -> args;
	while (parser -> next)
		parser = parser -> next;
	if (args == NULL)
		str = parser -> cmd;
	else
	{
		while (args -> next)
			args = args -> next;
		str = args -> value;
	}
	node = ft_getenv(g_var.list, "_");
	if (node != NULL)
	{
		free(node -> value);
		node -> value = ft_strdup(str);
	}
}
