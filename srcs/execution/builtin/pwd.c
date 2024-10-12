/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:49:02 by hzakharc          #+#    #+#             */
/*   Updated: 2024/10/12 18:02:20 by hzakharc         ###   ########.fr       */
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
	if (matrix_size(argv) > 2 && check_num(argv) == FALSE)
	{
		printf("minishell: numeric argument required\n");
		return (1);
	}
	if (matrix_size(argv) > 2)
	{
		printf("minishell to many arguments\n");
		ecode = 2;
	}
	else if (check_num(argv) == FALSE)
	{
		printf("minishell: too many arguments\n");
		ecode = 2;
	}
	else if (matrix_size(argv) == 2)
	{
		ecode = ft_atoi(argv[1]);
		if (ecode > 255)
			ecode %= 128;
	}
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
	pwd = NULL;
	if (!node)
	{
		printf("%s\n", getcwd(pwd, 1024));
		free(pwd);
		return (0);
	}
	pwd = ft_substr(node->data, 4, ft_strlen(node->data));
	printf("%s\n", pwd);
	free(pwd);
	return (0);
}
