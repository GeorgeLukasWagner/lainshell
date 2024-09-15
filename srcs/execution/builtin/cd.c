/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 22:48:01 by hzakharc          #+#    #+#             */
/*   Updated: 2024/09/15 03:58:26 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built.h"

static void	swap_env(t_env *env, char *src, char *to_change)
{
	t_env	*temp;
	char	*res;

	temp = find_node(src, env);
	free(temp->data);
	res = ft_strjoin(src, to_change);
	temp->data = ft_strdup(res);
	free(res);
}

static void	update_dir(t_data *data)
{
	char	*temp;
	char	*pwd;
	t_env	*e_pwd;

	temp = getcwd(NULL, 0);
	if (!temp)
	{
		perror("getcwd");
		return ;
	}
	e_pwd = find_node("PWD=", data->env);
	pwd = ft_substr(e_pwd->data, 3, ft_strlen(e_pwd->data));
	swap_env(data->env, "OLDPWD=", "PWD");
	swap_env(data->env, "PWD=", temp);
	free(temp);
	free(pwd);
}

static int	change_dir(char *dir, t_data *data)
{
	t_env	*home;
	char	*home_dir;

	home = find_node("HOME=", data->env);
	if (dir == NULL)
	{
		home_dir = ft_substr(home->data, 4, ft_strlen(home->data));
		if (chdir(home_dir) == -1)
		{
			free(home_dir);
			put_error((char *[]){"cd: ", home_dir, "is not a directory\n"});
			return (1);
		}
		free(home_dir);
	}
	if (chdir(dir) == -1)
	{
		put_error((char *[]){"cd: ", dir, "is not a directory\n"});
		return (1);
	}
	return (0);
}

int	ft_cd(t_data *data, t_cmd *cmd)
{
	t_env	*home;

	if (matrix_size(cmd->argv) >= 3)
	{
		put_error((char *[]){"cd: Too many arguments\n", NULL});
		return (1);
	}
	if (matrix_size(cmd->argv) == 1)
	{
		home = find_node("HOME=", data->env);
		if (!home)
		{
			ft_putstr_fd(": cd: HOME not set\n", 2);
			return (1);
		}
		if (change_dir(NULL, data) == 1)
			return (1);
	}
	else
	{
		if (change_dir(cmd->argv[1], data) == 1)
			return (1);
	}
	update_dir(data);
	return (0);
}
