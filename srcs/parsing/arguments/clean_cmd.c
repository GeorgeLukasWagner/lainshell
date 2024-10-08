/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:04:47 by gwagner           #+#    #+#             */
/*   Updated: 2024/10/08 20:28:44 by gwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"
#include <stdio.h>

size_t	check_elem(char **argv)
{
	size_t	i;
	size_t	len;

	len = 0;
	i = 0;
	if (!argv || argv[0] == NULL)
		return (0);
	while (argv[i])
	{
		if (argv[i][0] != '\0')
			len++;
		i++;
	}
	return (len);
}

char	**clean_argv(char **argv)
{
	char	**cmd;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	cmd = ft_calloc(sizeof(char *), check_elem(argv) + 1);
	if (!cmd)
		return (NULL);
	while (argv[i])
	{
		if (argv[i][0] != '\0')
			cmd[j++] = ft_strdup(argv[i]);
		i++;
	}
	if (argv)
		ft_free(argv);
	return (cmd);
}

void	clean_cmd(t_cmd **cmd)
{
	t_cmd	*tmp;

	tmp = *cmd;
	while (tmp)
	{
		if (tmp->argv)
			tmp->argv = clean_argv(tmp->argv);
		tmp = tmp->next;
	}
}
