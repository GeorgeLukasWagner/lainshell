/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 10:20:28 by hzakharc          #+#    #+#             */
/*   Updated: 2024/10/07 13:00:06 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#define PIPE 1
#define PARENT 0

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

static void	exec_built_util(t_data **data, int index, t_cmd **cmd)
{
	if ((*data)->redir)
	{
		if (check_redir_exec((*data)->redir, index) == FALSE)
		{
			close_copy_fds(data);
			return ;
		}
	}
	if (ft_strncmp((*cmd)->argv[0], "exit", ft_strlen((*cmd)->argv[0])) == 0)
	{
		close_copy_fds(data);
		exec_built(*cmd, data);
	}
	handle_redir(&(*data)->redir, index);
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
			exec_built_util(data, index, &cmd);
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

int	check_redir_exec(t_alt *redir, int index)
{
	t_alt	*cur;

	cur = redir;
	while (cur && cur->index != index)
		cur = cur->next;
	while (cur && cur->index == index)
	{
		if (cur->exec == FALSE)
			exit(1);
		cur = cur->next;
	}
	return (TRUE);
}
