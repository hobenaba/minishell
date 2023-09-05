/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:18:35 by hobenaba          #+#    #+#             */
/*   Updated: 2023/06/27 21:18:33 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_ignore_spaces(char *input, int i)
{
	while (input[i] && input[i] == ' ')
		i++;
	return (i);
}

void	check_amg_parse(t_token *t2, t_lexer *l)
{
	if (t2 != NULL && t2->arten == env_general
		&& (t2->next != NULL && t2->next->arten == env_general))
			l -> amg = 1;
	if (!ft_strcmp(t2 -> value, " "))
		l -> amg = 1;
}

int	ft_lstsize_parse(t_parser *parse)
{
	int	i;

	i = 0;
	if (!parse)
		return (0);
	while (parse)
	{
		i++;
		parse = parse->next;
	}
	return (i);
}

int	check_condition(t_lexer *lex, char *s, int i)
{
	if (s[i] == lex -> c && s[i - 1] == lex -> c && (lex -> str == NULL
			&& (s[i + 1] == ' ' || s[i + 1] == '\0' )))
		return (1);
	return (0);
}

void	check_condition2(t_lexer *lex, t_token **tokens, char *s, int *i)
{
	if (s[*i] == '<' && s[*i + 1] == '<')
	{
		lex -> her = 1;
		lex -> her2 += 1;
	}
	*i += check_wsc(s[*i], s[*i + 1], tokens, lex);
}
