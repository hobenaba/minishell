/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:14:51 by hobenaba          #+#    #+#             */
/*   Updated: 2023/06/27 21:18:39 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	create_node(t_parser *p, t_lexer *l)
{
	if (l -> i == 0 && (l->tok2->type == word))
	{
		p -> cmd = ft_strdup(l -> tok -> value);
		p -> my_cmd = 0;
	}
	else if (l -> amg == 0 && l->tok2->type == word)
		ft_lstaddback2(&(p->args), ft_lstnew2(l -> tok -> value));
	else if (l->tok2->type == l_rdr)
		addback4(&(p->inf_her), lstnew4(l->tok->value, infile, l->amg));
	else if (l->tok2->type == r_rdr)
		addback4(&(p->outfiles), lstnew4(l->tok->value, trunc, l->amg));
	else if (l->tok2->type == dr_rdr)
		addback4(&(p->outfiles), lstnew4(l->tok->value, append, l->amg));
	else if (l->tok2->type == heredoc && l->tok ->arten == general)
	{
		p ->nu_here++;
		addback4(&(p->inf_her), lstnew4(l -> tok -> value, expand, l -> amg));
	}
	else if (l->tok2->type == heredoc && l->tok ->arten == quotes)
	{
		p ->nu_here++;
		addback4(&(p->inf_her), lstnew4(l->tok->value, not_expand, l->amg));
	}
}

t_parser	*build_list_parser(t_parser **p, t_lexer *l, t_parser *t)
{
	if (((l->tok2)->type) == the_pipe && (l->tok2)->next != NULL)
	{
		l -> index++;
		l->i = 0;
		t = ft_lstaddback3(p, ft_lstnew3(l -> index));
		l->tok2 = (l->tok2)->next;
	}
	if (((l->tok2)->type) == the_pipe && l -> tok2 -> next == NULL)
	{
		l->tok2 = l -> tok2 -> next;
		return (t);
	}
	l->tok = my_next_word(l->tok2, l);
	if (!ft_strcmp(l-> tok->value, " ") && l -> tok2 -> arten == env_general)
	{
		t -> my_cmd = 1;
		return (t);
	}
	if (l -> tok != NULL)
		create_node(t, l);
	return (t);
}

void	check_wtok(t_lexer *l, t_parser *t)
{
	if ((l->tok2)->type == l_rdr || (l->tok2)->type == r_rdr
		|| (l->tok2)->type == dr_rdr || (l->tok2)->type == heredoc)
			l->tok2 = l->tok->next;
	else if ((l->tok2)->type == word)
	{
		l->tok2 = (l->tok2)->next;
		if (t -> my_cmd == 0)
			l->i++;
	}
}

void	parse(t_token **tokens, t_parser **p, t_lexer *l)
{
	t_parser	*t;

	l->tok2 = *tokens;
	l -> index = 0;
	l->i = 0;
	if ((l->tok2) != NULL)
		t = ft_lstaddback3(p, ft_lstnew3(l -> index));
	while (l->tok2)
	{
		l -> amg = 0;
		if (!ft_strcmp(l->tok2-> value, " ") && l->tok2->arten == env_general)
		{
			l -> tok2 = l -> tok2 -> next;
			t -> my_cmd = 1;
		}
		if (l -> tok2 == NULL)
			return ;
		t = build_list_parser(p, l, t);
		if (l -> tok2 != NULL)
			check_wtok(l, t);
	}
}

t_token	*my_next_word(t_token *to, t_lexer *l)
{
	t_token	*t;
	t_token	*t2;

	t = to;
	while (to)
	{
		t2 = to -> next;
		if (t2 != NULL && to->type != the_pipe && to->type != word
			&& to->type != heredoc)
			check_amg_parse(t2, l);
		if (!ft_strcmp(to -> value, "\"\"") || !ft_strcmp(to -> value, "\'\'"))
		{
			free(to -> value);
			to -> value = ft_strdup("\0");
			return (to);
		}
		else if (to->type == word)
			return (to);
		to = to->next;
	}
	return (t);
}
