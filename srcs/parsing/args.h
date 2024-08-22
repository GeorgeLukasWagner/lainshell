/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:38:57 by gwagner           #+#    #+#             */
/*   Updated: 2024/08/22 14:51:41 by gwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_H
# define ARGS_H

# include <stdio.h>
# include <stdlib.h>
# include "../../includes/minishell.h"

typedef enum e_token
{
	CMD,
	ARG,
	QUOTE,
	DOUBLE_QUOTE,
	REDIR_IN,
	REDIR_OUT,
	PIPE,
	HERE_DOC,
	REDIR_APPEND
}		t_token;

typedef struct s_args
{
	char			*data;
	t_token			token;
	struct s_args	*next;
}		t_args;

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

#endif