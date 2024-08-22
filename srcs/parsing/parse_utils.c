/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:32:34 by gwagner           #+#    #+#             */
/*   Updated: 2024/08/22 14:42:09 by gwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"

int	is_space(char c)
{
	if (c <= 32)
		return (1);
	else
		return (0);
}

int	wordlen(char *line)
{
	int	len;

	len = 0;
	while (!is_space(*line))
	{
		len++;
		line++;
	}
	return (len);
}

t_token	check_quote(char c)
{
	if (c == '"')
		return (DOUBLE_QUOTE);
	else if (c == '\'')
		return (QUOTE);
}

int	eat_space(char *line, int i)
{
	while (is_space(line[i]) && line[i])
		i++;
	return (i);
}
