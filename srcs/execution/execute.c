/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 16:45:12 by hzakharc          #+#    #+#             */
/*   Updated: 2024/10/10 16:31:34 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	env_lstsize_exec(t_env *env)
{
	t_env	*temp;
	int		i;

	temp = env;
	i = 0;
	while (temp)
	{
		if (ft_strchr(temp->data, '=') != NULL)
			i++;
		temp = temp->next;
	}
	return (i);
}

void	redir_error(t_data **data, int index)
{
	t_alt	*cur;

	cur = (*data)->redir;
	if (cur->index == index)
	{
		while (cur->index != index)
			cur = cur->next;
	}
	put_error((char *[]){cur->data, ": No such file or a directory\n", NULL});
}

static void	execute_util(t_data *data, t_cmd *cmd, int index)
{
	if (data->redir)
	{
		if (check_redir_exec(data->redir, index) == FALSE)
			return (redir_error(&data, index));
	}
	data->pid = fork();
	if (data->pid == -1)
		perror("fork");
	else if (data->pid == 0)
	{
		if (pathfinder(data->env, cmd->argv) == FALSE)
		{
			put_error((char *[]){cmd->argv[0],
				": Command was not found\n", NULL});
			exit(127);
		}
		handle_redir(&data->redir, index);
		execute_cmd(&data, cmd, index);
	}
	ft_waitpid(&data);
}

void	execute(t_data *data, t_cmd *cmd, int index)
{
	if (cmd->argv == NULL)
		return ;
	if (is_a_built(cmd->argv) == TRUE)
	{
		open_copy_fds(&data);
		exec_built_redir(&data, cmd, index, 0);
	}
	else
		execute_util(data, cmd, index);
}

void	exec(t_data *data)
{
	if (data->cmd->next == NULL)
		execute(data, data->cmd, 0);
	else
		execute_pipeline(data, data->cmd);
}
