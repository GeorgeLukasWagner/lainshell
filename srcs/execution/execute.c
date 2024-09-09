/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 16:45:12 by hzakharc          #+#    #+#             */
/*   Updated: 2024/09/09 13:06:55 by hzakharc         ###   ########.fr       */
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

void	execute_cmd(t_data *data, t_cmd *cmd)
{
	char **envp;

	envp = create_envp(data->env);
	if ((ft_strncmp(cmd->argv[0], "echo", ft_strlen(cmd->argv[0])) == 0)
		|| (ft_strncmp(cmd->argv[0], "cd", ft_strlen(cmd->argv[0])) == 0)
		|| (ft_strncmp(cmd->argv[0], "pwd", ft_strlen(cmd->argv[0])) == 0)
		|| (ft_strncmp(cmd->argv[0], "export", ft_strlen(cmd->argv[0])) == 0)
		|| (ft_strncmp(cmd->argv[0], "unset", ft_strlen(cmd->argv[0])) == 0)
		|| (ft_strncmp(cmd->argv[0], "env", ft_strlen(cmd->argv[0])) == 0)
		|| (ft_strncmp(cmd->argv[0], "exit", ft_strlen(cmd->argv[0])) == 0))
		exec_built(cmd->argv[0], data);
	else
	{
		pathfinder(data->env, cmd->argv);
		execve(cmd->argv[0], cmd->argv, envp);
	}
	free_matrix(envp);
}
