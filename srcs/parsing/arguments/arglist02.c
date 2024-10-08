/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arglist02.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 20:21:32 by gwagner           #+#    #+#             */
/*   Updated: 2024/08/31 12:07:13 by gwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"

void	ft_printlst(t_args *head)
{
	t_args	*tmp;

	tmp = head;
	while (tmp)
	{
		printf("%s %d %d\n", tmp->data, tmp->token, tmp->append);
		tmp = tmp->next;
	}
}

void	free_list(t_args **list)
{
	t_args	*head;
	t_args	*tmp;

	head = *list;
	while (head)
	{
		tmp = head;
		head = head->next;
		if (tmp->data)
			free(tmp->data);
		free(tmp);
	}
}
