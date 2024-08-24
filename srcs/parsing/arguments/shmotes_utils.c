/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shmotes_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 11:42:12 by gwagner           #+#    #+#             */
/*   Updated: 2024/08/24 11:47:35 by gwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"

t_quotes	*newshmote(char shmote)
{
	t_quotes	*new;

	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	new->quote = shmote;
	new->next = NULL;
	return (new);
}

void	shmotefront(t_quotes **list, t_quotes *new)
{
	new->next = *list;
	*list = new;
}

void	freeshmote(t_quotes **list)
{
	t_quotes	*head;
	t_quotes	*tmp;

	head = *list;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

void	shmotefrontremove(t_quotes **list)
{
	t_quotes	*tmp;

	tmp = *list;
	*list = (*list)->next;
	free(tmp);
}
