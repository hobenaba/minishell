/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 13:38:39 by hobenaba          #+#    #+#             */
/*   Updated: 2023/06/27 18:00:41 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_env	*ft_lstnew_env(char *env, char *value)
{
	t_env	*p;

	p = malloc(sizeof (t_env));
	if (!p)
		return (NULL);
	p -> value = value;
	p -> env = env;
	p -> next = NULL;
	return (p);
}

void	ft_lstaddback_env(t_env **lst, t_env *new)
{
	t_env	*p;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	p = *lst;
	if (!p)
		return ;
	while (p-> next)
		p = p -> next;
	p -> next = new;
}

char	*check_env(char *env, t_env *my_envs)
{
	t_env	*e;

	e = my_envs;
	while (e)
	{
		if (!ft_strcmp(env, e->env))
			return (ft_strdup(e -> value));
		e = e -> next;
	}
	return (ft_strdup(" "));
}

size_t	envsize(t_env *env)
{
	size_t	len;

	len = 0;
	if (!env)
		return (0);
	while (env)
	{
		len++;
		env = env->next;
	}
	return (len);
}
