/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:55:59 by hzakharc          #+#    #+#             */
/*   Updated: 2024/10/09 15:41:38 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <sys/wait.h>

void	parent_process(t_data **data, t_cmd *cmd, int *prev_fd)
{
	if (*prev_fd != -1)
		ft_close(prev_fd);
	if (cmd->next)
	{
		ft_close(&(*data)->pipefd[1]);
		*prev_fd = (*data)->pipefd[0];
	}
	else
	{
		ft_close(&(*data)->pipefd[1]);
		ft_close(&(*data)->pipefd[0]);
	}
}

void	exec_pipe(t_data **data, int index, t_cmd **cmd)
{
	if (check_redir_exec((*data)->redir, index) == FALSE)
	{
		redir_error(data, index);
		exit(1);
	}
	handle_redir(&(*data)->redir, index);
	if (pathfinder((*data)->env, (*cmd)->argv) == FALSE)
	{
		put_error((char *[]){(*cmd)->argv[0],
			": Command was not found\n", NULL});
		exit(127);
	}
	execute_cmd(data, *cmd, index);
	exit(0);
}

void	child_process(t_data **data, t_cmd *cmd, int *prev_fd, int index)
{
	if (*prev_fd != -1)
	{
		dup2(*prev_fd, 0);
		ft_close(prev_fd);
	}
	if (cmd->next)
		dup2((*data)->pipefd[1], 1);
	ft_close(&(*data)->pipefd[0]);
	ft_close(&(*data)->pipefd[1]);
	if (is_a_built(cmd->argv) == TRUE)
	{
		exec_built_redir(data, cmd, index, 1);
		exit((*data)->ecode);
	}
	else
		exec_pipe(data, index, &cmd);
}

void	ft_waitpid(t_data **data)
{
	int	status;

	while (waitpid(-1, &status, 0) > 0)
	{
		if (WIFEXITED(status))
			(*data)->ecode = WEXITSTATUS(status);
	}
}

void	open_child(t_data **data, t_cmd **cur, int index, int *prev_fd)
{
	(*data)->pid = fork();
	if ((*data)->pid == -1)
	{
		perror("fork");
		exit(1);
	}
	else if ((*data)->pid == 0)
		child_process(data, *cur, prev_fd, index);
	else
	{
		(*data)->l_pid = (*data)->pid;
		parent_process(data, *cur, prev_fd);
	}
}
