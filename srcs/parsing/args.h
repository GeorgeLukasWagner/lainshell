#ifndef ARGS_H
# define ARGS_H

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

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
}   t_token;

typedef struct s_args
{
    char            *data;
    t_token         token;
    struct s_args	*next;
}	t_args;

void	free_list(t_args **list);
t_args	*ft_lstnew(char *data, t_token token);
void	ft_lstadd_front(t_args **list, t_args *new);
void	ft_lstadd_back(t_args **list, t_args *new);
int	    ft_lstsize(t_args *head);
t_args	*ft_lstlast(t_args *head);
void	ft_printlst(t_args *head);

#endif