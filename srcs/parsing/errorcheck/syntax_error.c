/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:41:50 by gwagner           #+#    #+#             */
/*   Updated: 2024/08/31 09:42:32 by gwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

int	search_quote(char *line)
{
	int	i;
	int	inquote;

	i = 0;
	inquote = 0;
	while (line[i])
	{
		if ((line[i] == '\'' || line[i] == '\"') && !inquote)
			inquote = line[i];
		else if (line[i] == inquote)
			inquote = 0;
		i++;
	}
	if (inquote)
		return (1);
	return (0);
}

int unclosedquotecheck(t_args *list)
{
	t_args	*tmp;

	tmp = list;
	while (tmp)
	{
		if (tmp->token <= ARG && search_quote(tmp->data))
		{
			printf("lainshell: syntax error near unclosed quote ' %s '\n", tmp->data);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int	syntax_error(t_args *list)
{
	t_args	*tmp;

	tmp = list;
	while (tmp->next)
	{
		if (tmp->token > 3 && tmp->next->token > 3)
		{
			printf("lainshell: syntax error near unexpected token '%s'\n",
				tmp->next->data);
			break ;
		}
		tmp = tmp->next;
	}
	if (tmp->next)
		return (1);
	else if (tmp->token > 3)
	{
		printf("lainshell: syntax error near unexpected token '\\n'\n");
		return (1);
	}
	else if (unclosedquotecheck(list))
		return (1);
	else
		return (0);
}
