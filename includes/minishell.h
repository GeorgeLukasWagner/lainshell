/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:31:12 by gwagner           #+#    #+#             */
/*   Updated: 2024/08/19 17:45:11 by gwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <dirent.h>
# include <string.h>
# include <sys/ioctl.h>
# include <fcntl.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include <sys/wait.h>
# include <signal.h>
# include "libft/srcs/libft.h"

typedef enum e_token
{
	COMMAND,
	FLAG,
	INPUT,
	ERROR
}	t_token;

typedef struct s_env
{
	char			*data;
	struct s_env	*next;
}	t_env;

typedef struct s_data
{
	t_env	*env;
	char	**args;
}	t_data;

t_env	*ft_lstnew(int data);
void	ft_lstadd_back(t_env **env, t_env *new);
int		ft_lstsize(t_env *head);

#endif