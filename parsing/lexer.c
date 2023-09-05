/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:53:34 by hobenaba          #+#    #+#             */
/*   Updated: 2023/06/27 14:11:40 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_wsc(char c, char n_c, t_token **tokens, t_lexer *lex)
{
	if (c == '|')
		return (lex -> index++, ft_lstaddback(tokens,
				ft_lstnew(ft_strdup("|"), the_pipe, general)), 1);
	else if (c == '>')
	{
		if (n_c == '>')
			return (ft_lstaddback(tokens,
					ft_lstnew(ft_strdup(">>"), dr_rdr, general)), 2);
		return (ft_lstaddback(tokens,
				ft_lstnew(ft_strdup(">"), r_rdr, general)), 1);
	}
	else if (c == '<')
	{
		if (n_c == '<')
			return (ft_lstaddback(tokens,
					ft_lstnew(ft_strdup("<<"), heredoc, general)), 2);
		return (ft_lstaddback(tokens,
				ft_lstnew(ft_strdup("<"), l_rdr, general)), 1);
	}	
	return (0);
}

int	ft_check_space(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i + 1] == ' ')
			j++;
		else if (s[i] != ' ' && s[i + 1] == '\0')
			j++;
		i++;
	}
	return (j);
}

void	build_list(t_lexer *lex, t_token **tokens)
{
	int		arten;

	if (lex -> base2 != 0)
		arten = quotes;
	else
		arten = general;
	if (lex -> str != NULL && (lex -> e == 1))
		ft_lstaddback(tokens, ft_lstnew(lex -> str, word, env_general));
	else
		ft_lstaddback(tokens, ft_lstnew(lex -> str, word, arten));
	lex -> str = NULL;
	lex -> base2 = 0;
	lex -> e = 0;
}

int	lex(char *s, t_token **tokens, t_lexer *lex)
{
	int	i;

	i = 0;
	lexer_init(lex);
	while (s[i])
	{
		if (s[i] == ' ' && lex -> base == 0)
			i = ft_ignore_spaces(s, i);
		if (s[i] != '\0' && ft_strchr("$|><", s[i]) != NULL && lex -> base == 0)
			check_condition2(lex, tokens, s, &i);
		else if (s[i] != '\0')
			i = partition_tokens(lex, s, i);
		if (s[i] != '\0' && check_condition(lex, s, i) == 1)
			lex -> str = ft_strjoin(lex -> str, ft_substr(s, i - 1, 2));
		if (s[i] == '$')
			i = token_env(s, i, lex, tokens);
		if (lex -> base == 0 && lex -> str != NULL && (s[i] == '\0'
				|| ft_strchr(" |><", s[i]) != NULL))
			build_list(lex, tokens);
	}
	return (free(lex -> str), lex -> base);
}
