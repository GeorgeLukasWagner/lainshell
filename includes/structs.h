/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 10:21:54 by gwagner           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/09/04 11:09:42 by gwagner          ###   ########.fr       */
=======
/*   Updated: 2024/09/03 13:57:00 by hzakharc         ###   ########.fr       */
>>>>>>> refs/remotes/origin/main
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

typedef struct s_cmd
{
	char			**argv;
	struct s_cmd	*next;
} t_cmd;
typedef struct s_data
{
	t_env	*env;
	t_args	*args;
	t_cmd	*cmd;
}	t_data;


<<<<<<< HEAD
typedef struct s_data
{
	t_env	*env;
	t_args	*args;
	t_cmd	*cmd;
}	t_data;


#endif
=======
#endif
//i will go insane soon
>>>>>>> refs/remotes/origin/main
