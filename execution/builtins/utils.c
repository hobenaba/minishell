/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:18:08 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/06/27 18:12:00 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	set_pwd(char **pwd)
{
	if (pwd)
	{
		free(*pwd);
		*pwd = getcwd(NULL, 0);
	}
}

void	set_oldpwd(char **oldpwd, char *cwd)
{
	free(*oldpwd);
	*oldpwd = cwd;
}

void	cd_home(t_env *pwd_home, char **pwd, char *cwd, t_env *env_old)
{
	char	*path;

	path = NULL;
	if (pwd_home)
		path = pwd_home->value;
	if (path)
	{
		if (chdir(path) == -1)
		{
			return (g_var.exit_status = 1, printf("minishell: cd: %s: %s\n",
					path, strerror(errno)), free(cwd));
		}
		else if (env_old)
			set_oldpwd(&(env_old->value), cwd);
		set_pwd(pwd);
		g_var.exit_status = 0;
		if (chdir(path) != -1 && !env_old)
			free(cwd);
	}
	else
	{
		return (g_var.exit_status = 1,
			printf("minishell: cd: HOME not set\n"), free(cwd));
	}
}

void	cd_oldpwd(char **oldpwd, char **pwd)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (!oldpwd || !(*oldpwd))
	{
		g_var.exit_status = 1;
		printf("minishell: cd: OLDPWD not set\n");
		return (free(cwd));
	}
	else
	{
		if (chdir(*oldpwd) == -1)
		{
			g_var.exit_status = 1;
			printf("minishell: cd: %s: %s\n", cwd, strerror(errno));
			return (free(cwd));
		}
		else
		{
			printf("%s\n", *oldpwd);
			set_oldpwd(oldpwd, cwd);
		}
		set_pwd(pwd);
		g_var.exit_status = 0;
	}
}

void	cd_newpwd(t_data *name, char **pwd, t_env *env_old)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (chdir(name->value) == -1)
	{
		g_var.exit_status = 1;
		if (name->value[0] == '-' && name->value)
		{
			printf("minishell: cd: %s: invalid option\n", name->value);
			printf("cd: usage: cd [-L|-P] [dir]\n");
		}
		else
			printf("minishell: cd: %s: %s\n", name->value, strerror(errno));
		return (free(cwd));
	}
	else if (env_old)
		set_oldpwd(&(env_old->value), cwd);
	set_pwd(pwd);
	if (!env_old)
		free (cwd);
	g_var.exit_status = 0;
}
