/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:58:08 by hzakharc          #+#    #+#             */
/*   Updated: 2024/10/08 16:36:48 by gwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void	files_checker_append_heredoc(t_alt **cur)
{
	int	fd;

	if ((*cur)->token == REDIR_APPEND)
	{
		fd = open((*cur)->data, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (fd == -1)
		{
			put_error((char *[]){(*cur)->data,
				": No such a file or a director\n", NULL});
			(*cur)->exec = FALSE;
		}
		ft_close(&fd);
	}
}

static void	files_checker(t_alt **cur)
{
	int	fd;

	if ((*cur)->token == REDIR_IN)
	{
		fd = open((*cur)->data, O_RDONLY);
		if (fd == -1)
			(*cur)->exec = FALSE;
		ft_close(&fd);
	}
	else if ((*cur)->token == REDIR_OUT)
	{
		fd = open((*cur)->data, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
		{
			put_error((char *[]){(*cur)->data,
				": No such a file or a directory\n", NULL});
			(*cur)->exec = FALSE;
		}
		ft_close(&fd);
	}
	else if ((*cur)->token == REDIR_APPEND || (*cur)->token == HERE_DOC)
		files_checker_append_heredoc(cur);
}

void	open_all_files(t_alt **redir)
{
	t_alt	*cur;

	cur = *redir;
	execute_heredoc(redir);
	while (cur)
	{
		files_checker(&cur);
		cur = cur->next;
	}
}

void	execute_heredoc(t_alt **redir)
{
	t_alt	*temp;

	temp = *redir;
	while (temp)
	{
		if (temp->token == HERE_DOC)
		{
			here_doc(temp);
		}
		temp = temp->next;
	}
}
