/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:12:18 by gwagner           #+#    #+#             */
/*   Updated: 2024/10/07 12:17:00 by gwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"

void	free_cmd(t_cmd *cmd)
{
	t_cmd	*tmp;

	while (cmd)
	{
		tmp = cmd;
		cmd = cmd->next;
		ft_free(tmp->argv);
		free(tmp);
	}
}

void	ft_printcmd(t_cmd *cmd)
{
	size_t	i;

	printf("--------------------------------\n");
	while (cmd)
	{
		i = 0;
		while (cmd->argv[i])
		{
			printf("%s ", cmd->argv[i]);
			i++;
		}
		printf("\n--------------------------------\n");
		cmd = cmd->next;
	}
}

t_cmd	*ft_cmdlast(t_cmd *head)
{
	t_cmd	*tmp;

	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

void	ft_cmdadd_back(t_cmd **list, t_cmd *new)
{
	t_cmd	*n;

	if (*list)
	{
		n = ft_cmdlast(*list);
		n->next = new;
		new->next = NULL;
	}
	else
	{
		*list = new;
		(*list)->next = NULL;
	}
}

char	**vecdup(char **argv, size_t len)
{
	char	**new;
	size_t	i;

	i = 0;
	new = malloc(sizeof(char *) * len);
	if (!new)
		return (NULL);
	while (argv[i])
	{
		new[i] = ft_strdup(argv[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}
