/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 10:21:54 by gwagner           #+#    #+#             */
/*   Updated: 2024/09/19 13:17:29 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef enum e_token
{
	CMD,
	ARG,
	DOUBLE_QUOTE,
	QUOTE,
	REDIR_IN,
	REDIR_OUT,
	PIPE,
	HERE_DOC,
	REDIR_APPEND
}		t_token;

typedef enum e_redir_type
{
	IN,
	OUT,
	APPEND,
	HEREDOC
}		t_redir_type;

typedef struct s_args
{
	char			*data;
	t_token			token;
	bool			append;
	struct s_args	*next;
}		t_args;

typedef struct s_env
{
	int				printed;
	char			*data;
	struct s_env	*next;
}	t_env;

typedef struct s_alt
{
	char			*data;
	t_token			token;
	int				index;
	struct s_alt	*next;
}	t_alt;

typedef struct s_redir
{
	t_redir_type	type;
	char			*name;
	struct s_redir	*next;
}	t_redir;

typedef struct s_cmd
{
	char			**argv;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_data
{
	t_env	*env;
	t_args	*args;
	t_cmd	*cmd;
}	t_data;

#endif
//i will go insane soon
