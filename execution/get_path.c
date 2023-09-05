/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hindbenabad <hindbenabad@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 05:37:14 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/09/05 17:14:53 by hindbenabad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**table_cmd(t_parser *node)
{
	char			**s1;
	unsigned long	i;
	int				j;
	t_data			*args;

	j = 1;
	s1 = NULL;
	args = node -> args;
	while (args)
	{
		args = args -> next;
		j++;
	}
	s1 = malloc (sizeof(char *) * (j + 1));
	i = 1;
	args = node -> args;
	s1[0] = ft_strdup(node -> cmd);
	while (args)
	{
		s1[i] = ft_strdup(args -> value);
		i++;
		args = args -> next;
	}
	s1[i] = NULL;
	return (s1);
}

void	check_dir_notexec(char *path, t_parser *node)
{
	int		dir;

	(void)node;
	dir = open(path, O_DIRECTORY);
	if (dir != -1)
	{
		close(dir);
		g_var.exit_status = 126;
		ft_err("minishell: ", path, ": is a directory");
	}
	if (access(path, X_OK))
	{
		g_var.exit_status = 127;
		if (!access(path, F_OK))
			g_var.exit_status = 126;
		perror("minishell");
		exit(g_var.exit_status);
	}
}

char	**real_path(void)
{
	char	**p;
	t_env	*cur;

	cur = g_var.list;
	while (cur)
	{
		if (!ft_strncmp(cur->env, "PATH", 4))
		{
			if (cur->value[0] == ':')
				cur->value = ft_strjoin2(".", cur->value);
			p = ft_split(cur->value, ':');
			return (p);
		}
		cur = cur->next;
	}
	return (NULL);
}

char	*get_path(char *cmd)
{
	char	*path;
	char	*cmd_file;
	char	**full_path;
	int		i;

	full_path = real_path();
	if (!full_path)
	{
		g_var.exit_status = 127;
		ft_err("minishell: ", cmd, ": command not found");
	}
	cmd_file = ft_strjoin2("/", cmd);
	i = -1;
	while (full_path[++i])
	{
		path = ft_strjoin2(full_path[i], cmd_file);
		if (!access(path, F_OK | X_OK))
			return (ft_free(full_path), free(cmd_file), path);
		free(path);
	}
	ft_free(full_path);
	return (NULL);
}
