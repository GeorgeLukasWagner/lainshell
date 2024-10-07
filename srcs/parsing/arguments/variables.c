/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:51:58 by gwagner           #+#    #+#             */
/*   Updated: 2024/10/06 18:49:54 by gwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"

size_t	findstart(char *data)
{
	size_t	i;

	i = 0;
	while (data[i] && data[i] != '=')
		i++;
	return (i + 1);
}

void	makenewarg(t_args **list, size_t i, t_env *env)
{
	size_t	len;
	size_t	start;
	char	*new[3];

	len = varlen((*list)->data + i);
	while (env)
	{
		if (!ft_strncmp((*list)->data + i, env->data, len))
			break ;
		env = env->next;
	}
	start = findstart(env->data);
	new[0] = ft_substr((*list)->data, 0, i - 1);
	new[1] = ft_substr(env->data, start, ft_strlen(env->data + start));
	new[2] = ft_substr((*list)->data + i + len, 0,
			ft_strlen((*list)->data + i + len));
	free((*list)->data);
	(*list)->data = ft_strjoin(new[0], new[1]);
	free(new[0]);
	free(new[1]);
	new[0] = ft_strjoin((*list)->data, new[2]);
	free((*list)->data);
	(*list)->data = new[0];
	free(new[2]);
}

void	remove_var(t_args **list, size_t i)
{
	char	*new;
	char	*tmp;
	size_t	len;

	len = varlen((*list)->data + i);
	new = ft_substr((*list)->data, 0, i);
	tmp = ft_substr((*list)->data + i + len, 0,
			ft_strlen((*list)->data + i + len));
	free((*list)->data);
	if (new[0] == '\0' && tmp[0] == '\0')
		(*list)->data = ft_strdup("");
	else
		(*list)->data = ft_strjoin(new, tmp);
	free(new);
	free(tmp);
}

void	check_var(t_args **list, t_env *env)
{
	size_t	i;

	i = 0;
	while ((*list)->data[i])
	{
		if ((*list)->data[i] == '$' && (*list)->data[i + 1] != '?'
			&& ((*list)->data[i + 1] != '\0'))
		{
			if (check_env((*list)->data + i + 1, env))
				makenewarg(list, i + 1, env);
			else
				remove_var(list, i);
			if ((*list)->data[i] == '\0')
				break ;
		}
		i++;
	}
}

void	put_vars(t_args **list, t_env *env)
{
	t_args	*tmp;

	tmp = *list;
	while (tmp)
	{
		if (tmp->token < 3)
			check_var(&tmp, env);
		tmp = tmp->next;
	}
}
