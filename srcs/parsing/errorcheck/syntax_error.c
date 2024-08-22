/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:41:50 by gwagner           #+#    #+#             */
/*   Updated: 2024/08/22 16:20:38 by gwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

int	syntax_error(t_args *list)
{
	t_args	*tmp;

	tmp = list;
	while (tmp->next)
	{
		if (tmp->token > 3 && tmp->next->token > 3)
		{
			printf("lainshell: syntax error near unexpected token '%s'\n",
				tmp->data);
			break ;
		}
		tmp = tmp->next;
	}
	if (tmp->next)
		return (1);
	else if (tmp->token == 7)
	{
		printf("lainshell: syntax error near unexpected token '\\n'\n");
		return (1);
	}
	else
		return (0);
}
