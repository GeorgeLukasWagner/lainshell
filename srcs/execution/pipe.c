/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:36:23 by hzakharc          #+#    #+#             */
/*   Updated: 2024/10/07 12:55:32 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	execute_pipeline_util(t_data **data, t_cmd **cmd,
int *prev_fd, int index)
{
	if ((*cmd)->next && pipe((*data)->pipefd) == -1)
	{
		perror("pipe");
		exit(1);
	}
	else
	{
		(*data)->pid = fork();
		if ((*data)->pid == -1)
		{
			perror("fork");
			exit(1);
		}
		else if ((*data)->pid == 0)
			child_process(data, *cmd, prev_fd, index);
		else
		{
			(*data)->l_pid = (*data)->pid;
			parent_process(data, *cmd, prev_fd);
		}
	}
}

void	execute_pipeline(t_data *data, t_cmd *cmd)
{
	int		prev_fd;
	int		index;

	prev_fd = -1;
	index = 0;
	while (cmd)
	{
		execute_pipeline_util(&data, &cmd, &prev_fd, index);
		index++;
		cmd = cmd->next;
	}
	ft_waitpid(&data);
}
