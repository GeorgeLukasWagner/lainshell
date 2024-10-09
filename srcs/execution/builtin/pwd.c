/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:49:02 by hzakharc          #+#    #+#             */
/*   Updated: 2024/10/09 14:55:57 by hzakharc         ###   ########.fr       */
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
		return (ft_exit(data, cmd->argv));
	return (-1);
}

static int	check_num(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

int	ft_exit(t_data **data, char **argv)
{
	int	ecode;

	ecode = 0;
	if (check_num(argv) == FALSE)
	{
		printf("minishell: numeric argument required\n");
		ecode = 2;
	}
	else if (matrix_size(argv) > 2)
	{
		printf("minishell: too many arguments\n");
		return(1);
	}
	else if (matrix_size(argv) == 2)
		ecode = atoi(argv[1]);
	printf("exit\n");
	clean_cmd(&(*data)->cmd);
	free_cmd((*data)->cmd);
	free_alt(&(*data)->redir);
	free_list(&(*data)->args);
	exit(ecode);
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
