/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:26:28 by hzakharc          #+#    #+#             */
/*   Updated: 2024/09/28 01:27:16 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void	in_redir(char *name)
{
	int fd;

	fd = open(name, O_RDONLY);
	if (fd == -1)
	{
		put_error((char *[]){name, ": No such a file or a director\n", NULL});
		exit(1);
	}
	if (dup2(fd, 0) == -1)
	{
		put_error((char *[]){name, ": No such a file or a director\n", NULL});
		exit(1);
	}
	close(fd);
}

static void	out_redir(char *name)
{
	int	fd;

	fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		put_error((char *[]){name, ": No such a file or a director\n", NULL});
		exit(1);
	}
	if (dup2(fd, 1) == -1)
	{
		put_error((char *[]){name, ": No such a file or a director\n", NULL});
		exit(1);
	}
	close(fd);
}

static void	append_redir(char *name)
{
	int	fd;

	fd = open(name, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		put_error((char *[]){name, ": No such a file or a director\n", NULL});
		exit(1);
	}
	if (dup2(fd, 1) == -1)
	{
		put_error((char *[]){name, ": No such a file or a director\n", NULL});
		exit(1);
	}
	close(fd);
}

static void	heredoc_redir(void)
{
	int	fd;

	fd = open(".heredoc", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Cannot access heredoc\n", 2);
		exit(1);
	}
	if (dup2(fd, 0) == -1)
	{
		ft_putstr_fd("heredoc: No such a file or a directory\n", 2);
		exit(1);
	}
	close(fd);
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

void	exec_built_redir(t_data *data, t_cmd *cmd, int index)
{
	int		in_copy;
	int		out_copy;
	t_alt	*temp;

	in_copy = dup(0);
	out_copy = dup(1);
	if (data->redir)
	{
		temp = data->redir;
		while (temp && temp->index != index)
			temp = temp->next;
		if (temp != NULL)
		{
			if (data->redir)
				if (check_redir_exec(data->redir, index) == FALSE)
				{
					close(in_copy);
					close(out_copy);
					return ;
				}
			if (ft_strncmp(cmd->argv[0], "exit", ft_strlen(cmd->argv[0])) == 0)
			{
				close(in_copy);			//maybe not working (trying to handle exit function)
				close(out_copy);
				exec_built(cmd, data);
			}
			handle_redir(&data->redir, index);
		}
	}
	exec_built(cmd, data);
	if (dup2(in_copy, 0) == -1 || dup2(out_copy, 1) == -1)
		perror("dup2");
	close(in_copy);
	close(out_copy);
}
