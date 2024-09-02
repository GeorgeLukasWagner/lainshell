/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:32:34 by gwagner           #+#    #+#             */
/*   Updated: 2024/09/02 15:10:48 by gwagner          ###   ########.fr       */
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
	else
		return (1);
}

int	eat_space(char *line, int i)
{
	while (is_space(line[i]) && line[i])
		i++;
	return (i);
}

int quotewordlen(char *line)
{
	int	inquote;
	int	i;

	i = 0;
	inquote = 0;
	while (line[i])
	{
		if (is_space(line[i]) && !inquote)
			break ;
		if ((line[i] == '\'' || line[i] == '\"') && !inquote)
			inquote = line[i];
		else if (line[i] == inquote)
			inquote = 0;
		i++;
	}
	return (i);
}
