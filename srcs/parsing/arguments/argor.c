/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 09:48:18 by gwagner           #+#    #+#             */
/*   Updated: 2024/09/16 19:52:40 by gwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"

int	remquotelen(char *data)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (data[i])
	{
		if (!(data[i] == '\'' || data[i] == '\"'))
			len++;
		i++;
	}
	return (len);
}

char	*destroyquotes(char *data)
{
	char	*new;
	int		len;
	int		len2;
	int		i;

	i = 0;
	len = remquotelen(data);
	new = malloc(len + 1);
	new[len] = '\0';
	len2 = 0;
	while (len2 < len)
	{
		if (!(data[i] == '\'' || data[i] == '\"') && data[i])
		{
			new[len2] = data[i];
			len2++;
		}
		i++;
	}
	return (new);
}

void trim_quotes(t_args **list)
{
	t_args	*tmp;
	char	*data;

	tmp = *list;
	while (tmp)
	{
		if (tmp->token == DOUBLE_QUOTE || tmp->token == QUOTE)
		{
			data = ft_substr(tmp->data, 1, ft_strlen(tmp->data) - 2);
			free(tmp->data);
			tmp->data = ft_strdup(data);
			free(data);
		}
		else if (tmp->token == CMD)
		{
			data = destroyquotes(tmp->data);
			free(tmp->data);
			tmp->data = ft_strdup(data);
			free(data);
		}
		tmp = tmp->next;
	}
}

int	is_token(char c)
{
	if (c == '|' || c == '<' || c == '>')
		return (1);
	return (0);
}

size_t	special_len(char *str)
{
	size_t	len;
	
	len = 0;
	while (str[len] && !is_space(str[len]) && !is_token(str[len]))
		len++;
	return (len);
}
