/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:36:23 by hzakharc          #+#    #+#             */
/*   Updated: 2024/09/17 14:56:25 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	execute_pipeline(t_data *data, t_cmd *cmd)
{
	int pipefd[2];
	int prev_fd;

	while (cmd)
	{
		if (cmd->next)
			pipe(pipefd);
		cmd->pid = fork();
		if (cmd->pid == 0)
		{
			if (prev_fd)
			{
				dup2(prev_fd, 0);
				close(prev_fd);
			}
			if (cmd->next)
			{
				close(pipefd[0]);
				dup2(pipefd[1], 1);
				close(pipefd[1]);
			}
			execute(data, cmd);
		}
		if (cmd->pid > 0)
		{
			close(pipefd[1]);
			if (prev_fd)
				close(prev_fd);
			prev_fd = pipefd[0];
			waitpid(cmd->pid, NULL, 0);
		}
		else
			perror("fork");
		cmd = cmd->next;
	}
}
