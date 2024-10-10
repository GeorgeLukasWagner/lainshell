/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:19:44 by hzakharc          #+#    #+#             */
/*   Updated: 2024/10/10 16:43:07 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built.h"

void	swap_env(t_env *env, char *src, char *to_change)
{
	t_env	*temp;
	char	*res;

	temp = find_node(src, env);
	free(temp->data);
	res = ft_strjoin(src, to_change);
	temp->data = ft_strdup(res);
	free(res);
}

void	update_dir(t_data *data)
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
	swap_env(data->env, "OLDPWD=", e_pwd->data + 4);
	swap_env(data->env, "PWD=", temp);
	free(temp);
	free(pwd);
}
