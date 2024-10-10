/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:58:08 by hzakharc          #+#    #+#             */
/*   Updated: 2024/10/10 16:41:32 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	ft_error_file(t_data *data, char *name)
{
	if (data->error_file == 0)
	{
		put_error((char *[]){name,
			": No such a file or a directory\n", NULL});
		data->error_file = 1;
	}
}

static void	files_checker_append_heredoc(t_alt **cur, t_data *data)
{
	int	fd;

	if ((*cur)->token == REDIR_APPEND)
	{
		fd = open((*cur)->data, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (fd == -1)
		{
			ft_error_file(data, (*cur)->data);
			(*cur)->exec = FALSE;
		}
		ft_close(&fd);
	}
}

static void	files_checker(t_alt **cur, t_data *data)
{
	int	fd;

	if ((*cur)->token == REDIR_IN)
	{
		fd = open((*cur)->data, O_RDONLY);
		if (fd == -1)
		{
			ft_error_file(data, (*cur)->data);
			(*cur)->exec = FALSE;
		}
		ft_close(&fd);
	}
	else if ((*cur)->token == REDIR_OUT)
	{
		fd = open((*cur)->data, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
		{
			ft_error_file(data, (*cur)->data);
			(*cur)->exec = FALSE;
		}
		ft_close(&fd);
	}
	else if ((*cur)->token == REDIR_APPEND || (*cur)->token == HERE_DOC)
		files_checker_append_heredoc(cur, data);
}

void	open_all_files(t_alt **redir, t_data *data)
{
	t_alt	*cur;

	cur = *redir;
	execute_heredoc(redir, data);
	while (cur)
	{
		files_checker(&cur, data);
		cur = cur->next;
	}
}

void	execute_heredoc(t_alt **redir, t_data *data)
{
	t_alt	*temp;
	pid_t	pid;

	temp = *redir;
	while (temp)
	{
		if (temp->token == HERE_DOC)
		{
			pid = fork();
			if (pid == -1)
			{
				perror("fork");
				return ;
			}
			if (pid == 0)
				here_doc(temp, data);
		}
		temp = temp->next;
	}
	wait(NULL);
}
