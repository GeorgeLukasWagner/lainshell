/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_util2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:00:23 by hzakharc          #+#    #+#             */
/*   Updated: 2024/10/08 20:23:28 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

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

void	execute_cmd(t_data **data, t_cmd *cmd, int index)
{
	char	**envp;

	envp = create_envp((*data)->env);
	if (check_redir_exec((*data)->redir, index) == FALSE)
		exit(1);
	if (execve(cmd->argv[0], cmd->argv, envp) == -1)
	{
		perror(cmd->argv[0]);
		free_matrix(envp);
		exit(127);
	}
	free_matrix(envp);
}

void	ft_close(int *fd)
{
	if (*fd >= 0)
		close(*fd);
}
