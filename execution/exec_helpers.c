/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 00:25:27 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/06/27 17:14:24 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_err(char *s, char *cmd, char *s2)
{
	ft_putstr_fd(s, STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putendl_fd(s2, STDERR_FILENO);
	exit(g_var.exit_status);
}

int	ft_check_fork(int p)
{
	if (p == -1)
	{
		perror("minishell");
		return (1);
	}
	return (0);
}

int	cmd_slash(char *cmd)
{
	int	i;

	i = 0;
	if (!cmd)
		return (0);
	while (cmd[i])
	{
		if (cmd[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

void	ft_free(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

int	ft_ambi(t_data2 *list)
{
	if (list -> amg == 1)
	{
		g_var.exit_status = 1;
		printf ("minishell: %s: ambiguous redirect\n", list->value);
		return (1);
	}
	return (0);
}
