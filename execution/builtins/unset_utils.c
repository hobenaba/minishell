/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:34:49 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/06/27 17:37:06 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	free_args(t_env *temp)
{
	free(temp->env);
	free(temp->value);
	free(temp);
}

void	ft_remove_if(t_env **head, void *data)
{
	t_env	*current;
	t_env	*previous;
	t_env	*temp;

	current = *head;
	previous = NULL;
	while (current != NULL)
	{
		if (ft_strcmp(current->env, data) == 0)
		{
			if (previous == NULL)
				*head = current->next;
			else
				previous->next = current->next;
			temp = current;
			current = current->next;
			free_args(temp);
		}
		else
		{
			previous = current;
			current = current->next;
		}
	}
}
