/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:11:55 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/06/27 17:35:09 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	unset_arg(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!(ft_isalpha(av[i]) || ft_isdigit(av[i]) || av[i] == '_'))
			return (0);
		i++;
	}
	return (1);
}

int	env_search(t_env *head, char *s)
{
	int		l;
	int		len;

	len = ft_strlen(s);
	while (head)
	{
		l = ft_strlen(head->env);
		if (len == l && !ft_strncmp(head->env, s, len))
			return (1);
		head = head->next;
	}
	return (0);
}

static void	unset_error(t_data *arg)
{
	g_var.exit_status = 2;
	printf("minishell: unset: %s: invalid option\n", arg->value);
	printf("unset: usage: unset [-f] [-v] [name ...]\n");
}

void	sh_unset(t_data *arg)
{
	int		i;
	t_data	*cur;

	i = 0;
	cur = arg;
	g_var.exit_status = 0;
	if (!cur)
		return ;
	if (cur->value[i] == '-' && cur->value[i + 1])
		return (unset_error(cur));
	while (cur)
	{
		if (!unset_arg(cur->value) || ft_isdigit(cur->value[0])
			|| cur->value[0] == '\0')
		{
			printf("minishell: unset: `%s': not a valid identifier\n",
				cur->value);
			g_var.exit_status = 1;
		}
		if (env_search(g_var.list, cur->value))
			ft_remove_if(&g_var.list, cur->value);
		cur = cur->next;
	}
	if (g_var.exit_status != 1)
		g_var.exit_status = 0;
}
