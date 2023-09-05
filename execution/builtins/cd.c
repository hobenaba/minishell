/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:16:58 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/06/27 17:10:24 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env	*ft_getenv(t_env *head, char *s)
{
	t_env	*node;
	int		l;
	int		len;

	len = ft_strlen(s);
	while (head)
	{
		l = ft_strlen(head->env);
		if (len == l && !ft_strncmp(head->env, s, len))
		{
			node = head;
			return (node);
		}
		head = head->next;
	}
	return (NULL);
}

void	sh_cd(t_parser *env_cmd)
{
	t_env	*env_oldpwd;
	t_env	*pwd_home;
	t_env	*env_pwd;
	char	**oldpwd;
	char	**pwd;

	oldpwd = NULL;
	pwd = NULL;
	pwd_home = ft_getenv(g_var.list, "HOME");
	env_oldpwd = ft_getenv(g_var.list, "OLDPWD");
	if (env_oldpwd)
		oldpwd = &(env_oldpwd->value);
	env_pwd = ft_getenv(g_var.list, "PWD");
	if (env_pwd)
		pwd = &(env_pwd->value);
	if (!env_cmd->args || !ft_strcmp(env_cmd->args->value, "--")
		|| !ft_strcmp(env_cmd->args->value, "~"))
		cd_home(pwd_home, pwd, getcwd(NULL, 0), env_oldpwd);
	else if (env_cmd->args)
	{
		if (ft_strcmp(env_cmd->args->value, "-") == 0)
			cd_oldpwd(oldpwd, pwd);
		else
			cd_newpwd(env_cmd->args, pwd, env_oldpwd);
	}
}
