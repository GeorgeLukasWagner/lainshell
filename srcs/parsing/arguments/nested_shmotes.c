/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nested_shmotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 11:36:58 by gwagner           #+#    #+#             */
/*   Updated: 2024/08/24 12:28:44 by gwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"

int quotington(char *line, int i)
{
	t_quotes	*stack;
	t_quotes	*new;

	stack = NULL;
	stack = malloc(sizeof(t_quotes *));
	while (line[i])
	{
		if ((line[i] == '"' || line[i] == '\'') && stack->quote != line[i])
		{
			new = newshmote(line[i++]);
			shmotefront(&stack, new);
		}
		if (line[i] == stack->quote)
			shmotefrontremove(&stack);
		i++;
		if (stack->quote == 0)
			return (i);
	}
	if (stack)
	{
		freeshmote(&stack);
		return (-1);
	}
	return (i);
}
