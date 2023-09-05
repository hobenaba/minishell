/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_exp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:19:26 by hobenaba          #+#    #+#             */
/*   Updated: 2023/06/26 17:54:08 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	loop_on_myenv(t_token **t, t_lexer *l)
{
	l -> s2 = ft_split(l -> str_env, ' ');
	free(l -> str_env);
	while (l -> s2[l -> i2 + 1])
	{
		if (l -> base == 0)
			ft_lstaddback(t, ft_lstnew(l->s2[l -> i2], word, env_general));
		else
			ft_lstaddback(t, ft_lstnew(l->s2[l -> i2], word, env_quotes));
		l -> i2++;
	}
	l -> str_env = l -> s2[l -> i2];
}

void	token_env3(t_token **t, t_lexer *l, char *input, int i)
{
	l -> i2 = 0;
	l -> e = 1;
	l -> env = ft_substr(input, i + 1, l -> len);
	l -> str_env = check_env(l -> env, g_var.list);
	if (ft_strcmp(l -> str_env, " ") != 0 && ft_check_space(l -> str_env) > 0)
	{
		if (l -> str != NULL && l -> e == 0)
			build_list(l, t);
		loop_on_myenv(t, l);
		free(l -> s2);
	}
	if (l -> str != NULL && !ft_strcmp(" ", l -> str_env))
	{
		free (l -> str_env);
		l -> str_env = NULL;
	}
	l->str = ft_strjoin(l->str, l -> str_env);
	free(l -> env);
}

int	token_env2(char *input, int i, t_lexer *l, t_token **tokens)
{
	l -> len = token_word(input, i + 1, -1);
	l -> str_env = NULL;
	if (l->her == 0 && (l->base == 2 || l->base == 0))
	{
		if (l -> len != 0)
			token_env3(tokens, l, input, i);
		else if (l->len == 0 && ((input[i + 1] != '\0' && l->base == 2)
				|| ((input[i + 1] == '\0' || input[i + 1] == ' ')
					&& l->base == 0)))
		{
			l -> str_env = ft_strdup("$");
			l->str = ft_strjoin(l->str, l -> str_env);
		}
	}
	else
	{
		l -> str_env = ft_substr(input, i, l -> len + 1);
		l->str = ft_strjoin(l->str, l->str_env);
		l->her = 0;
	}
	i += l -> len + 1;
	return (i);
}

int	token_env(char *input, int i, t_lexer *lexer, t_token **tokens)
{
	char	*itoa;

	if (input[i + 1] == '?')
	{
		if (lexer -> index == 0)
			itoa = ft_itoa(g_var.exit_status);
		else
			itoa = ft_strdup("0");
		lexer -> str_env = ft_strdup(itoa);
		lexer->str = ft_strjoin(lexer->str, lexer -> str_env);
		free(itoa);
		i += 2;
	}
	else if (ft_isdigit(input[i + 1]))
		i += 2;
	else if (input[i + 1] == '$')
	{
		lexer -> str_env = ft_strdup("$$");
		lexer->str = ft_strjoin(lexer->str, lexer -> str_env);
		i += 2;
	}
	else
		i = token_env2(input, i, lexer, tokens);
	return (i);
}
