/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:54:28 by hobenaba          #+#    #+#             */
/*   Updated: 2023/06/26 21:41:30 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "../includes/env.h"

enum
{
	word,
	the_pipe,
	r_rdr,
	dr_rdr,
	l_rdr,
	heredoc,
};

enum
{
	env_general,
	env_quotes,
	general,
	quotes,
};

typedef struct t_token
{
	char			*value;
	int				type;
	int				arten;
	struct t_token	*next;
}	t_token;

typedef struct t_lexer
{
	int		base;
	int		base2;
	int		her;
	int		her2;
	char	*str;
	char	c;
	int		a;
	int		i;
	int		len;
	int		i2;
	int		index;
	int		amg;
	int		arten;
	char	*str_env;
	char	**s2;
	char	*env;
	int		e;
	t_token	*tok2;
	t_token	*tok;
}	t_lexer;

// utils i would be in need for my linked list.

t_token	*ft_lstnew(char *value, int type, int arten);
void	ft_lstaddback(t_token **lst, t_token *new);

// funstions related to tokens
int		lex(char *input, t_token **tokens, t_lexer *lexer);
int		check_which_special_char(char c, char next_c, t_token **t, t_lexer *l);
int		ft_ignore_spaces(char *input, int i);
int		other_tokens(t_lexer *lexer, int i, char *input);
int		partition_tokens(t_lexer *lexer, char *input, int i);
int		token_word(char *input, int start, int base);
int		token_env(char *input, int i, t_lexer *lexer, t_token **tokens);
int		normal_word(char *input, int start);
int		quotes_word(char *input, int start, int base);
int		env_word(char *input, int start);
void	build_list(t_lexer *lexer, t_token **tokens);
int		ft_check_space(char *value);

// to initiaize 
void	lexer_init(t_lexer *lexer);
#endif