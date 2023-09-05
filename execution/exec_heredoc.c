/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:39:01 by hobenaba          #+#    #+#             */
/*   Updated: 2023/06/26 21:22:15 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	check_my_heredoc(t_data2 *inf_her, t_data2 **my_heredoc)
{
	while (inf_her)
	{
		if (inf_her -> type != infile)
		{
			*my_heredoc = inf_her;
			break ;
		}
		inf_her = inf_her -> next;
	}
}

void	check_her(t_data2 *inf_her, t_parser *p)
{
	t_data2		*my_heredoc;
	t_data2		*heredoc_next;
	t_data2		*v;

	while (inf_her)
	{
		my_heredoc = NULL;
		heredoc_next = NULL;
		check_my_heredoc(inf_her, &my_heredoc);
		v = my_heredoc;
		if (my_heredoc != NULL)
			check_my_heredoc(v -> next, &heredoc_next);
		if (heredoc_next != NULL)
			v = heredoc_next;
		if (my_heredoc != NULL)
			write_her(my_heredoc, heredoc_next, p);
		if (my_heredoc != NULL)
			inf_her = heredoc_next;
		else
			inf_her = my_heredoc;
	}
}

void	exec_heredoc(t_parser *parser)
{
	t_data2		*inf_her;
	t_parser	*p;

	p = parser;
	while (p)
	{
		inf_her = p -> inf_her;
		check_her(inf_her, p);
		p = p->next;
	}
}

void	signal_heredoc(int signal)
{
	(void)signal;
	exit(1);
}

void	write_her(t_data2 *my_heredoc, t_data2 *heredoc_next, t_parser *p)
{
	int	pipefd[2];
	int	pid;
	int	status;

	if (heredoc_next == NULL)
		pipe(pipefd);
	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, signal_heredoc);
		her(my_heredoc, heredoc_next, p -> index, pipefd);
		exit (0);
	}
	waitpid(pid, &status, 0);
	g_var.exit_status = WEXITSTATUS(status);
	if (g_var.exit_status == 1)
		p -> signal = 1;
	if (heredoc_next == NULL)
	{
		close(pipefd[1]);
		p->fd[0] = pipefd[0];
	}
}
