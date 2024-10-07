/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:18:53 by hzakharc          #+#    #+#             */
/*   Updated: 2024/10/07 11:47:04 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built.h"

int	export_exist(char *data, t_env *env)
{
	t_env	*temp;
	char	*temp_str;
	int		i;

	i = 0;
	temp = env;
	while (data[i] != '=' && data[i] != '\0')
		i++;
	if (data[i] == '\0')
		temp_str = ft_strdup(data);
	else
		temp_str = ft_substr(data, 0, i);
	while (temp != NULL)
	{
		if (ft_strncmp(temp->data, temp_str, ft_strlen(temp_str)) == 0)
		{
			free(temp_str);
			return (0);
		}
		temp = temp->next;
	}
	free(temp_str);
	return (-1);
}

static void	add_exp(char *str, t_env *env)
{
	t_env	*new;
	char	*res;

	res = ft_strdup(str);
	new = env_lstnew(res);
	env_lstadd_back(&env, new);
}

static void	delete_and_add_exp(char *str, t_env *env)
{
	t_env	*temp;
	int		i;

	i = 0;
	temp = env;
	while (str[i] != '=')
		i++;
	while (temp)
	{
		if (ft_strncmp(str, temp->data, i) == 0)
		{
			free(temp->data);
			temp->data = ft_strdup(str);
		}
		temp = temp->next;
	}
}

static void	add_exp2(char *str, t_env *env)
{
	t_env	*temp;
	char	*res;

	if (export_exist(str, env) == 0)
	{
		return ;
	}
	else
	{
		res = ft_strdup(str);
		temp = env_lstnew(res);
		env_lstadd_back(&env, temp);
	}
}

int	ft_export(t_data **data, t_cmd *cmd)
{
	t_cmd	*temp;
	int		i;

	temp = cmd;
	if (matrix_size(temp->argv) == 1)
		print_export((*data)->env);
	i = 1;
	while (temp->argv[i] != NULL)
	{
		if (valid_name(temp->argv[i]) == -1)
			return (-1);
		if (ft_strchr(temp->argv[i], '=') != NULL)
		{
			if (export_exist(temp->argv[i], (*data)->env) == 0)
				delete_and_add_exp(temp->argv[i], (*data)->env);
			else
				add_exp(temp->argv[i], (*data)->env);
		}
		else
			add_exp2(temp->argv[i], (*data)->env);
		i++;
	}
	return (0);
}
