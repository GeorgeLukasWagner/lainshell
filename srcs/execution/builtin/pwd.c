/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:49:02 by hzakharc          #+#    #+#             */
/*   Updated: 2024/08/31 14:04:59 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built.h"

int	exec_built(char *cmd, t_data data)
{
	// if (ft_strncmp(cmd, "echo", ft_strlen(cmd)) == 0)
	// 	//coming soon
	if (ft_strncmp(cmd, "cd", ft_strlen(cmd)) == 0)
		return (ft_cd(data));
	if (ft_strncmp(cmd, "pwd", ft_strlen(cmd)) == 0)
		return (ft_pwd(data));
	if (ft_strncmp(cmd, "export", ft_strlen(cmd)) == 0)
		return (ft_export(data));
	if (ft_strncmp(cmd, "unset", ft_strlen(cmd)) == 0)
		return (ft_unset(data));
	if (ft_strncmp(cmd, "env", ft_strlen(cmd)) == 0)
		return (ft_env(data));
	// if (ft_strncmp(cmd, "exit", ft_strlen(cmd)) == 0)
	// 	//coming soon^^
	return (-1);
}

int	ft_pwd(t_data data)
{
	char	*pwd;
	t_env	*node;

	node = find_node("PWD=", data.env);
	pwd = ft_substr(node->data, 4, ft_strlen(node->data));
	printf("%s\n", pwd);
	free(pwd);
	return (0);
}

static void	change_dir_env(t_env **env)
{
	t_env	*pwd;
	t_env	*oldpwd;
	char	*s_pwd;

	pwd = find_node("PWD=", *env);
	oldpwd = find_node("OLDPWD=", *env);
	if (pwd == NULL || oldpwd == NULL)
		return ;
	free(oldpwd->data);
	oldpwd->data = ft_strjoin("OLDPWD=", pwd->data + 4);
	free(pwd->data);
	s_pwd = getcwd(NULL, 0);
	pwd->data = ft_strjoin("PWD=", s_pwd);
	free(s_pwd);
}

static char	*find_home(t_data data)
{
	t_env	*home;

	home = find_node("HOME=", data.env);
	if (home == NULL)
		return (NULL);
	return (ft_substr(home->data, 5, ft_strlen(home->data) - 5));
}

static int	ft_cd_util(t_data data)
{
	t_args	*temp;

	temp = data.args;
	if (temp->next->next)
	{
		if (temp->next->next->token == ARG)
		{
			printf("cd: too many arguments\n");
			return (-1);
		}
	}
	if (chdir(temp->next->data) != 0)
	{
		printf("cd: %s: No such directory\n", temp->next->data);
		return (-1);
	}
	else
	{
		change_dir_env(&data.env);
		return (0);
	}
}

int		ft_cd(t_data data)
{
	t_args	*temp;
	char	*home;

	temp = data.args;
	if (!temp->next)
	{
		home = find_home(data);
		if (home)
		{
			chdir(home);
			change_dir_env(&data.env);
			free(home);
			return (0);
		}
	}
	return (ft_cd_util(data));
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
