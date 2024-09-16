/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 16:45:12 by hzakharc          #+#    #+#             */
/*   Updated: 2024/09/16 12:45:34 by hzakharc         ###   ########.fr       */
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

char	**create_envp(t_env *env)
{
	char	**envp;
	t_env	*temp;
	int		i;

	temp = env;
	envp = ft_calloc(sizeof(char *), env_lstsize_exec(env) + 1);
	i = 0;
	while (temp != NULL)
	{
		if (ft_strchr(temp->data, '=') != NULL)
		{
			envp[i] = ft_strdup(temp->data);
			i++;
		}
		temp = temp->next;
	}
	return (envp);
}

int	is_a_built(char **argv)
{
	if ((ft_strncmp(argv[0], "echo", ft_strlen(argv[0])) == 0)
		|| (ft_strncmp(argv[0], "cd", ft_strlen(argv[0])) == 0)
		|| (ft_strncmp(argv[0], "pwd", ft_strlen(argv[0])) == 0)
		|| (ft_strncmp(argv[0], "export", ft_strlen(argv[0])) == 0)
		|| (ft_strncmp(argv[0], "unset", ft_strlen(argv[0])) == 0)
		|| (ft_strncmp(argv[0], "env", ft_strlen(argv[0])) == 0)
		|| (ft_strncmp(argv[0], "exit", ft_strlen(argv[0])) == 0))
		return (TRUE);
	else
		return (FALSE);
}

void	execute_cmd(t_data *data, t_cmd *cmd)
{
	char	**envp;

	envp = create_envp(data->env);
	if (execve(cmd->argv[0], cmd->argv, envp) == -1)
	{
		perror(cmd->argv[0]);
		free_matrix(envp);
		return ;
	}
	free_matrix(envp);
}

void	execute(t_data *data, t_cmd *cmd)
{
	pid_t	pid;

	if (cmd->next == NULL)
	{
		if (is_a_built(cmd->argv) == TRUE)
			exec_built(cmd, data);
		else
		{
			if (pathfinder(data->env, cmd->argv) == TRUE)
			{
				pid = fork();
				if (pid == -1)
					perror("fork");
				else if (pid == 0)
				{
					// if (cmd->redir)
					// 	handle_redir(cmd->redir);
					execute_cmd(data, cmd);
				}
				waitpid(pid, 0, 0);
			}
			else
				put_error((char*[]){cmd->argv[0], ": Command was not found\n", NULL});
		}
	}
	else
	{
		//execute_pipeline();
	}
}
