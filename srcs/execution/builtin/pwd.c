/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:49:02 by hzakharc          #+#    #+#             */
/*   Updated: 2024/10/06 18:35:57 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built.h"

int	exec_built(t_cmd *cmd, t_data **data)
{
	if (ft_strncmp(cmd->argv[0], "echo", ft_strlen(cmd->argv[0])) == 0)
		return (ft_echo(cmd));
	if (ft_strncmp(cmd->argv[0], "cd", ft_strlen(cmd->argv[0])) == 0)
		return (ft_cd(data, cmd));
	if (ft_strncmp(cmd->argv[0], "pwd", ft_strlen(cmd->argv[0])) == 0)
		return (ft_pwd(data));
	if (ft_strncmp(cmd->argv[0], "export", ft_strlen(cmd->argv[0])) == 0)
		return (ft_export(data, cmd));
	if (ft_strncmp(cmd->argv[0], "unset", ft_strlen(cmd->argv[0])) == 0)
		return (ft_unset(data, cmd));
	if (ft_strncmp(cmd->argv[0], "env", ft_strlen(cmd->argv[0])) == 0)
		return (ft_env(data, cmd));
	if (ft_strncmp(cmd->argv[0], "exit", ft_strlen(cmd->argv[0])) == 0)
		ft_exit(data);
	return (-1);
}

void	ft_exit(t_data **data)
{
	printf("exit\n");
	clean_cmd(&(*data)->cmd);
	free_cmd((*data)->cmd);
	free_alt(&(*data)->redir);
	free_list(&(*data)->args);
	exit(0);
}

int	matrix_size(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
		i++;
	return (i);
}

int	ft_pwd(t_data **data)
{
	char	*pwd;
	t_env	*node;

	node = find_node("PWD=", (*data)->env);
	pwd = ft_substr(node->data, 4, ft_strlen(node->data));
	printf("%s\n", pwd);
	free(pwd);
	return (0);
}

t_env	*find_node(const char *to_find, t_env *env)
{
	t_env	*temp;

	temp = env;
	while (temp)
	{
		if (ft_strncmp(temp->data, to_find, ft_strlen(to_find)) == 0)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}
