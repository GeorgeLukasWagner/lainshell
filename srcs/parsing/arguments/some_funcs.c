/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:17:35 by gwagner           #+#    #+#             */
/*   Updated: 2024/10/07 12:19:12 by gwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"

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

t_alt	*altnew(char *data, t_token token, size_t i)
{
	t_alt	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->data = data;
	new->token = token;
	new->exec = TRUE;
	new->index = i;
	new->next = NULL;
	return (new);
}

t_alt	*ft_altlast(t_alt *head)
{
	t_alt	*tmp;

	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

void	ft_altadd_back(t_alt **list, t_alt *new)
{
	t_alt	*n;

	if (*list)
	{
		n = ft_altlast(*list);
		n->next = new;
		new->next = NULL;
	}
	else
	{
		*list = new;
		(*list)->next = NULL;
	}
}

void	print_redir(t_alt *redir)
{
	t_alt	*tmp;

	tmp = redir;
	while (tmp)
	{
		printf("redir: %s %d INDEX IS: %d\n",
			tmp->data, tmp->token, tmp->index);
		tmp = tmp->next;
	}
}
