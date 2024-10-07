/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:20:43 by gwagner           #+#    #+#             */
/*   Updated: 2024/10/07 12:21:17 by gwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"

void	free_alt(t_alt **list)
{
	t_alt	*head;
	t_alt	*tmp;

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

int	redircheck(t_args *tmp, int i)
{
	if ((tmp->next->token == REDIR_OUT || tmp->next->token == REDIR_APPEND
			|| tmp->next->token == REDIR_IN || tmp->next->token == HERE_DOC)
		&& i == 1)
		return (1);
	else if ((tmp->token == REDIR_OUT || tmp->token == REDIR_APPEND
			|| tmp->token == REDIR_IN || tmp->token == HERE_DOC) && i == 2)
		return (1);
	else if (tmp->next->token != REDIR_OUT && tmp->next->token != REDIR_APPEND
		&& tmp->next->token != REDIR_IN && tmp->next->token != HERE_DOC
		&& tmp->next && i == 3)
		return (1);
	return (0);
}
