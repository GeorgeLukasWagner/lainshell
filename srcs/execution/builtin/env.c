/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 09:44:44 by hzakharc          #+#    #+#             */
/*   Updated: 2024/08/26 17:08:53 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built.h"

void	ft_printenv(t_env *head)
{
	t_env	*tmp;

	tmp = head;
	while (tmp)
	{
		printf("%s\n", tmp->data);
		tmp = tmp->next;
	}
}

int	ft_env(t_data data)
{
	if (data.args->next)
	{
		if (data.args->next->token == ARG)
		{
			if (access(data.args->next->data, F_OK) == 0)
				printf("env: '%s': Permission denied :(\n", data.args->next->data);
			else
				printf("env: '%s': No such a file or directory xD\n", data.args->next->data);
			return (-1);
		}
	}
	ft_printenv(data.env);
	return (0);
}

static void	restore_printed(t_exp *exp)
{
	t_exp	*tmp;

	tmp = exp;
	while (tmp)
	{
		tmp->printed = 0;
		tmp = tmp->next;
	}
}

static void	print_exp_util(t_exp *node)
{
	if (node->name)
		printf("declare -x %s=", node->name);
	if (node->value)
		printf("\"%s\"\n", node->value);
	else if (!node->value)
		printf("\n");
}

int	print_export(t_exp *exp)
{
	t_exp	*cur;
	t_exp	*start;
	t_exp	*min;

	start = exp;
	while (1)
	{
		min = NULL;
		cur = start;
		while (cur != NULL)
		{
			if (!cur->printed && ((min == NULL)
				|| (ft_strncmp(min->name, cur->name, ft_strlen(cur->name)) > 0)))
				min = cur;
			cur = cur->next;
		}
		if (min == NULL)
			break;
		print_exp_util(min);
		min->printed = 1;
	}
	restore_printed(exp);
	return (0);
}

void	env_free_node(char *data, t_env *env)
{
	t_env	*temp;
	t_env	*temp2;

	temp = env;
	while (temp)
	{
		if (ft_strnstr(temp->next->data, data, ft_strlen(temp->next->data)) != NULL)
		{
			temp2 = temp;
			temp = temp->next;
			temp2->next = temp->next;
			if (temp->data)
				free(data);
			free(temp);
		}
	}
}

void	exp_free_node(char *data, t_exp *exp)
{
	
}

int	ft_export(t_data data)
{
	t_args	*temp;
	t_env	*new_env;
	t_exp	*new_exp;
	char	**temp_str;

	temp = data.args;
	if (data.args->next)
	{
		if (data.args->next->token != ARG)
			return (print_export(data.exp));
	}
	else if (!data.args->next)
		return (print_export(data.exp));
	temp = temp->next;
	while (temp->token == ARG)
	{
		if (ft_strchr(temp->data, '='))
		{
			if (find_node(temp->data, data.env) != NULL)
			{
				env_free_node(temp->data, data.env);
				exp_free_node(temp->data, data.exp);
			}
			new_env = env_lstnew(ft_strdup(temp->data));
			env_lstadd_back(data.env, new_env);
			temp_str = ft_split(temp->data, '=');
			new_exp = exp_lstnew(temp_str[0], temp_str[1]);
			exp_lstadd_back(data.exp, new_exp);
			free(temp_str);
		}
	}
	return (-1);
}

