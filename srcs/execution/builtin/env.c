/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 09:44:44 by hzakharc          #+#    #+#             */
/*   Updated: 2024/08/30 22:23:30 by hzakharc         ###   ########.fr       */
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
