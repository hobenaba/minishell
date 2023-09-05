/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 06:15:22 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/06/26 19:13:13 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	sh_pwd(void)
{
	char	buf[4096];
	t_env	*s;

	if (!getcwd(buf, 4096))
	{
		if (env_search(g_var.list, "PWD"))
		{
			s = ft_getenv(g_var.list, "PWD");
			printf("%s\n", s->value);
		}
		else
			perror("minishell");
	}
	else
		printf("%s\n", buf);
}
