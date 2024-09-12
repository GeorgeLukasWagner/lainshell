/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:18:53 by hzakharc          #+#    #+#             */
/*   Updated: 2024/09/10 18:19:42 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built.h"

static void	restore_printed(t_env *env)
{
	t_env	*temp;

	temp = env;
	while (temp)
	{
		temp->printed = 0;
		temp = temp->next;
	}
}

void	free_matrix(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i] != NULL)
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
}

static void	print_exp_util(t_env *node)
{
	char	**temp;

	if (!node)
		return ;
	if (ft_strncmp(node->data, "_=", 2) == 0)
		return ;
	if (ft_strchr(node->data, '=') == NULL)
		printf("declare -x %s\n", node->data);
	else if (node->data != NULL)
	{
		temp = ft_split(node->data, '=');
		printf("declare -x %s", temp[0]);
		printf("=\"%s\"\n", temp[1]);
		free_matrix(temp);
	}
}

static void	print_export(t_env *env)
{
	t_env	*cur;
	t_env	*start;
	t_env	*min;

	start = env;
	while (1)
	{
		min = NULL;
		cur = start;
		while (cur != NULL)
		{
			if (!cur->printed && ((min == NULL)
				|| (ft_strncmp(min->data, cur->data, ft_strlen(cur->data)) > 0)))
				min = cur;
			cur = cur->next;
		}
		if (min == NULL)
			break;
		print_exp_util(min);
		min->printed = 1;
	}
	restore_printed(env);
}

int	valid_name(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '=' && arg[i] != '\0')
	{
		if (arg[i] == '-')
			return (-1);
		i++;
	}
	return (0);
}

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

int	ft_export(t_data *data)
{
	t_cmd	*temp;
	int		i;

	temp = data->cmd;
	if (matrix_size(temp->argv) == 1)
		print_export(data->env);
	i = 1;
	while (temp->argv[i] != NULL)
	{
		if (valid_name(temp->argv[i]) == -1)
			return (-1);
		if (ft_strchr(temp->argv[i], '=') != NULL)
		{
			if (export_exist(temp->argv[i], data->env) == 0)
				delete_and_add_exp(temp->argv[i], data->env);
			else
				add_exp(temp->argv[i], data->env);
		}
		else
		{
			add_exp2(temp->argv[i], data->env);
		}
		i++;
	}
	return (0);
}
