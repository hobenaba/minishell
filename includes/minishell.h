/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:53:18 by hobenaba          #+#    #+#             */
/*   Updated: 2023/06/27 18:00:34 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include "../includes/lexer.h"
# include "../includes/parser.h"
# include "../includes/execution.h"
# include "../includes/env.h"
# include "../execution/builtins/builtins.h"
# include <stdio.h>
# include <stdbool.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/errno.h>
# include "../includes/execution.h"
# include <signal.h>
# include <termios.h>

typedef struct s_glb
{
	t_env	*list;
	int		exit_status;
	int		signal_heredoc;
	bool	parent_process;
	int		*fd_prog;
	bool	redir;
}	t_glb;

t_glb	g_var;

typedef struct t_helper
{
	char	**arr;
	char	*add;
	t_env	*en;
	int		en_lenght;
	int		val_lenght;
	int		i;
}	t_helper;

// thsi one must stau hier since they dont know the prototype of this function
//gotta add this cause in the library i downloaded they didnt have the prototype
void	rl_replace_line(const char *text, int clear_undo);
size_t	envsize(t_env *env);
void	signal_check(void);
void	check_signal_heredoc(void);
int		*my_fd(void);
void	update_fd(int *my_fd);
void	close_myfd_prog(int *my_fd);
t_env	*find_env(t_env *head, char *s);
char	*ft_add_arr(t_env *en, int en_len, int val_len);
void	add_to_under_score(t_parser *parser);

#endif