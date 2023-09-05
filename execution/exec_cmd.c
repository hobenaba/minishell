/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 19:43:02 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/06/27 21:27:01 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_execve(char *path, t_parser *node, char **env, int slash)
{
	char	**arr;

	g_var.exit_status = 0;
	if (slash)
		check_dir_notexec(path, node);
	arr = table_cmd(node);
	if (execve(path, arr, env) < 0)
	{
		free(env);
		perror("minishell");
		exit(1);
	}
}

void	dp_built(t_parser *parse, t_pipe pip, char *msg)
{
	if (!dup_fd(parse, pip, msg))
		exit(1);
	if (isbuiltin(parse))
	{
		run_builtin(parse);
		update_fd(g_var.fd_prog);
		exit(g_var.exit_status);
	}
	if (!parse->cmd && g_var.redir == 1)
		exit(0);
}

void	signal_child(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

void	path_null(char *path)
{
	if (!path)
		exit(g_var.exit_status);
}

int	exec_cmd(t_parser *parse, t_pipe pip, char *msg)
{
	pid_t	pid;
	char	*path;
	int		slash;

	pid = fork();
	if (ft_check_fork(pid))
		return (pid);
	if (pid == 0)
	{
		signal_child();
		dp_built(parse, pip, msg);
		path = parse->cmd;
		path_null(path);
		slash = cmd_slash(parse->cmd);
		if (!slash)
			path = get_path(parse->cmd);
		if ((!path && parse->my_cmd == 0) || !ft_strcmp(parse->cmd, "\0"))
		{
			g_var.exit_status = 127;
			ft_err("minishell: ", parse->cmd, ": command not found");
		}
		if (parse -> my_cmd == 0)
			ft_execve(path, parse, create_env_arr(envsize(g_var.list)), slash);
	}
	return (pid);
}
