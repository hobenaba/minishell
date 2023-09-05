/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:53:39 by hobenaba          #+#    #+#             */
/*   Updated: 2023/06/27 15:23:31 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

typedef struct s_pipe
{
	int	*rd_end;
	int	*wr_end;
}	t_pipe;

void	her(t_data2 *my_heredoc, t_data2 *heredoc_next, int index, int *pipefd);
void	run_builtin(t_parser *parser);
void	exec_heredoc(t_parser *parser);
void	execution(t_parser *parser);
int		multiple_pipes(t_parser *node);
int		exec_cmd(t_parser *parser, t_pipe pip, char *msg);
int		isbuiltin(t_parser *parser);
void	builtin_executor(t_parser *node, t_pipe pip, char *msg);
void	run_builtin(t_parser *parser);
int		*dup_fd(t_parser *parse, t_pipe pip, char *msg);
int		*fd_redirection(t_parser *node);
char	*get_path(char *cmd);
void	check_dir_notexec(char *path, t_parser *node);
char	**create_env_arr(int size);
char	**table_cmd(t_parser *node);
void	ft_free(char **str);
void	ft_err(char *s, char *cmd, char *s2);
void	update_fd(int *my_fd);
int		ft_check_fork(int p);
int		cmd_slash(char *cmd);;
void	write_her(t_data2 *my_heredoc, t_data2 *heredoc_next, t_parser *p);
int		ft_ambi(t_data2 *list);
void	check_my_heredoc(t_data2 *inf_her, t_data2 **my_heredoc);

#endif