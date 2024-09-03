/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 09:44:44 by hzakharc          #+#    #+#             */
/*   Updated: 2024/09/03 12:26:57 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built.h"

void	ft_printenv(t_env *head)
{
	t_env	*tmp;

	tmp = head;
	while (tmp)
	{
		if (ft_strchr(tmp->data, '=') == NULL)
			tmp = tmp->next;
		else
		{
			printf("%s\n", tmp->data);
			tmp = tmp->next;
		}
	}
}

int	ft_env(t_data *data)
{
	t_cmd	*temp;

	temp = data->cmd;
	if (matrix_size(temp->argv) > 1)
	{
		printf("Too many arguments\n");
		return (-1);
	}
	ft_printenv(data->env);
	return (0);
}
