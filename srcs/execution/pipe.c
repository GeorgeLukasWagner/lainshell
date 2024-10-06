/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:36:23 by hzakharc          #+#    #+#             */
/*   Updated: 2024/10/06 16:10:48 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

// static void	pipe_built(t_data **data, t_cmd *cmd, int *prev_fd, int index)
// {
// 	open_copy_fds(data);
// 	if (*prev_fd != -1)
// 	{
// 		dup2(*prev_fd, 0);
// 		close(*prev_fd);
// 	}
// 	if (cmd->next)
// 		dup2((*data)->pipefd[1], 1);
// 	exec_built_redir(data, cmd, index);
// 	close((*data)->pipefd[0]);
// 	close((*data)->pipefd[1]);
// }

static void	parent_process(t_data **data, t_cmd *cmd, int *prev_fd)
{
	if (*prev_fd != -1)
		close(*prev_fd);
	if (cmd->next)
	{
		close((*data)->pipefd[1]);
		*prev_fd = (*data)->pipefd[0];
	}
	else
	{
		close((*data)->pipefd[1]);
		close((*data)->pipefd[0]);
	}
}

static void child_process(t_data **data, t_cmd *cmd, int *prev_fd, int index)
{
	if (*prev_fd != -1)
	{
		dup2(*prev_fd, 0);
		close(*prev_fd);
	}
	if (cmd->next)
		dup2((*data)->pipefd[1], 1);
	close((*data)->pipefd[0]);
	close((*data)->pipefd[1]);
	if (is_a_built(cmd->argv) == TRUE)
	{
		exec_built_redir(data, cmd, index, 1);
		exit((*data)->ecode);
	}
	else
	{
		print_redir((*data)->redir);
		handle_redir(&(*data)->redir, index);
		if (pathfinder((*data)->env, cmd->argv) == FALSE)
		{
			put_error((char *[]){cmd->argv[0], ": Command was not found\n", NULL});
			exit(127);
		}
		execute_cmd(data, cmd, index);
		exit(0);
	}
}

void	execute_pipeline(t_data *data, t_cmd *cmd)
{
	int		prev_fd;
	int		index;
	t_cmd	*cur;
	pid_t	last_pid;

	prev_fd = -1;
	cur = cmd;
	index = 0;
	while (cur)
	{
		if (cmd->next && pipe(data->pipefd) == -1)
		{
			perror("pipe");
			exit(1);
		}
		else
		{
			data->pid = fork();
			if (data->pid == -1)
			{
				perror("fork");
				exit(1);
			}
			else if (data->pid == 0)
				child_process(&data, cur, &prev_fd, index);
			else
			{
				last_pid = data->pid;
				parent_process(&data, cur, &prev_fd);
			}
		}
		index++;
		cur = cur->next;
	}
	while (waitpid(-1, NULL, 0) > 0);
}
