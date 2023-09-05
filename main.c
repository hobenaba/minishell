/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hindbenabad <hindbenabad@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:52:25 by hobenaba          #+#    #+#             */
/*   Updated: 2023/09/05 18:17:39 by hindbenabad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	syntax_error(int base, t_token **tokens)
{
	t_token	*t;
	t_token	*p;

	p = NULL;
	if (*tokens == NULL)
		t = NULL;
	else
		t = *tokens;
	if (base != 0)
		return (printf("minishell: syntax error near unexpected token\n"), 1);
	while (t)
	{
		if ((t -> type == the_pipe && (p == NULL || t->next == NULL))
			|| (t->type == the_pipe && (t->next)->type == the_pipe))
			return (printf("minishell: syntax error near unexpected token `|'\n")
				, 1);
		if ((t -> type != the_pipe && t -> type != word)
			&& (t -> next == NULL || (t -> next)-> type != word))
			return (printf("minishell: syntax error near unexpected token\n"),
				1);
		p = t;
		t = t -> next;
	}
	return (0);
}

void	pa_ex(t_token *tok, t_lexer *lex, t_parser *par, int base)
{
	t_parser	*p;

	if (tok != NULL)
		parse(&tok, &par, lex);
	p = par;
	while (p)
	{
		if (p -> nu_here >= 17)
		{
			printf("minishell: maximum here-document count exceeded\n");
			exit (2);
		}
		p = p -> next;
	}
	exec_heredoc(par);
	if (syntax_error(base, &tok))
		g_var.exit_status = 258;
	else
	{
		execution(par);
		add_to_under_score(par);
		update_fd(g_var.fd_prog);
	}
	free_mylist(par, 1);
}

void	starting(char *input, t_token *tok, t_lexer *le, t_parser *par)
{
	int	base;

	add_history(input);
	g_var.fd_prog = my_fd();
	base = lex(input, &tok, le);
	pa_ex(tok, le, par, base);
	close_myfd_prog(g_var.fd_prog);
	free_mylist(tok, 0);
}

int	_session(t_token *tok, t_parser *par, t_lexer *le)
{
	char	*input;

	while (1)
	{	
		tok = NULL;
		par = NULL;
		g_var.signal_heredoc = 0;
		signal_check();
		input = readline("minishell-3.2$ ");
		signal(SIGINT, SIG_IGN);
		if (input == NULL)
			break ;
		if (ft_check_space(input))
			starting(input, tok, le, par);
		free(input);
	}
	return (g_var.exit_status);
}

int	main(int ac, char **av, char **env)
{
	t_lexer		*lexer;
	t_token		*tokens;
	t_parser	*parser;
	int			out;

	(void)ac;
	(void)av;
	lexer = malloc (sizeof(t_lexer));
	tokens = NULL;
	parser = NULL;
	g_var.list = save_my_env(env);
	if (!env_search(g_var.list, "PWD"))
		ft_lstaddback_env(&g_var.list,
			ft_lstnew_env(ft_strdup("PWD"), getcwd(NULL, 0)));
	out = _session(tokens, parser, lexer);
	return (out);
}
