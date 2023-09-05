/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 18:12:42 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/06/25 20:24:14 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_fd(int *fl, t_parser *parse)
{
	if (fl[0] != -1)
		parse->fd[0] = fl[0];
	if (fl[1] != -1)
		parse->fd[1] = fl[1];
}

void	cmd_pos(t_parser *parse, t_pipe pip, char *msg, int *fl)
{
	if (!ft_strcmp(msg, "first"))
		ft_fd(fl, parse);
	if (!ft_strcmp(msg, "last"))
	{
		parse->fd[1] = 1;
		parse->fd[0] = pip.rd_end[0];
		ft_fd(fl, parse);
	}
	if (!ft_strcmp(msg, "between"))
	{
		parse->fd[0] = pip.rd_end[0];
		parse->fd[1] = pip.wr_end[1];
		ft_fd(fl, parse);
	}
}

int	*dup_fd(t_parser *parse, t_pipe pip, char *msg)
{
	int		*fl;

	fl = fd_redirection(parse);
	if (!fl)
		return (0);
	parse->fd[1] = 1;
	parse->fd[0] = 0;
	if (!ft_strcmp(msg, "one"))
		ft_fd(fl, parse);
	else
	{
		parse->fd[1] = pip.wr_end[1];
		cmd_pos(parse, pip, msg, fl);
	}
	dup2(parse->fd[1], 1);
	dup2(parse->fd[0], 0);
	if (ft_strcmp(msg, "one"))
	{
		close(pip.rd_end[0]);
		close(pip.rd_end[1]);
		close(pip.wr_end[0]);
		close(pip.wr_end[1]);
	}
	return (fl);
}
