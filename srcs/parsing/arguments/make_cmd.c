/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:20:06 by gwagner           #+#    #+#             */
/*   Updated: 2024/10/09 13:14:24 by gwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"

size_t	cmd_len(t_args *args)
{
	size_t	len;

	len = 0;
	while (args && args->token != PIPE)
	{
		if (args->token < 4)
			len++;
		args = args->next;
	}
	return (len);
}

size_t	veclen(char **argv)
{
	size_t	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

t_cmd	*ft_cmdnew(char **argv, size_t len)
{
	t_cmd	*new;

	new = malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->argv = vecdup(argv, len);
	new->next = NULL;
	return (new);
}

char	**make_argv(t_args **args)
{
	char	**argv;
	char	*tmp;
	size_t	i;

	argv = ft_calloc(sizeof(char *), (cmd_len((*args)) + 1));
	i = 0;
	while ((*args) && (*args)->token != PIPE)
	{
		if ((*args)->token < 4)
			argv[i] = ft_strdup((*args)->data);
		while ((*args)->append && (*args)->next)
		{
			tmp = ft_strjoin(argv[i], (*args)->next->data);
			free(argv[i]);
			argv[i] = tmp;
			(*args) = (*args)->next;
		}
		if ((*args)->token < 4)
			i++;
		(*args) = (*args)->next;
	}
	return (argv);
}

t_cmd	*make_cmd(t_args *args)
{
	t_cmd	*cmd;
	t_args	*tmp;
	char	**argv;

	tmp = args;
	cmd = NULL;
	while (tmp)
	{
		argv = make_argv(&tmp);
		ft_cmdadd_back(&cmd, ft_cmdnew(argv, cmd_len(args) + 1));
		ft_free(argv);
		if (!tmp || !tmp->next)
			break ;
		tmp = tmp->next;
	}
	return (cmd);
}
