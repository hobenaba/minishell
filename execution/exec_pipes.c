/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:19:54 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/06/27 21:16:29 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	switch_pipe(t_pipe *pip, int i, int fd_pip[2][2])
{
	if (i % 2 == 0)
	{
		pip->rd_end = fd_pip[0];
		pip->wr_end = fd_pip[1];
	}
	else
	{
		pip->rd_end = fd_pip[1];
		pip->wr_end = fd_pip[0];
	}
}

void	open_pipes(t_pipe pip, int index)
{
	if (index == 0)
	{
		pipe(pip.rd_end);
		pipe(pip.wr_end);
	}
	else
		pipe(pip.wr_end);
}

int	multiple_pipes(t_parser *node)
{
	t_pipe		pip;
	t_parser	*cur;
	pid_t		pid;
	int			fd_pip[2][2];

	cur = node;
	while (cur)
	{
		if (pid == -1)
			return (pid);
		switch_pipe(&pip, cur->index, fd_pip);
		open_pipes(pip, cur->index);
		if (cur == node)
			pid = exec_cmd(cur, pip, "first");
		else if (cur->next == NULL)
			pid = exec_cmd(cur, pip, "last");
		else
			pid = exec_cmd(cur, pip, "between");
		close(pip.rd_end[0]);
		close(pip.rd_end[1]);
		cur = cur->next;
	}
	close(pip.wr_end[0]);
	close(pip.wr_end[1]);
	return (pid);
}
