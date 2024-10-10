/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 22:48:01 by hzakharc          #+#    #+#             */
/*   Updated: 2024/10/10 16:20:18 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built.h"

static int	change_dir(char *dir, t_data *data)
{
	t_env	*home;
	char	*home_dir;

	home = find_node("HOME=", data->env);
	if (dir == NULL)
	{
		home_dir = ft_substr(home->data, 5, ft_strlen(home->data));
		if (chdir(home_dir) == -1)
		{
			put_error((char *[]){"cd: ",
				home_dir, " is not a directory\n", NULL});
			free(home_dir);
			return (1);
		}
		free(home_dir);
		return (0);
	}
	if (chdir(dir) == -1)
	{
		put_error((char *[]){"cd: ", dir, " is not a directory\n", NULL});
		return (1);
	}
	return (0);
}

static int	check_env_cd(t_env **env)
{
	t_env	*pwd;
	t_env	*oldpwd;

	pwd = NULL;
	oldpwd = NULL;
	pwd = find_node("PWD=", *env);
	oldpwd = find_node("OLDPWD=", *env);
	if (!pwd || !oldpwd)
		return (FALSE);
	return (TRUE);
}

static int	cd_checker(t_data **data, t_cmd *cmd)
{
	if (check_env_cd(&(*data)->env) == FALSE)
	{
		put_error((char *[]){"why u unseted pwd or oldpwd fuck you\n", NULL});
		return (1);
	}
	if (matrix_size(cmd->argv) >= 3)
	{
		put_error((char *[]){"cd: Too many arguments\n", NULL});
		return (1);
	}
	else
	{
		if (change_dir(cmd->argv[1], *data) == 1)
			return (1);
	}
	return (0);
}

int	ft_cd(t_data **data, t_cmd *cmd)
{
	t_env	*home;

	if (cd_checker(data, cmd) == 1)
		return (1);
	if (matrix_size(cmd->argv) == 1)
	{
		home = find_node("HOME=", (*data)->env);
		if (!home)
		{
			ft_putstr_fd(": cd: HOME not set\n", 2);
			return (1);
		}
		if (change_dir(NULL, *data) == 1)
			return (1);
	}
	update_dir(*data);
	return (0);
}
