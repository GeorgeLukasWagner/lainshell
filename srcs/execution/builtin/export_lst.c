/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:39:41 by hzakharc          #+#    #+#             */
/*   Updated: 2024/08/28 17:50:44 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built.h"

t_exp	*exp_lstnew(char *name, char *value)
{
	t_exp	*new;

	new = malloc(sizeof(t_exp));
	if (!new)
		return (NULL);
	new->name = name;
	if (value == NULL)
		new->value = ft_strdup("");
	else
		new->value = value;
	new->printed = 0;
	new->next = NULL;
	return (new);
}

t_exp	*exp_lstlast(t_exp *head)
{
	t_exp	*tmp;

	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

void	exp_lstadd_back(t_exp **list, t_exp *new)
{
	t_exp	*n;

	if (*list)
	{
		n = exp_lstlast(*list);
		n->next = new;
		new->next = NULL;
	}
	else
	{
		*list = new;
		(*list)->next = NULL;
	}
}

int	exp_lstsize(t_exp *head)
{
	size_t	i;
	t_exp	*tmp;

	tmp = head;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	free_exp(t_exp **list)
{
	t_exp	*head;
	t_exp	*tmp;

	head = *list;
	while (head)
	{
		tmp = head;
		head = head->next;
		if (tmp->name)
			free(tmp->name);
		if (tmp->value)
			free(tmp->value);
		free(tmp);
	}
}
