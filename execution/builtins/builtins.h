/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 00:48:37 by nerrakeb          #+#    #+#             */
/*   Updated: 2023/06/27 17:36:15 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

void	sh_echo(t_parser **echo);
void	sh_pwd(void);
void	sh_env(t_data *args);
void	sh_exit(t_parser *ex);
void	sh_unset(t_data *arg);
void	ft_remove_if(t_env **head, void *data);
int		env_search(t_env *head, char *s);
void	sh_cd(t_parser *env_cmd);
t_env	*ft_getenv(t_env *head, char *s);
void	cd_home(t_env *pwd_home, char **pwd, char *cwd, t_env *env_old);
void	cd_oldpwd(char **oldpwd, char **pwd);
void	cd_newpwd(t_data *name, char **pwd, t_env *env_old);
void	sh_export(t_parser *parser);
void	sorted_env(t_env *head);
int		check_egal(t_data *tmp);
int		check_export_args(t_env *new_node);
int		check_ident(char *env, char *value, int len);
void	modifie_and_add(t_env *new_env_node);
void	modifie_env_node(char *env, char *new_value);

#endif
