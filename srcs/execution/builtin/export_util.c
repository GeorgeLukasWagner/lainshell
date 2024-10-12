/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 10:18:42 by hzakharc          #+#    #+#             */
/*   Updated: 2024/10/12 18:02:57 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built.h"

void	restore_printed(t_env *env)
{
	t_env	*temp;

	temp = env;
	while (temp)
	{
		temp->printed = 0;
		temp = temp->next;
	}
}

void	print_exp_util(t_env *node)
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
		if (temp[1])
			printf("=\"%s\"\n", temp[1]);
		else
			printf("=\"\"\n");
		free_matrix(temp);
	}
}

void	print_export(t_env *env)
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
					|| (ft_strncmp(min->data, cur->data,
							ft_strlen(cur->data)) > 0)))
				min = cur;
			cur = cur->next;
		}
		if (min == NULL)
			break ;
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
