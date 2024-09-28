/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:36:23 by hzakharc          #+#    #+#             */
/*   Updated: 2024/09/28 03:20:08 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	execute_pipeline(t_data *data, t_cmd *cmd)
{
	int		pipefd[2];
	int		prev_fd;
	int		index;
	pid_t	pid;
	t_cmd	*cur;

	prev_fd = -1;
	cur = cmd;
	index = 0;
	while (cur)
	{
		if (cur->next)
		{
			if (pipe(pipefd) == -1)
			{
				perror("pipe");
				exit(1);
			}
		}
		if (is_a_built(cur->argv) == TRUE)
		{
			if (prev_fd != -1)
			{
				dup2(prev_fd, 0);
				close(prev_fd);
			}
			if (cur->next)
			{
				dup2(pipefd[1], 1);
				close(pipefd[0]);
				close(pipefd[1]);
			}
			exec_built_redir(data, cur, index);
			if (cur->next)
			{
				prev_fd = pipefd[0];
				close(pipefd[1]);
			}
			else
				close(pipefd[0]);
			index++;
			cur = cur->next;
		}
		else
		{
			pid = fork();
			if (pid == -1)
			{
				perror("fork");
				exit(1);
			}
			else if (pid == 0)
			{
				if (prev_fd != -1)
				{
					dup2(prev_fd, 0);
					close(prev_fd);
				}
				if (cur->next)
				{
					dup2(pipefd[1], 1);
					close(pipefd[1]);
					close(pipefd[0]);
				}
				handle_redir(&data->redir, index);
				if (pathfinder(data->env, cur->argv) == FALSE)
				{
					put_error((char *[]){cmd->argv[0], ": Command was not found\n", NULL});
					exit(127);
				}
				execute_cmd(data, cur);
				exit(0);
			}
			else
			{
				if (prev_fd != -1)
					close(prev_fd);
				if (cur->next)
				{
					close(pipefd[1]);
					prev_fd = pipefd[0];
				}
				else
				{
					close(pipefd[1]);
					close(pipefd[0]);
				}
				index++;
				cur = cur->next;
			}
		}
	}
	while (waitpid(-1, NULL, 0) > 0);
}

//i literally have no idea how to fix pipeline for built ins
