/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 01:33:01 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/06/16 18:08:22 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	check_egal(t_data *tmp)
{
	if (tmp->value[0] == '=' || !ft_strcmp(tmp->value, "=")
		|| !tmp->value[0] || tmp->value[0] == '+')
	{
		printf("minishell: export: `%s': not a valid identifier\n", tmp->value);
		g_var.exit_status = 1;
		return (1);
	}
	return (0);
}

int	plus_sign(char *env, char *value)
{
	int	i;
	int	count_plus;

	i = 0;
	count_plus = 0;
	while (env[i])
	{
		if (env[i] == '+')
			count_plus++;
		i++;
	}
	if ((!value && env[i - 1] == '+')
		|| (env[i - 1] == '+' && count_plus > 1))
		return (1);
	return (0);
}

int	check_ident(char *env, char *value, int len)
{
	int	i;

	i = 0;
	if (ft_isdigit(env[0]))
		return (printf("minishell: export: `%s': not a valid identifier\n",
				env));
	if (plus_sign(env, value))
		return (printf("minishell: export: `%s': not a valid identifier\n",
				env));
	while (env[i])
	{
		if (!(ft_isalpha(env[i]) || ft_isdigit(env[i])
				|| env[i] == '_') && env[len - 1] != '+')
		{
			printf("minishell: export: `%s': not a valid identifier\n", env);
			return (1);
		}
		i++;
	}
	return (0);
}
