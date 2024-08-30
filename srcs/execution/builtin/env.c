/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 09:44:44 by hzakharc          #+#    #+#             */
/*   Updated: 2024/08/28 17:54:39 by hzakharc         ###   ########.fr       */
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
	if (!node)
	{
		printf("\n");
		return ;
	}
	if (node->name != NULL)
		printf("declare -x %s", node->name);
	if (node->value != NULL)
		printf("=\"%s\"\n", node->value);
	else if (node->value == NULL)
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

void	 env_free_node(char *data, t_env *env)
{
	t_env	*temp;
	t_env	*temp2;

	temp = env;
	while (temp && temp->next)
	{
		if (ft_strnstr(temp->next->data, data, ft_strlen(temp->next->data)) != NULL)
		{
			temp2 = temp;
			temp = temp->next;
			temp2->next = temp->next;
			if (temp->data)
				free(temp->data);
			free(temp);
		}
		else
			temp = temp->next;
	}
}

void	exp_free_node(char *data, t_exp *exp)
{
	t_exp	*temp;
	t_exp	*temp2;

	temp = exp;
	while (temp && temp->next)
	{
		if (ft_strnstr(data, temp->next->name, ft_strlen(temp->next->name)) != NULL)
		{
			temp2 = temp;
			temp = temp->next;
			temp2->next = temp->next;
			if (temp->name)
				free(temp->name);
			if (temp->value)
				free(temp->value);
			free(temp);
		}
		else
			temp = temp->next;
	}
}

t_exp	*find_node_exp(const char *to_find, t_exp *env)
{
	t_exp	*temp;

	temp = env;
	while (temp)
	{
		if (ft_strnstr(temp->name, to_find, ft_strlen(temp->name)) != NULL)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
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
    while (temp)
    {
        if (temp->token == ARG)
        {
            if (ft_strchr(temp->data, '=') != NULL)
            {
                if (find_node(temp->data, data.env) != NULL)
                {
                    env_free_node(temp->data, data.env);
                    exp_free_node(temp->data, data.exp);
                }
                new_env = env_lstnew(ft_strdup(temp->data));
                env_lstadd_back(&data.env, new_env);
                temp_str = ft_split(temp->data, '=');
                new_exp = exp_lstnew(temp_str[0], temp_str[1]);
                exp_lstadd_back(&data.exp, new_exp);
                free(temp_str);
            }
            else
            {
                if (find_node_exp(temp->data, data.exp) != NULL)
                    break ;
                else
                {
                    new_exp = exp_lstnew(temp->data, NULL);
                    exp_lstadd_back(&data.exp, new_exp);
                }
            }
        }
        temp = temp->next;
    }
    if (!temp || temp->token != ARG)
        return (0);
    return (-1);
}
