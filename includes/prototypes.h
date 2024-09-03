/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 10:21:00 by gwagner           #+#    #+#             */
/*   Updated: 2024/09/03 12:28:03 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "structs.h"

void	free_list(t_args **list);
t_args	*ft_lstnew(char *data, t_token token);
void	ft_lstadd_front(t_args **list, t_args *new);
void	ft_lstadd_back(t_args **list, t_args *new);
int		ft_lstsize(t_args *head);
t_args	*ft_lstlast(t_args *head);
void	ft_printlst(t_args *head);
t_args	*split_args(char *line);
int		is_space(char c);
int		wordlen(char *line);
t_token	check_quote(char c);
int		eat_space(char *line, int i);
int		check_redir(char *line, int i);
int		putquote(t_args **list, char *line, int i, char quote);
int		quotecheck(char *line, int i, char quote);
int		putcmd(t_args **list, char *line, int *i);
int		quotelen(char *line, char quote);
int		syntax_error(t_args *list);
t_env	*env_lstnew(char *data);
t_env	*env_lstlast(t_env *head);
void	env_lstadd_back(t_env **list, t_env *new);
int		env_lstsize(t_env *head);
void	free_env(t_env **list);
t_env	*init_env(char **envp);
void	put_vars(t_args **list, t_env *env);
int 	ft_pwd(t_data *data);
int		ft_cd(t_data *data);
int 	ft_env(t_data *data);
int 	exec_built(char *cmd, t_data *data);
void	ft_printenv(t_env *head);
t_env	*find_node(const char *to_find, t_env *env);
int		ft_export(t_data *data);
void	free_matrix(char **str);
int		export_exist(char *data, t_env *env);
int		ft_unset(t_data *data);
int 	quotewordlen(char *line);
void 	trim_quotes(t_args **list);
size_t	varlen(char *data);
int		check_env(char *data, t_env *env);
int		matrix_size(char **matrix);
int		ft_echo(t_cmd *cmd);

#endif