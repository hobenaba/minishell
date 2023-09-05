/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:50:10 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/06/27 21:45:01 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_open(char *name, char *msg)
{
	int	fd;

	if (!ft_strcmp(msg, "saved_file"))
		fd = open(name, O_CREAT | O_WRONLY | O_APPEND, 0644);
	else if (!ft_strcmp(msg, "outfile"))
		fd = open(name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else
		fd = open(name, O_RDONLY, 0644);
	if (fd == -1)
	{
		perror(name);
		if (g_var.parent_process == 0)
			exit(1);
		else
			fd = -3;
	}
	return (fd);
}

int	*init_fd(void)
{
	int	*fd;

	fd = malloc(sizeof(int) * 2);
	fd[0] = -1;
	fd[1] = -1;
	return (fd);
}

int	ft_infiles(t_parser *node, t_data2 *tmp2, int *fd)
{
	while (tmp2)
	{
		g_var.redir = 1;
		if (ft_ambi(tmp2))
			return (0);
		if (tmp2->type == infile && !ft_ambi(tmp2))
		{
			close(fd[0]);
			fd[0] = ft_open(tmp2->value, "infile");
		}
		else
			fd[0] = node->fd[0];
		if (fd[0] == -3)
			return (0);
		tmp2 = tmp2->next;
	}
	return (fd[0]);
}

int	*fd_redirection(t_parser *node)
{
	int			*fd;
	t_data2		*tmp1;
	t_data2		*tmp2;

	fd = init_fd();
	tmp1 = node->outfiles;
	tmp2 = node->inf_her;
	fd[0] = ft_infiles(node, tmp2, fd);
	if (!fd[0])
		return (free(fd), NULL);
	while (tmp1)
	{
		g_var.redir = 1;
		close(fd[1]);
		if (ft_ambi(tmp1))
			return (free(fd), NULL);
		if (tmp1->type == append && !ft_ambi(tmp1))
			fd[1] = ft_open(tmp1->value, "saved_file");
		else if (tmp1->type == trunc && !ft_ambi(tmp1))
			fd[1] = ft_open(tmp1->value, "outfile");
		if (fd[1] == -3)
			return (free(fd), NULL);
		tmp1 = tmp1->next;
	}
	return (fd);
}
