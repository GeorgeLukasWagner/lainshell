/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 18:56:31 by gwagner           #+#    #+#             */
/*   Updated: 2024/10/06 18:45:49 by gwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"

int	is_special(char c)
{
	if (c == '\\' || c == '/' || c == '!')
		return (1);
	return (0);
}

size_t	varlen(char *data)
{
	size_t	i;

	i = 0;
	while (data[i] && data[i] != '\"' && data[i] != ' '
		&& data[i] != '\'' && !is_special(data[i]))
		i++;
	return (i);
}

int	check_env(char *data, t_env *env)
{
	t_env	*tmp;
	size_t	len;

	len = varlen(data);
	tmp = env;
	if (!len)
		return (0);
	while (tmp)
	{
		if (ft_strncmp(data, tmp->data, len) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
