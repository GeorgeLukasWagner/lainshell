/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:26:28 by hzakharc          #+#    #+#             */
/*   Updated: 2024/10/07 17:19:31 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#define PIPE 1
#define PARENT 0

static void	in_redir(char *name)
{
	int	fd;

	fd = open(name, O_RDONLY);
	printf("FD IS %d\n", fd);
	if (fd == -1)
	{
		put_error((char *[]){name, ": No such a file or a director1\n", NULL});
		return ;
	}
	if (dup2(fd, 0) == -1)
	{
		put_error((char *[]){name, ": No such a file or a director\n", NULL});
		return ;
	}
	ft_close(&fd);
}

static void	out_redir(char *name)
{
	int	fd;

	fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		put_error((char *[]){name, ": No such a file or a director\n", NULL});
		return ;
	}
	if (dup2(fd, 1) == -1)
	{
		put_error((char *[]){name, ": No such a file or a director\n", NULL});
		return ;
	}
	ft_close(&fd);
}

static void	append_redir(char *name)
{
	int	fd;

	fd = open(name, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		put_error((char *[]){name, ": No such a file or a director\n", NULL});
		return ;
	}
	if (dup2(fd, 1) == -1)
	{
		put_error((char *[]){name, ": No such a file or a director\n", NULL});
		return ;
	}
	ft_close(&fd);
}

static void	heredoc_redir(void)
{
	int	fd;

	fd = open("/tmp/.heredoc", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Cannot access heredoc\n", 2);
		return ;
	}
	if (dup2(fd, 0) == -1)
	{
		ft_putstr_fd("heredoc: No such a file or a directory\n", 2);
		return ;
	}
	ft_close(&fd);
}

void	handle_redir(t_alt **redir, int index)
{
	t_alt	*temp;

	if (redir != NULL)
	{
		temp = *redir;
		while (temp && temp->index != index)
			temp = temp->next;
		while (temp && temp->index == index)
		{
			if (temp->token == REDIR_IN)
				in_redir(temp->data);
			if (temp->token == REDIR_OUT)
				out_redir(temp->data);
			if (temp->token == REDIR_APPEND)
				append_redir(temp->data);
			if (temp->token == HERE_DOC)
				heredoc_redir();
			temp = temp->next;
		}
	}
}
