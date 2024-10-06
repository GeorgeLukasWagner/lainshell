/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:26:28 by hzakharc          #+#    #+#             */
/*   Updated: 2024/10/04 18:44:27 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
# define PIPE 1
# define PARENT 0

static void	in_redir(char *name)
{
	int fd;

	fd = open(name, O_RDONLY);
	printf("FD IS %d\n", fd);
	if (fd == -1)
	{
		put_error((char *[]){name, ": No such a file or a director1\n", NULL});
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

void	open_copy_fds(t_data **data)
{
	(*data)->fd[0] = dup(0);
	(*data)->fd[1] = dup(1);
}

void	close_copy_fds(t_data **data)
{
	close((*data)->fd[0]);
	close((*data)->fd[1]);
}

void	exec_built_redir(t_data **data, t_cmd *cmd, int index, int type)
{
	t_alt	*temp;

	if ((*data)->redir)
	{
		temp = (*data)->redir;
		while (temp && temp->index != index)
			temp = temp->next;
		if (temp != NULL)
		{
			if ((*data)->redir)
				if (check_redir_exec((*data)->redir, index) == FALSE)
				{
					close_copy_fds(data);
					return ;
				}
			if (ft_strncmp(cmd->argv[0], "exit", ft_strlen(cmd->argv[0])) == 0)
			{
				close_copy_fds(data);
				exec_built(cmd, data);
			}
			handle_redir(&(*data)->redir, index);
		}
	}
	(*data)->ecode = exec_built(cmd, data);
	if (type == PARENT)
	{
		if (dup2((*data)->fd[0], 0) == -1 || dup2((*data)->fd[1], 1) == -1)
			perror("dup2");
		close((*data)->fd[0]);
		close((*data)->fd[1]);
	}
}
