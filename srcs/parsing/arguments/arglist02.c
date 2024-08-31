/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arglist02.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 20:21:32 by gwagner           #+#    #+#             */
/*   Updated: 2024/08/24 10:12:40 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"

void	ft_printlst(t_args *head)
{
	t_args	*tmp;

	tmp = head;
	while (tmp)
	{
		printf("%s %d\n", tmp->data, tmp->token);
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
