/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 10:21:00 by gwagner           #+#    #+#             */
/*   Updated: 2024/10/07 13:19:52 by gwagner          ###   ########.fr       */
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
void	put_vars(t_args **list, t_env *env, int ecode);
int 	ft_pwd(t_data **data);
int		ft_cd(t_data **data, t_cmd *cmd);
int 	ft_env(t_data **data, t_cmd *cmd);
int 	exec_built(t_cmd *cmd, t_data **data);
void	ft_printenv(t_env *head);
t_env	*find_node(const char *to_find, t_env *env);
int		ft_export(t_data **data, t_cmd *cmd);
void	free_matrix(char **str);
int		export_exist(char *data, t_env *env);
int		ft_unset(t_data **data, t_cmd *cmd);
int 	quotewordlen(char *line);
void 	trim_quotes(t_args **list);
size_t	varlen(char *data);
int		check_env(char *data, t_env *env);
t_cmd	*make_cmd(t_args *args);
int		matrix_size(char **matrix);
int		ft_echo(t_cmd *cmd);
int		pathfinder(t_env *env, char **args);
void	free_cmd(t_cmd *cmd);
void	execute_cmd(t_data **data, t_cmd *cmd, int index);
void	put_error(char **msg);
void	ft_printcmd(t_cmd *cmd);
void	execute(t_data *data, t_cmd *cmd, int index);
size_t	varlen(char *data);
void	handle_redir(t_alt **redir, int index);
void	exec_built_redir(t_data **data, t_cmd *cmd, int index, int type);
size_t	special_len(char *str);
int		is_token(char c);
void	clean_cmd(t_cmd **cmd);
void	ft_free(char **argv);
t_alt	*get_redir(t_args **args);
void	free_alt(t_alt **list);
void	print_redir(t_alt *redir);
void	execute_pipeline(t_data *data, t_cmd *cmd);
void	exec(t_data *data);
void	open_all_files(t_alt **redir);
int		check_redir_exec(t_alt *redir, int index);
int		is_a_built(char **argv);
void	open_copy_fds(t_data **data);
void	close_copy_fds(t_data **data);
char	**vecdup(char **argv, size_t len);
void	ft_cmdadd_back(t_cmd **list, t_cmd *new);
void	ft_altadd_back(t_alt **list, t_alt *new);
t_alt	*altnew(char *data, t_token token, size_t i);
int		redircheck(t_args *tmp, int i);
void	ft_waitpid(t_data **data);
void	ft_exit(t_data **data);
void	print_export(t_env *env);
void	print_exp_util(t_env *node);
void	restore_printed(t_env *env);
void	parent_process(t_data **data, t_cmd *cmd, int *prev_fd);
void	exec_pipe(t_data **data, int index, t_cmd **cmd);
void	child_process(t_data **data, t_cmd *cmd, int *prev_fd, int index);
void	open_child(t_data **data, t_cmd **cur, int index, int *prev_fd);
int		valid_name(char *arg);
int		env_lstsize_exec(t_env *env);

#endif