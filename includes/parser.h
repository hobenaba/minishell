/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:54:36 by hobenaba          #+#    #+#             */
/*   Updated: 2023/06/27 14:13:49 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

enum
{
	expand,
	not_expand,
	trunc,
	append,
	infile,
};
enum
{
	env,
	not_env
};

typedef struct t_data
{
	char			*value;
	struct t_data	*next;
}	t_data;

typedef struct t_data2
{
	char			*value;
	int				type;
	int				amg;
	struct t_data2	*next;
}	t_data2;

// this represent the main struct that i will send to my teammate
typedef struct t_parser
{
	char			*cmd;
	t_data			*args;
	t_data2			*outfiles;
	int				index;
	int				nu_here;
	int				fd[2];
	t_data2			*inf_her;
	int				my_cmd;
	int				signal;
	struct t_parser	*next;
}	t_parser;

// functions im gonna work with in the parsing part
void		parse(t_token **tokens, t_parser **parser, t_lexer *lexer);
void		create_node(t_parser *parser, t_lexer *lexer);
t_token		*my_next_word(t_token *tokens, t_lexer *lexer);
int			ft_lstsize_parse(t_parser *parse);
void		check_struct(t_parser *parser);
void		check_amg_parse(t_token *t2, t_lexer *l);
int			check_wsc(char c, char n_c, t_token **tokens, t_lexer *lex);

// those are relate to then creation of my lists that im gonna work with.

t_data		*ft_lstnew2(char *value);
void		ft_lstaddback2(t_data **lst, t_data *new);
t_parser	*ft_lstnew3(int index);
t_parser	*ft_lstaddback3(t_parser **lst, t_parser *new);
t_data2		*lstnew4(char *value, int type, int amg);
void		addback4(t_data2 **lst, t_data2 *new);
int			check_condition(t_lexer *lex, char *s, int i);
void		check_condition2(t_lexer *lex, t_token **tokens, char *s, int *i);

// functions that are responsible for freeing my list

void		free_mylist(void *list, int type);

#endif