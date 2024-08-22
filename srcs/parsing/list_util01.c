/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 19:55:22 by gwagner           #+#    #+#             */
/*   Updated: 2024/08/21 14:18:38 by gwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"

t_args	*ft_lstnew(char *data, t_token token)
{
	t_args	*new;

	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	new->data = data;
	new->token = token;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_front(t_args **list, t_args *new)
{
	new->next = *list;
	*list = new;
}

t_args	*ft_lstlast(t_args *head)
{
	t_args	*tmp;

	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

void	ft_lstadd_back(t_args **list, t_args *new)
{
	t_args	*n;

	if (*list)
	{
		n = ft_lstlast(*list);
		n->next = new;
		new->next = NULL;
	}
	else
	{
		*list = new;
		(*list)->next = NULL;
	}
}

int	ft_lstsize(t_args *head)
{
	size_t	i;
	t_args	*tmp;

	tmp = head;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
