/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_saver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:45:04 by hobenaba          #+#    #+#             */
/*   Updated: 2023/06/27 14:26:47 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	check_this_out(int i, int *a, char **env, t_env **my_env)
{
	int	len;
	int	start;

	len = 0;
	start = 0;
	while (env[i][++len])
	{
		if (env[i][len] == '=')
		{
			start = len + 1;
			break ;
		}
	}
	if (!ft_strcmp2(ft_substr(env[i], 0, len), "OLDPWD"))
	{
		ft_lstaddback_env(my_env, ft_lstnew_env(ft_substr(env[i], 0,
					len), NULL));
		*a = 1;
	}
	else
		ft_lstaddback_env(my_env, ft_lstnew_env(ft_substr(env[i], 0, len),
				ft_substr(env[i], start, ft_strlen(env[i]) - 1)));
}

t_env	*save_my_env(char **env)
{
	t_env	*my_env;
	int		i;
	int		a;

	i = 0;
	a = 0;
	my_env = NULL;
	if (ft_dostrlen (env) == 0)
		ft_lstaddback_env(&my_env, ft_lstnew_env(ft_strdup("SHLVL"),
				ft_strdup("1")));
	while (env[i])
	{
		check_this_out(i, &a, env, &my_env);
		i++;
	}
	if (a == 0)
		ft_lstaddback_env(&my_env, ft_lstnew_env(ft_strdup("OLDPWD"), NULL));
	return (my_env);
}
