/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:58:08 by hzakharc          #+#    #+#             */
/*   Updated: 2024/10/07 12:59:02 by hzakharc         ###   ########.fr       */
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
		close(fd);
	}
	// else if (cur->token == HERE_DOC)
		// 	//here_doc execute;
}

static void	files_checker(t_alt **cur)
{
	int	fd;

	if ((*cur)->token == REDIR_IN)
	{
		fd = open((*cur)->data, O_RDONLY);
		if (fd == -1)
			(*cur)->exec = FALSE;
		close(fd);
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
		close(fd);
	}
	else if ((*cur)->token == REDIR_APPEND || (*cur)->token == HERE_DOC)
		files_checker_append_heredoc(cur);
}

void	open_all_files(t_alt **redir)
{
	t_alt	*cur;

	cur = *redir;
	while (cur)
	{
		files_checker(&cur);
		cur = cur->next;
	}
}
