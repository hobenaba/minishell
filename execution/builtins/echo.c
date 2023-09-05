/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hindbenabad <hindbenabad@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 11:18:14 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/09/05 17:15:25 by hindbenabad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_av(t_data *av, int newline)
{
	t_data	*tmp;

	tmp = av;
	while (tmp)
	{
		printf("%s", tmp->value);
		if (tmp->next)
			printf(" ");
		tmp = tmp->next;
	}
	if (newline)
		printf("\n");
}

int	non_n_carcacters(char *ntr)
{
	if (!(*ntr))
		return (1);
	while (*ntr)
	{
		if (*ntr != 'n')
			return (1);
		ntr++;
	}
	return (0);
}

void	check_n(t_data *arg)
{
	int		i;
	t_data	*tmp;

	i = 0;
	tmp = arg;
	if (non_n_carcacters(tmp->value + 1))
	{
		print_av(tmp, 1);
		return ;
	}
	while (tmp && tmp->value[i] == '-' && !non_n_carcacters(tmp->value + 1))
		tmp = tmp->next;
	if (!tmp)
		return ;
	print_av(tmp, 0);
}

void	sh_echo(t_parser **echo)
{
	t_parser	*tmp;

	tmp = *echo;
	if (!tmp->args)
		printf("\n");
	else if (tmp->args->value[0] == '-')
		check_n(tmp->args);
	else
		print_av(tmp->args, 1);
	g_var.exit_status = 0;
}
