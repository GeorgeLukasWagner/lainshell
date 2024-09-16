/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:26:28 by hzakharc          #+#    #+#             */
/*   Updated: 2024/09/15 03:58:57 by hzakharc         ###   ########.fr       */
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
		put_error((char *[]){name, ": No such a file or a director\n", NULL});
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
		put_error((char *[]){name, ": No such a file or a director\n", NULL});
	close(fd);
}

static void	appen_redir(char *name)
{
	int	fd;

	fd = open(name, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		put_error((char *[]){name, ": No such a file or a director\n", NULL});
		exit(1);
	}
	if (dup2(fd, 1) == -1)
		put_error((char *[]){name, ": No such a file or a director\n", NULL});
	close(fd);
}

void	handle_redir(t_redir *redir)
{
	t_redir	*temp;

	temp = redir;
	while (temp)
	{
		if (temp->type == IN)
			in_redir(temp->name);
		if (temp->type == OUT)
			out_redir(temp->name);
		if (temp->type == APPEND)
			appen_redir(temp->name);
		temp = temp->next;
	}
}

void	exec_built_redir(t_data *data, t_cmd *cmd)
{
	int	in_copy;
	int	out_copy;

	if (cmd->redir)
	{
		in_copy = dup(0);
		out_copy = dup(1);
		//handle_redir(cmd->redir);
		if (ft_strncmp(cmd->argv[0], "exit", ft_strlen(cmd->argv[0])))
		{
			close(in_copy);			//maybe not working (trying to handle exit function)
			close(out_copy);
			exec_built(cmd, data);
		}
		exec_built(cmd, data);
		if (dup2(in_copy, 0) == -1 || dup2(out_copy, 1) == -1)
		{
			perror("dup2");
			exit(1);
		}
		close(in_copy);
		close(out_copy);
	}
}
