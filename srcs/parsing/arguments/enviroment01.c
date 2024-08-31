/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enviroment01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:25:20 by gwagner           #+#    #+#             */
/*   Updated: 2024/08/30 18:07:21 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"

t_env	*env_lstnew(char *data)
{
	t_env	*new;

	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	new->data = data;
	new->printed = 0;
	new->next = NULL;
	return (new);
}

t_env	*env_lstlast(t_env *head)
{
	t_env	*tmp;

	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

void	env_lstadd_back(t_env **list, t_env *new)
{
	t_env	*n;

	if (*list)
	{
		n = env_lstlast(*list);
		n->next = new;
		new->next = NULL;
	}
	else
	{
		*list = new;
		(*list)->next = NULL;
	}
}

int	env_lstsize(t_env *head)
{
	size_t	i;
	t_env	*tmp;

	tmp = head;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	free_env(t_env **list)
{
	t_env	*head;
	t_env	*tmp;

	head = *list;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp->data);
		free(tmp);
	}
}
