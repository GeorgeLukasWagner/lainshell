/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:20:06 by gwagner           #+#    #+#             */
/*   Updated: 2024/09/08 18:56:42 by hzakharc         ###   ########.fr       */
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

void	ft_free(char **argv)
{
	size_t	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

size_t	veclen(char **argv)
{
	size_t	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
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
		i++;
		(*args) = (*args)->next;
	}
	return (argv);
}

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
		if (tmp && tmp->next)
			tmp = tmp->next;
		ft_free(argv);
	}
	//ft_printcmd(cmd);
	return (cmd);
}
