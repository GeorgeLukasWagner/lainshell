/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:49:02 by hzakharc          #+#    #+#             */
/*   Updated: 2024/08/25 15:41:43 by hzakharc         ###   ########.fr       */
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
		return (ft_pwd());
	if (ft_strncmp(cmd, "export", ft_strlen(cmd)) == 0)
		return (ft_export(data));
	// if (ft_strncmp(cmd, "unset", ft_strlen(cmd)) == 0)
	// 	//coming soon^^
	if (ft_strncmp(cmd, "env", ft_strlen(cmd)) == 0)
		return (ft_env(data));
	// if (ft_strncmp(cmd, "exit", ft_strlen(cmd)) == 0)
	// 	//coming soon^^
	return (-1);
}

int	ft_pwd(void)
{
	printf("%s\n", getcwd(NULL, 0));
	return (0);
}

static void	change_dir_env(t_env **env)
{
	t_env	*pwd;
	t_env	*oldpwd;

	pwd = find_node("PWD=", *env);
	oldpwd = find_node("OLDPWD=", *env);
	free(oldpwd->data);
	oldpwd->data = ft_strdup(pwd->data);
	oldpwd->data = ft_strjoin("OLD", pwd->data);
	free(pwd->data);
	pwd->data = ft_strdup(getcwd(NULL, 0));
	pwd->data = ft_strjoin("PWD=", pwd->data);
}

static char	*find_home(t_data data)
{
	t_env	*home;
	char	*res;

	home = find_node("USER=", data.env);
	res = ft_strtrim(home->data, "USER=");
	printf("%s\n", res);
	res = ft_strjoin("/home/", res);
	if (!res)
		return (NULL);
	return (res);
}

static int		ft_cd_util(t_data data)
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
		printf("cd: %s: No such directory\n", temp->data);
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
	if (!temp->next || temp->next->token != ARG)
	{
		home = find_home(data);
		if (home)
		{
			chdir(home);
			free(home);
			change_dir_env(&data.env);
			return (0);
		}
		else
			return (-1);
	}
	return (ft_cd_util(data));
}


t_env	*find_node(const char *to_find, t_env *env)
{
	t_env	*temp;

	temp = env;
	while (temp)
	{
		if (ft_strnstr(temp->data, to_find, ft_strlen(temp->data)) != NULL)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}
